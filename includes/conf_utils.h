#pragma once
#ifndef CONF_UTILS_H
#define CONF_UTILS_H

#include <vector>
#include <string_view>
#include "window_manager.h"

std::vector<std::string> generateSourceAndDestPaths(const std::string_view homePath, WindowManager& wm);
void generateFullFile(WindowManager& wm);

#endif
