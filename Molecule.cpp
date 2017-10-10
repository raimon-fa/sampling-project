#include "Molecule.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <tuple>
/**
 *  @brief Generate the vectors containing the atoms, bonds,.. of
 * the molecule.
 */
Molecule::Molecule(std::string molecule_file) {
  auto vectors = initialize(molecule_file);
  atoms = std::get<0>(vectors);
  bonds = std::get<1>(vectors);
  num_atoms = atoms.size();
  num_bonds = bonds.size();

  // angles = std::get<2>(vectors);
  // dihidrals = std::get<3>(vectors);
}

std::tuple<std::vector<Atom>, std::vector<Bond>> Molecule::initialize(
    std::string molecule_file) {
  std::ifstream infile(molecule_file);
  std::string line;
  // read atoms
  // vector where the atoms of the molecule will be stored
  std::vector<Atom> atoms;
  // go to line starting with word [ atoms ]
  while (getline(infile, line)) {
    if (line == "[ atoms ]") break;
  }
  // skipe two lines
  std::getline(infile, line);
  std::getline(infile, line);
  // read atoms
  int i = 0;
  while (std::getline(infile, line)) {
    if (line.empty()) break;

    std::istringstream iss(line);
    std::string semicolon;
    Atom new_atom;
    atoms.push_back(new_atom);

    iss >> atoms[i].index >> atoms[i].type >> atoms[i].resnr >>
        atoms[i].residue >> atoms[i].element >> atoms[i].cgnr >>
        atoms[i].charge >> semicolon;
    i++;
  }
  // read bonds
  std::vector<Bond> bonds;
  // go to line starting with word [ bonds ]
  while (getline(infile, line)) {
    if (line == "[ bonds ]") break;
  }
  // skipe one line
  std::getline(infile, line);
  // read bonds
  int atom_i, atom_j, funct;
  int l = 0;
  while (std::getline(infile, line)) {
    if (line.empty()) break;
    std::istringstream iss(line);

    iss >> atom_i >> atom_j >> funct;
    Bond new_bond(atoms[atom_i - 1], atoms[atom_j - 1]);
    bonds.push_back(new_bond);
    l++;
  }
  // read angles
  // std::vector<Angle> angles;
  // read dihedrals
  // std::vector<Dihedral> dihedrals;

  // return std::make_tuple(atoms, bonds, angles, dihedrals)
  return std::make_tuple(atoms, bonds);
}