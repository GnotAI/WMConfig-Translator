#include <format>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <string_view>
#include <vector>
#include <filesystem>
#include "../includes/conf_utils.h"
#include "../includes/formatting.h"
#include "../includes/window_manager.h"
#include "../includes/hyprland.h"
#include "../includes/niri.h"

namespace fs = std::filesystem;

std::vector<std::string> generateSourceAndDestPaths(const std::string_view homePath, WindowManager& wm) {

  std::string destinationFilePath;
  std::string sourceFilePath;

  if (typeid(wm) == typeid(Hyprland)) {

    fs::path destPath { std::format("{0}/Documents/wmconfig/hypr", homePath) };
    fs::create_directories(destPath);

    sourceFilePath = std::format("{0}/.config/hypr/hyprland.conf", homePath);
    destinationFilePath =  std::format("{0}/Documents/wmconfig/hypr/hyprland.conf", homePath);
  }
  if (typeid(wm) == typeid(Niri)) {

    fs::path destPath { std::format("{0}/Documents/wmconfig/niri", homePath) };
    fs::create_directories(destPath);

    sourceFilePath = std::format("{0}/.config/niri/config.kdl", homePath);
    destinationFilePath =  std::format("{0}/Documents/wmconfig/niri/config.kdl", homePath); 
  }
  return { sourceFilePath, destinationFilePath };
}

void generateFullFile(WindowManager& wm) {
  std::string line;
  std::string token;
  std::vector<std::string> tokens;

  const std::string_view homeDir { getenv("HOME") };
  std::vector<std::string> filePaths = { generateSourceAndDestPaths(homeDir, wm) };

  std::ifstream srcFile( filePaths[0] );
  std::ofstream destFile( filePaths[1] );

  if (!srcFile.is_open()) {
    std::cout << "[ERROR] Failed to open source file. \n";
    exit(1);
  }
  if (!destFile.is_open()) {
    std::cout << "[ERROR] Failed to create a destination file. \n";
    exit(1);
  } 

  while (std::getline(srcFile, line)) {
    tokens.clear();
    std::stringstream ss(trim(line));
    while (ss >> token) {
      tokens.emplace_back(token);
    } 

    if (tokens.empty()) {
      continue;
    }
    else if (tokens[0] != wm.getImportToken()) {
      destFile << line << '\n';
    } 
    else {
      std::string newFileLoc{tokens[wm.getImportTokenIndex()]};
      dirHardFormat(newFileLoc);
      std::ifstream newSrcFile(newFileLoc);
      destFile << newSrcFile.rdbuf() << "\n\n";
      newSrcFile.close();
    }
  }
}
