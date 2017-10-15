#ifndef ANGLE_H
#define ANGLE_H
#include "Atom.h"

class Angle {
 public:
  std::vector<Atom> atoms;
  Angle(Atom i, Atom j, Atom k) {
    atoms = {i, j, k};
    // atoms[0] = i;
    // atoms[1] = j;
    // atoms[2] = k;
  };
};

#endif  // ANGLE_H
