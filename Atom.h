#ifndef ATOM_H
#define ATOM_H
#include <string>
#include <vector>
class Atom {
 public:
  std::string type, residue, element;
  std::vector<double> position;

  int index, resnr, cgnr;
  double charge, mass;
  double sigma, epsilon;
};
#endif  // ATOM_H
