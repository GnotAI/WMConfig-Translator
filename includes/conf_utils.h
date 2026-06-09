#pragma once
#ifndef CONF_UTILS_H
#define CONF_UTILS_H

#include <string>
#include <vector>
#include "window_manager.h"

std::vector<std::string> generateSourceAndDestPaths(std::string homePath, WindowManager& wm);
void generateFullFile(WindowManager& wm);

#endif
