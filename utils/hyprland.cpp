#include <iostream>
#include "../includes/hyprland.h"

Hyprland::Hyprland() {
  std::cout << "[INFO] Hypr wm created.\n";
}

Hyprland::~Hyprland() { 
  std::cout << "[INFO] Hypr wm destroyed.\n";
}

std::string Hyprland::getImportToken() const {
  return "source";
}

int Hyprland::getImportTokenIndex() const {
  return 2;
}
