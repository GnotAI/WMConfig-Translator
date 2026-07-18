#pragma once
#ifndef NIRI_H
#define NIRI_H

#include <string>
#include "window_manager.h"

class Niri : public WindowManager {
  public:
    explicit Niri();
    ~Niri() override;

    std::string getImportToken() const override;
    int getImportTokenIndex() const override;
};

#endif
