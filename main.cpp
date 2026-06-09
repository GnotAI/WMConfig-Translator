#include <iostream>
#include "includes/conf_utils.h"
#include "includes/hyprland.h"

int main (int argc, char *argv[]) {

  Hyprland hypr;
  std::cout << "[INFO] File path created.\n";

  std::cout << "------------ Start parsing. -------------" << '\n';

  generateFullFile(hypr);

  std::cout << "------------ Done parsing. -------------" << '\n';

  return 0;
}
