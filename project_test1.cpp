#include <iostream>
#include <string>
#include "Molecule.h"
int main() {
  std::string file_name = "./molecule_files/lig.itp";

  Molecule photoswitch1(file_name);

  std::cout << photoswitch1.num_atoms << "\n";
  std::cout << photoswitch1.num_bonds << "\n";
  std::cout << photoswitch1.num_angles << "\n";
  std::cout << photoswitch1.num_dihedrals << "\n";

  // Bond bond1 = photoswitch1.bonds[0];
  // std::cout << bond1.atom_i.charge << "\n";
}