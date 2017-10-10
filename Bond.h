#ifndef BOND_H
#define BOND_H
#include "Atom.h"

class Bond {
 public:
  Atom atoms[2];

  Bond(Atom i, Atom j) {
    atoms[0] = i;
    atoms[1] = j;
  };

  double b0, kb;
};

#endif  // BOND_H
