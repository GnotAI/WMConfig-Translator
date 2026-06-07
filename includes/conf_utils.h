#pragma once
#ifndef CONF_UTILS_H
#define CONF_UTILS_H

#include <string>

enum class WM {
	Hypr,
	Niri,
	Mangowc,
	Sway
};

std::string getKeyword(const WM& wm);
void generateFullFile(std::string& srcPath, std::string& destPath, WM wm);

#endif
