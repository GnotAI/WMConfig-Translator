#include <iostream>
#include <memory>
#include <string_view>
#include "formatting.h"
#include "includes/conf_utils.h"
#include "includes/hyprland.h"
#include "includes/niri.h"
#include "window_manager.h"

std::unique_ptr<WindowManager> getWM(std::string_view wmOpt);

int main (int argc, char *argv[]) {

  if (argc < 2) {
    showHelp();
    return 1;
  }

  std::string_view windowManagerArg { argv[1] };
  std::unique_ptr<WindowManager> managerObject { getWM(windowManagerArg) };
  if (!managerObject) return 1;


  std::cout << "[INFO] File path created.\n";
  std::cout << "------------ Start parsing. -------------" << '\n';

  generateFullFile(*managerObject);

  std::cout << "------------ Done parsing. -------------" << '\n';

  return 0;
}

std::unique_ptr<WindowManager> getWM(std::string_view wmOpt) {

  if (wmOpt == "-H" || wmOpt == "--hypr") return std::make_unique<Hyprland>();
  if (wmOpt == "-N" || wmOpt == "--niri") return std::make_unique<Niri>();

  std::cerr << "\nUnknown WM option: " << wmOpt << "\n\n";
  showHelp();
  return nullptr;

}
