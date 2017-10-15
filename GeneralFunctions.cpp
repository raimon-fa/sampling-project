#include "GeneralFunctions.h"
#include <sys/stat.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
/**
 * Jumps to line of file that consists of string "word".
 */
void GeneralFunctions::jump_to(std::string word, std::istream &is) {
  std::string line;
  while (getline(is, line)) {
    if (line == word) break;
  }
};

void GeneralFunctions::check_if_file_exists(std::string &file_name) {
  std::cout << "Reading file: " << file_name << "\n";
  struct stat buffer;
  if (stat(file_name.c_str(), &buffer) != 0)  // file does exists
  {
    std::cout << "Attempted to read"
              << "\n";
    std::cout << file_name << "\n";
    std::cout << "Sorry, no such file ..."
              << "\n";
    exit(EXIT_FAILURE);
  }
};

// namespace GeneralFunctions