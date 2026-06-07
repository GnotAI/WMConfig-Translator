#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "../includes/conf_utils.h"
#include "../includes/formatting.h"

std::string getKeyword(const WM& wm) {
				switch (wm) {
								case WM::Hypr:
								case WM::Mangowc:
												return "source";
												break;
								case WM::Niri:
								case WM::Sway: 
												return "include";
												break;
								default:
												return "WM not supported";
												break;
				}
}

void generateFullFile(std::string& srcFileLoc, std::string& destFileLoc, WM wm) {
				std::vector<std::string> tokens;
				std::ifstream srcFile(srcFileLoc);
				std::ofstream destFile(destFileLoc);
				std::string line;
				std::string token;

				if (srcFile.is_open() && destFile.is_open()) {
								while (std::getline(srcFile, line)) {

												tokens.clear();
												std::stringstream ss(trim(line));
												while (ss >> token) {
																tokens.emplace_back(token);
												} 

												if (tokens.empty()) {
																continue;
												}
												else if (tokens[0] != getKeyword(wm)) {
																destFile << line << '\n';
												} 
												else {
																std::string newFileLoc{tokens[2]};
																dirHardFormat(newFileLoc);
																std::ifstream newSrcFile(newFileLoc);
																destFile << newSrcFile.rdbuf() << "\n\n";
																newSrcFile.close();
												}
								}
				} 
				else {
								std::cout << "Failed to create a file." << "\n";
				}
}
