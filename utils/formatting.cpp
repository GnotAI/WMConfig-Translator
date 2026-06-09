#include <cstdlib>
#include <string>
#include "../includes/formatting.h"

std::string trim(const std::string& s) {
  const char* whitespace = " \t\n\r\f\v";
  size_t begin = s.find_first_not_of(whitespace);
  if (begin == std::string::npos) {
    return std::string{};
  }
  size_t end = s.find_last_not_of(whitespace);
  return std::string{s.substr(begin, end - begin + 1)};
}

void dirHardFormat(std::string& s) {
  const std::string homeDir{ getenv("HOME") };
  s.replace(0, 1, homeDir);
}
