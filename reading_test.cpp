#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include "Atom.h"

int main() {
  // vector where the atoms of the molecule will be stored
  std::vector<Atom> atoms;

  std::ifstream infile("lig.itp");
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
}
