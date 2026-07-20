#pragma once
#ifndef WINDOW_MANAGER_H
#define WINDOW_MANAGER_H

#include <string_view>

class WindowManager {
  protected:
    const int importTokenIndex;
    const std::string_view importToken;

  public:
    WindowManager(const std::string_view& stringValue, const int intValue);
    virtual ~WindowManager() = default;
    std::string_view getImportToken() const;
    int getImportTokenIndex() const;
};

#endif
