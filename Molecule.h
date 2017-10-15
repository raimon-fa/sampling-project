#ifndef MOLECULE_H
#define MOLECULE_H
#include <iostream>
#include <string>
#include "Angle.h"
#include "Atom.h"
#include "Bond.h"
#include "Dihedral.h"
// #include "ForceFields.h"

class Molecule {
 private:
  // std::tuple<std::vector<Atom>, std::vector<Bond>, std::vector<Angle>,
  //            std::vector<Dihedral>>
  //     initialize(std::string);
  std::vector<Atom> initialize_atoms(std::string);
  std::vector<Bond> initialize_bonds(std::string);
  std::vector<Angle> initialize_angles(std::string);
  std::vector<Dihedral> initialize_dihedrals(std::string);

 public:
  Molecule();
  Molecule(std::string);
  std::vector<Atom> atoms;
  std::vector<Bond> bonds;
  std::vector<Angle> angles;
  std::vector<Dihedral> dihedrals;

  int num_atoms, num_bonds, num_angles, num_dihedrals;
  // class Configuration {
  //  public:
  //   Configuration();
  //   double energy(ForceFields forcefields);
  // };
};

#endif  // MOLECULE_H
