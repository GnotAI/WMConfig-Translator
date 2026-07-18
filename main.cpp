#include <iostream>
#include <memory>
#include <string_view>
//#include "includes/conf_utils.h"
#include "includes/hyprland.h"
#include "includes/niri.h"
#include "window_manager.h"

std::unique_ptr<WindowManager> getWM(std::string_view wmOpt);

int main (int argc, char *argv[]) {

  if (argc < 2) {
    std::cout << "\nA program to translate your DE config files to another DE config syntax.\n";
    std::cout << "\n";
    std::cout << "Usage: ./WMConfig-Translator [OPTION]\n";
    std::cout << "\n";
    std::cout << "Arguments: \n";
    std::cout << "  [OPTION]\n";
    std::cout << "    -H, --hypr : Hyprland \n";
    std::cout << "    -N, --niri : Niri \n";
    std::cout << "    -M, --mango : MangoWC \n";
    std::cout << "    -S, --sway : Swaync \n";
    return 1;
  }

  std::string_view windowManagerArg { argv[1] };
  std::unique_ptr<WindowManager> managerObject { getWM(windowManagerArg) };
  if (!managerObject) return 1;


  std::cout << "[INFO] File path created.\n";
  std::cout << "------------ Start parsing. -------------" << '\n';

  //generateFullFile(*managerObject);

  std::cout << "------------ Done parsing. -------------" << '\n';

  return 0;
}

std::unique_ptr<WindowManager> getWM(std::string_view wmOpt) {

  if (wmOpt == "-H" || wmOpt == "--hypr") return std::make_unique<Hyprland>();
  if (wmOpt == "-N" || wmOpt == "--niri") return std::make_unique<Niri>();

  std::cerr << "\nUnknown WM option: " << wmOpt << "\n";
  std::cout << "\n";
  std::cout << "Usage: ./WMConfig-Translator [OPTION]\n";
  std::cout << "\n";
  std::cout << "Arguments: \n";
  std::cout << "  [OPTION]\n";
  std::cout << "    -H, --hypr : Hyprland \n";
  std::cout << "    -N, --niri : Niri \n";
  std::cout << "    -M, --mango : MangoWC \n";
  std::cout << "    -S, --sway : Swaync \n";
  return nullptr;

}
