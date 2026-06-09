#include <iostream>
#include "../includes/niri.h"

Niri::Niri() {
  std::cout << "[INFO] Niri wm created.\n";
}

Niri::~Niri() { 
  std::cout << "[INFO] Niri wm destroyed.\n";
}

std::string Niri::getFileName() const {
  return "config.kdl";
}

std::string Niri::getConfigDir() const {
  return "niri/config.kdl";
}

std::string Niri::getImportToken() const {
  return "include";
}

int Niri::getImportTokenIndex() const {
  return 1;
}
