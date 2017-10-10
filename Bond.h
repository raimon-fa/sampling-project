#ifndef BOND_H
#define BOND_H
#include "Atom.h"

class Bond {
 public:
  Bond(Atom i, Atom j) {
    atom_i = i;
    atom_j = j;
  };

  Atom atom_i, atom_j;
  double b0, kb;
};

#endif  // BOND_H
