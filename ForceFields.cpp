#include "ForceFields.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

ForceFields::ForceFields(std::string FF_folder, Molecule molecule) {
  bond_constants = initialize_bond_constants(FF_folder, molecule);
  // angle_constants = initialize_angle_constants();
  // dihedral_constants = initialize_dihedral_constants();
  // long_range_constants = initialize_long_range_constants();
}

vector<double> ForceFields::initialize_bond_constants(std::string FF_folder,
                                                      Molecule molecule) {
  std::ifstream infile(molecule_file);
  std::string line;
  // go to line starting with word [ atoms ]
  while (getline(infile, line)) {
    if (line == "[ atoms ]") break;
  }
  // skipe two lines
  std::getline(infile, line);
  std::getline(infile, line);
  // read atoms
  int i = 0;
  while (std::getline(infile, line)) {
    if (line.empty()) break;

    std::istringstream iss(line);
    std::string semicolon;
    Atom new_atom;
    atoms.push_back(new_atom);

    iss >> atoms[i].index >> atoms[i].type >> atoms[i].resnr >>
        atoms[i].residue >> atoms[i].element >> atoms[i].cgnr >>
        atoms[i].charge >> semicolon;
    i++;
  }
  return atoms;
}