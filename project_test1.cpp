#include <iostream>
#include <string>
#include "Molecule.h"
int main() {
  std::string file_name = "lig.itp";

  Molecule photoswitch1(file_name);

  Bond bond1 = photoswitch1.bonds[0];
  std::cout << bond1.atom_i.charge << "\n";
}