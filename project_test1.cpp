#include <iostream>
#include <string>
#include "ForceFields.h"
#include "Molecule.h"
int main() {
  std::string file_name = "./molecule_files/dithiacyclophane/lig.itp";

  Molecule dithiacyclophane1(file_name);
  std::string folder_name =
      "/home/fabregat/sampling_project/force_field_files/";
  ForceFields ff("ffbonded.itp", folder_name + "ffnonbonded.itp",
                 dithiacyclophane1);

  std::cout << dithiacyclophane1.num_atoms << "\n";
  std::cout << dithiacyclophane1.num_bonds << "\n";
  std::cout << dithiacyclophane1.num_angles << "\n";
  std::cout << dithiacyclophane1.num_dihedrals << "\n";

  std::cout << ff.bond_constants.size() << "\n";
  std::cout << ff.angle_constants.size() << "\n";
  std::cout << ff.dihedral_constants.size() << "\n";
}