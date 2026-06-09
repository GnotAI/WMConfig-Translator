#pragma once
#ifndef WINDOW_MANAGER_H
#define WINDOW_MANAGER_H

#include <string>

class WindowManager {
  public:
    virtual std::string getImportToken() const = 0;
    virtual std::string getFileName() const = 0;
    virtual std::string getConfigDir() const = 0;
    virtual int getImportTokenIndex() const = 0;

    virtual ~WindowManager() = default;
};

#endif
