#include "ForceFields.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include "GeneralFunctions.h"
ForceFields::ForceFields(std::string FFbonded_file, std::string FFunbonded_file,
                         Molecule &molecule) {
  molecule = molecule;

  FFbonded_file = FFbonded_file;
  FFunbonded_file = FFunbonded_file;

  bond_constants = initialize("bonds");
  angle_constants = initialize("angles");
  dihedral_constants = initialize("dihedrals");
  // pair_constants = initialize("pairs");
}

std::vector<std::vector<double>> ForceFields::initialize(std::string what) {
  std::string file_name = FFbonded_file;
  if (what == "pairs") {
    file_name = FFunbonded_file;
  }

  std::ifstream infile(file_name);
  std::string line;
  GeneralFunctions::check_if_file_exists(file_name);

  // go to line starting with word [ bondtypes ]
  std::string headline = what;
  headline.pop_back();
  headline = "[" + headline + "types ]";

  GeneralFunctions::jump_to(headline, infile);
  std::getline(infile, line);  // skipe one line

  // READ what ENERGY CONSTANTS
  // save line position that beggins data
  std::streampos oldpos = infile.tellg();

  int num_items;

  std::map<std::string, int> what_map = {
      {"bonds", 1}, {"angles", 2}, {"dihedrals", 3}, {"pairs", 4}};

  switch (what_map[what]) {
    // case what_map["bonds"]:
    case 1:
      num_items = molecule.num_bonds;
      break;
      // case what_map["angles"]:
    case 2:
      num_items = molecule.num_angles;
      break;
      // case what_map["dihedrals"]:
    case 3:
      num_items = molecule.num_dihedrals;
      break;
      // case what_map["pairs"]:
    case 4:
      break;
  }

  for (int i = 0; i < num_items; ++i) {
    int item_found = false;
    while (std::getline(infile, line)) {
      if (line.empty()) break;
      std::istringstream iss(line);

      std::vector<std::string> atom_types;
      Atom *atoms;
      switch (what_map[what]) {
        // case what_map["bonds"]:
        case 1:
          atoms = molecule.bonds[i].atoms;
          break;
          // case what_map["angles"]:
        case 2:
          atoms = molecule.angles[i].atoms;
          break;
          // case what_map["dihedrals"]:
        case 3:
          atoms = molecule.dihedrals[i].atoms;
          break;
          // case what_map["pairs"]:
        case 4:
          break;
      }
      std::transform(atoms.begin(), atoms.end(), std::back_inserter(atom_types),
                     [](const Atom &atom) -> std::string { return atom.type; });

      std::vector<std::string> temp_types;
      std::vector<std::vector<double>> item_constants;
      std::vector<double> temp_constants;
      std::string temp_type1, temp_type2, temp_type3, temp_type4;

      switch (what_map[what)]) {
            // case what_map["bonds"]:
          case 1:
            double b0, kb;  //
            iss >> temp_type1 >> temp_type2 >> func >> b0 >> kb;
            temp_types = {temp_type1, temp_type2};
            temp_constants = {b0, kb};
            break;
            // case what_map["angles"]:
          case 2:
            double theta, ktheta, ub0, kub;
            iss >> temp_type1 >> temp_type2 >> temp_type3 >> func >> theta >>
                ktheta >> ub0 >> kub;
            temp_types = {temp_type1, temp_type2, temp_types3};
            temp_constants = {theta, ktheta, ub0, kub};
            break;
            // case what_map["dihedrals"]:
          case 3:
            double phi0, kphi, mult;
            iss >> temp_type1 >> temp_type2 >> temp_type3 >> temp_type4 >>
                func >> phi0 >> kphi >> mult;
            temp_types = {temp_type1, temp_type2, temp_types3, temp_types4};
            temp_constants = {phi0, kphi, mult};
            break;
            // case what_map["pairs"]:
          case 4:
            break;
        }
      // sort types to beggin permutations
      temp_types = sort(temp_types.begin(), temp_types.end());
      do {
        if (atom_types == temp_types) {
          item_constants.push_back(temp_constants);
          item_found = true;
          break
        }
      } while (std::next_permutation(temp_types.begin(), temp_types.end()));
    };

    if (item_found == false) {
      std::cout << "error! Item ";
      for (int i = 0; i < atom_types.size(); ++i) {
        std::cout << atom_types[i] << "-"
      }
      std::cout << " not found"
                << "\n";
    }

    infile.seekg(oldpos);
  }

  return item_constants;
}
