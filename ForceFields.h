#ifndef FORCE_FIELDS_H
#define FORCE_FIELDS_H
#include <array>
#include <string>
#include "Atom.h"
#include "Bond.h"
#include "Molecule.h"
class ForceFields {
 public:
  // Constructor: reads FF files and generates arrays
 public:
  ForceFields(std::string FFbonded_file, std::string FFunbonded_file,
              Molecule &);

  std::string FFbonded_file;
  std::string FFunbonded_file;

  Molecule molecule;

  std::vector<std::vector<double>> bond_constants;
  std::vector<std::vector<double>> angle_constants;
  std::vector<std::vector<double>> dihedral_constants;
  std::vector<std::vector<double>> long_range_constants;

  // double energy(Configuration molecule_conf);
 private:
  std::vector<std::vector<double>> initialize(std::string what);
  // std::vector<double> initialize_angle_constants();
  // std::vector<double> initialize_dihedral_constants();
  // std::vector<double> initialize_long_range_constants();
};

#endif  // FORCE_FIELDS_H
