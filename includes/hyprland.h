#pragma once
#ifndef HYPRLAND_H
#define HYPRLAND_H

#include <string>
#include "window_manager.h"

class Hyprland : public WindowManager {
  public:
    explicit Hyprland();
    ~Hyprland() override;

    std::string getImportToken() const override;
    int getImportTokenIndex() const override;
};

#endif
