#include <format>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <string_view>
#include <vector>
#include "../includes/conf_utils.h"
#include "../includes/window_manager.h"
#include "../includes/formatting.h"

std::vector<std::string> generateSourceAndDestPaths(const std::string_view homePath, WindowManager& wm) {
  std::string windowManagerFileName{ wm.getFileName() }; 
  std::string windowManagerSourcePath{ wm.getConfigDir() };
  std::string destinationFilePath { std::format("{0}/Documents/{1}", homePath, windowManagerFileName) };
  std::string sourceFilePath { std::format("{0}/.config/{1}", homePath, windowManagerSourcePath) };
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

  if (!srcFile.is_open() || !destFile.is_open()) {
    std::cout << "Failed to create a file." << "\n";
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
