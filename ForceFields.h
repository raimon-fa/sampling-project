#ifndef FORCE_FIELDS_H
#define FORCE_FIELDS_H

#include <string>
#include "Atom.h"
#include "Bond.h"
#include "Molecule.h"

class ForceFields {
 private:
  std::vector<double> initialize_bond_constants();
  std::vector<double> initialize_angle_constants();
  std::vector<double> initialize_dihedral_constants();
  std::vector<double> initialize_long_range_constants();

 public:
  // Constructor: reads FF files and generates arrays
  ForceFields(std::string, Molecule);
  string std::vector<double> bond_constants;
  std::vector<double> angle_constants;
  std::vector<double> dihedral_constants;
  std::vector<double> long_range_constants;

  // double energy(Configuration molecule_conf);
};

#endif  // FORCE_FIELDS_H
