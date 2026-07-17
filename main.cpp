#include <iostream>
#include <typeinfo>
#include "includes/conf_utils.h"
#include "includes/hyprland.h"
#include "includes/niri.h"
#include "window_manager.h"

int main (int argc, char *argv[]) {

  Hyprland hypr;
  std::cout << "[INFO] File path created.\n";

  std::cout << "------------ Start parsing. -------------" << '\n';

  std::cout << typeid(windowManagerArg).name() << '\n';
  generateFullFile(wm);

  std::cout << "------------ Done parsing. -------------" << '\n';

  return 0;
}
