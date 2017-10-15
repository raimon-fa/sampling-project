#ifndef BOND_H
#define BOND_H
#include "Atom.h"

class Bond {
 public:
  // Atom atoms[2];
  std::vector<Atom> atoms;

  Bond(Atom i, Atom j) {
    atoms = {i, j};
    // atoms[0] = i;
    // atoms[1] = j;
  };

  double ff_b0, ff_kb;
};

#endif  // BOND_H
