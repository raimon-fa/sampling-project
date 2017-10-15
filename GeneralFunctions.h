#include <iostream>
#include <string>
namespace GeneralFunctions {
/**
 * Jumps to line of file that consists of string "word".
 */
void jump_to(std::string word, std::istream &is);

/**
 * Checks if file exists, and if it does not the program finishes.
 */
void check_if_file_exists(std::string &file_name);

}  // namespace GeneralFunctions
