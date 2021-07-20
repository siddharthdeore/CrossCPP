#------------------------------------------------------------------------------#
# COPYRIGHT (C) Siddharth Deore <siddharth.deore@iit.it>
# Cross Platform C++ Boilerplate Template
#------------------------------------------------------------------------------#
cmake_minimum_required (VERSION 3.14 FATAL_ERROR)

set (PROJECT_NAME "Cross")
project (${PROJECT_NAME})
# Cmake otion to build examples / set off to skip
option(BUILD_01_Eigen         "Build eigen library demo" ON)
option(BUILD_02_Shared_Memory "Build boost header only library demo" ON)
option(BUILD_03_Boost_Chrono  "Build boost precompiled library link demo" ON)

#------------------------------------------------------------------------------#
# Source code Structuring guidelines
#
# set (PROJECT_SOURCE_DECLARATION_DIR ${PROJECT_SOURCE_DIR}/include)
# set (PROJECT_SOURCE_DEFINITION_DIR ${PROJECT_SOURCE_DIR}/src)
# set (MAIN_FILE ${PROJECT_SOURCE_DEFINITION_DIR}/main.cc)
# option settings for "CMake".
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
# include_directories (${PROJECT_SOURCE_DECLARATION_DIR})
#------------------------------------------------------------------------------#


#------------------------------------------------------------------------------#
# CMake Modules
#------------------------------------------------------------------------------#
# Platform spesific instructions
include(cmake/config_platform.cmake)
# Compiler spesific instructions
include(cmake/config_compiler.cmake)
# Boost Library configration
include(cmake/config_boost.cmake)
# check and update git submodules
include(cmake/config_git_submodules.cmake)
# fetch eigen with git submodule
include(cmake/config_eigen.cmake)
#------------------------------------------------------------------------------#

#------------------------------------------------------------------------------#
# Build Targets
#------------------------------------------------------------------------------#
# examples
add_subdirectory(examples)
