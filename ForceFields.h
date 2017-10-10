#ifndef FORCE_FIELDS_H
#define FORCE_FIELDS_H

#include <string>
#include "Atom.h"
#include "Bond.h"
#include "Molecule.h"

class ForceFields {
 private:
  /* data */
 public:
  // Constructor: reads FF files and generates arrays
  ForceFields(std::string, Molecule);

  class FF_bond::Bond {
   public:
    FF_bond();
    ~FF_bond();
  };

  std::vector<double> bond_energies;
  std::vector<double> angle_energies;
  std::vector<double> dihedral_energies;
  std::vector<double> long_range_energies;

  // double energy(Configuration molecule_conf);
};

#endif  // FORCE_FIELDS_H
