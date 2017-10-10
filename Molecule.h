#ifndef MOLECULE_H
#define MOLECULE_H
#include <iostream>
#include <string>
// #include "Angle.h"
#include "Atom.h"
#include "Bond.h"
// #include "Dihedral.h"
// #include "ForceFields.h"

class Molecule {
 private:
  // std::tuple<std::vector<Atom>, std::vector<Bond>, std::vector<Angle>,
  //            std::vector<Dihedral>>
  //     initialize(std::string);
  std::tuple<std::vector<Atom>, std::vector<Bond>> initialize(std::string);

 public:
  Molecule(std::string);
  std::vector<Atom> atoms;
  std::vector<Bond> bonds;
  // std::vector<Angle> angles;
  // std::vector<Dihedral> dihidrals;
  int num_atoms, num_bonds;
  // class Configuration {
  //  public:
  //   Configuration();
  //   double energy(ForceFields forcefields);
  // };
};

#endif  // MOLECULE_H
