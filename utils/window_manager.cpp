#include <string_view>
#include "../includes/window_manager.h"

WindowManager::WindowManager(const std::string_view& stringValue, const int intValue) : importToken(stringValue), importTokenIndex(intValue) {}

std::string_view WindowManager::getImportToken() const {
  return importToken;
}

int WindowManager::getImportTokenIndex() const {
  return importTokenIndex;
}
