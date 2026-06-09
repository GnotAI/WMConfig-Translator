#include <iostream>
#include "../includes/hyprland.h"

Hyprland::Hyprland() {
  std::cout << "[INFO] Hypr wm created.\n";
}

Hyprland::~Hyprland() { 
  std::cout << "[INFO] Hypr wm destroyed.\n";
}

std::string Hyprland::getImportWord() const {
  return "source";
}

std::string Hyprland::getFileName() const {
  return "hyprland.conf";
}

std::string Hyprland::getConfigDir() const {
  return "hypr/hyprland.conf";
}
