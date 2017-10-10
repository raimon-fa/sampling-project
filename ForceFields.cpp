#include "ForceFields.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

ForceFields::ForceFields(std::string bounded_FF_file,
                         std::string unbounded_FF_file, Molecule molecule) {
  bond_constants = initialize_bond_constants(bounded_FF_file, molecule);
  // angle_constants = initialize_angle_constants();
  // dihedral_constants = initialize_dihedral_constants();
  // long_range_constants = initialize_long_range_constants();
}

std::vector<std::vector<double>> ForceFields::initialize_bond_constants(
    std::string bounded_FF_file, Molecule molecule) {
  std::ifstream infile(bounded_FF_file);
  std::string line;
  // go to line starting with word [ bondtypes ]
  while (getline(infile, line)) {
    if (line == "[ bondtypes ]") break;
  }
  // skipe one lines
  std::getline(infile, line);
  // read bond energy constants
  streampos oldpos = infile.tellg();  // stores the position
  for (int i = 0; i < molecule.num_bonds; ++i) {
    if (line.empty()) break;

    atom_type1 = molecule.bonds.atoms[0].type;
    atom_type2 = molecule.bonds.atoms[1].type;

    std::istringstream iss(line);
    std::string atom_type1, atom_type2;

    int func;
    double b0, kb;

    iss >> atom_type1p, atom_type2p, fun, b0, kb;

    if (((atom_type1 == atom_type1p) && (atom_type2 == atom_type2p)) ||
        ((atom_type1 == atom_type2p) && (atom_type2 == atom_type1p))) {
      bond_constants[i][0] = b0;
      bond_constants[i][0] = kb;
      bond_constants = infile.seekg(oldpos);
    }
  }

  return bond_constants;
}