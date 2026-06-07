cmake_minimum_required(VERSION 3.20)
project(WMConfigTranslator)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(WMConfigTranslator
				main.cpp
				utils/conf_utils.cpp
				utils/formatting.cpp
)

target_include_directories(WMConfigTranslator PRIVATE
				includes
)
