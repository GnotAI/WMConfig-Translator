#include <cstdlib>
#include <format>
#include <iostream>
#include <string>
#include "includes/conf_utils.h"

int main () {
				WM wm = WM::Hypr;
				std::string destFileName;
				std::string confDir;

				switch (wm) {
								case WM::Hypr: 
												destFileName = "hyprland.conf";
												confDir = ".config/hypr/hyprland.conf";
												break;
								case WM::Niri: 
												destFileName = "config.kdl";
												confDir = ".config/niri/config.kdl";
												break;
								default:
												std::cout << "Needs a config type";
												break;
				}

				std::string homeDir{ getenv("HOME") };
				std::string srcFilePath{ std::format("{0}/{1}", homeDir, confDir) };
				std::string destFilePath{ std::format("{0}/Documents/{1}", homeDir, destFileName) };

				std::cout << "------------ Start parsing. -------------" << '\n';
				generateFullFile(srcFilePath, destFilePath, wm);
				std::cout << "------------ Done parsing. -------------" << '\n';

				return 0;
}
