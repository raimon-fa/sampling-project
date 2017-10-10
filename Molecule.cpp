#include "Molecule.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
/**
 *  @brief Generate the vectors containing the atoms, bonds,.. of
 * the molecule.
 */
Molecule::Molecule(std::string molecule_file) {
  atoms = initialize_atoms(molecule_file);
  bonds = initialize_bonds(molecule_file);
  angles = initialize_angles(molecule_file);
  dihedrals = initialize_dihedrals(molecule_file);

  num_atoms = atoms.size();
  num_bonds = bonds.size();
  num_angles = angles.size();
  num_dihedrals = dihedrals.size();
}

std::vector<Atom> Molecule::initialize_atoms(std::string molecule_file) {
  std::ifstream infile(molecule_file);
  std::string line;
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
  return atoms;
}
std::vector<Bond> Molecule::initialize_bonds(std::string molecule_file) {
  std::ifstream infile(molecule_file);
  std::string line;
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
  return bonds;
}
std::vector<Angle> Molecule::initialize_angles(std::string molecule_file) {
  std::ifstream infile(molecule_file);
  std::string line;
  // go to line starting with word [ angles ]
  while (getline(infile, line)) {
    if (line == "[ angles ]") break;
  }
  // skipe one line
  std::getline(infile, line);
  // read angles
  int i, j, k, funct;
  int l = 0;
  while (std::getline(infile, line)) {
    if (line.empty()) break;
    std::istringstream iss(line);
    iss >> i >> j >> k >> funct;
    Angle new_angle(atoms[i - 1], atoms[j - 1], atoms[k - 1]);
    angles.push_back(new_angle);
    l++;
  }
  return angles;
}
std::vector<Dihedral> Molecule::initialize_dihedrals(
    std::string molecule_file) {
  std::ifstream infile(molecule_file);
  std::string line;
  // go to line starting with word [ angles ]
  while (getline(infile, line)) {
    if (line == "[ dihedrals ]") break;
  }
  // skipe one line
  std::getline(infile, line);
  // read angles
  int i, j, k, l, funct;
  int m = 0;
  while (std::getline(infile, line)) {
    if (line.empty()) break;
    std::istringstream iss(line);
    iss >> i >> j >> k >> l >> funct;
    Dihedral new_dih(atoms[i - 1], atoms[j - 1], atoms[k - 1], atoms[l - 1]);
    dihedrals.push_back(new_dih);
    m++;
  }
  return dihedrals;
}
