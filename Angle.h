#ifndef ANGLE_H
#define ANGLE_H
#include "Atom.h"

class Angle {
 public:
  Atom& atoms[3];
  Angle(Atom i, Atom j, Atom k) {
    atoms[0] = i;
    atoms[1] = j;
    atoms[2] = k;
  };
};

#endif  // ANGLE_H
