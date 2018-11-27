cmake_minimum_required(VERSION 3.8.0)

project(SmartControl)

find_package(Boost 1.67 REQUIRED)
find_package(tinyxml2 REQUIRED)

add_subdirectory(SCLib)
add_subdirectory(SCConsole)