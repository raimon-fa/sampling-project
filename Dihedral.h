#ifndef DIHEDRAL_H
#define DIHEDRAL_H
#include "Atom.h"

class Dihedral {
 public:
  std::vector<Atom> atoms;
  Dihedral(Atom i, Atom j, Atom k, Atom l) {
    atoms = {i, j, k, l};
    //
  };
};

#endif  // DIHEDRAL_H
