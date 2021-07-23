#------------------------------------------------------------------------------#
# COPYRIGHT (C) Siddharth Deore <siddharth.deore@iit.it>
# Cross Platform C++ Boilerplate Template
#------------------------------------------------------------------------------#
cmake_minimum_required (VERSION 3.15)

set (PROJECT_NAME "CrossCPP")
project (${PROJECT_NAME})

# Cmake otion to build examples / set off to skip
option(BUILD_Examples        "Build Example executable files" ON)
option(BUILD_SharedLibraries "Build Shared Libraries" ON)

#------------------------------------------------------------------------------#
# Source code Structuring guidelines
#
# option settings for "CMake".
set (CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
# set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

# set (PROJECT_SOURCE_DECLARATION_DIR ${PROJECT_SOURCE_DIR}/include)
# set (PROJECT_SOURCE_DEFINITION_DIR ${PROJECT_SOURCE_DIR}/src)
# set (MAIN_FILE ${PROJECT_SOURCE_DEFINITION_DIR}/main.cc)
# include_directories (${PROJECT_SOURCE_DECLARATION_DIR})
#------------------------------------------------------------------------------#
#------------------------------------------------------------------------------#
# CMake Modules
#------------------------------------------------------------------------------#
include(cmake/config_platform.cmake) # Platform spesific instructions
include(cmake/config_compiler.cmake) # Compiler spesific instructions
include(cmake/config_boost.cmake) # Boost Library configration
include(cmake/config_git_submodules.cmake) # check and update git submodules
include(cmake/config_eigen.cmake) # fetch eigen with git submodule
include(cmake/list_subdir.cmake) # list of subdirs e.g. list_subdir(lst path 1)
#------------------------------------------------------------------------------#

#------------------------------------------------------------------------------#
# Build libraries Targets
#------------------------------------------------------------------------------#
if(${BUILD_SharedLibraries})
    set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/demos)
    add_subdirectory(libraries)
endif()


#------------------------------------------------------------------------------#
# Build Executable Targets
#------------------------------------------------------------------------------#
# examples
if(${BUILD_Examples})
    set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/examples)
    add_subdirectory(examples)
endif()