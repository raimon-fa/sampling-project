#ifndef DIHEDRAL_H
#define DIHEDRAL_H
#include "Atom.h"

class Dihedral {
 public:
  Atom atoms[4];
  Dihedral(Atom i, Atom j, Atom k, Atom l) {
    atoms[0] = i;
    atoms[1] = j;
    atoms[2] = k;
    atoms[3] = l;
  };
};

#endif  // DIHEDRAL_H
