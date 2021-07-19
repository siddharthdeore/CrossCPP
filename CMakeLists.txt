################################################################################
# COPYRIGHT (C) Siddharth Deore <siddharth.deore@iit.it>
# Cross Platform C++ Boilerplate Template
################################################################################
cmake_minimum_required (VERSION 3.14 FATAL_ERROR)

set (PROJECT_NAME "Cross")
project (${PROJECT_NAME})
# Cmake otion to build examples / set off to skip
option(BUILD_01_Eigen         "Build eigen library demo" ON)
option(BUILD_02_Shared_Memory "Build boost header only library demo" ON)
option(BUILD_03_Boost_Chrono  "Build boost precompiled library link demo" ON)

################################################################################
# Source code Structuring guidelines
# set (PROJECT_SOURCE_DECLARATION_DIR ${PROJECT_SOURCE_DIR}/include)
# set (PROJECT_SOURCE_DEFINITION_DIR ${PROJECT_SOURCE_DIR}/src)
# set (MAIN_FILE ${PROJECT_SOURCE_DEFINITION_DIR}/main.cc)
# Set options used by "CMake".
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
################################################################################
# include_directories (${PROJECT_SOURCE_DECLARATION_DIR})

################################################################################
# BOOST
################################################################################
set (Boost_NO_SYSTEM_PATHS ON)
set (Boost_USE_MULTITHREADED ON)
set (Boost_USE_STATIC_LIBS ON)
set (Boost_USE_STATIC_RUNTIME OFF)
set (Boost_DEBUG OFF)
set (BOOST_ALL_DYN_LINK ON)
# For Windows set envirnoment variables as :
# set (BOOST_ROOT "D:/boost_1_72_0")
# set (BOOST_INCLUDEDIR "D:/boost_1_72_0/boost")
# set (BOOST_LIBRARYDIR "D:/boost_1_72_0/stage/lib")
find_package (Boost 1.66 REQUIRED COMPONENTS chrono)
if (Boost_FOUND)
  include_directories (SYSTEM ${Boost_INCLUDE_DIR})
endif ()

################################################################################
# Git Submodule searches for existing submodules
################################################################################
find_package(Git QUIET)
if(GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git")
# Update submodules as needed
    option(GIT_SUBMODULE "Check submodules during build" ON)
    if(GIT_SUBMODULE)
        message(STATUS "Submodule update")
        execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
                        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                        RESULT_VARIABLE GIT_SUBMOD_RESULT)
        if(NOT GIT_SUBMOD_RESULT EQUAL "0")
            message(FATAL_ERROR "git submodule update --init --recursive failed with ${GIT_SUBMOD_RESULT}, please checkout submodules")
        endif()
    endif()
endif()
################################################################################
# Eigen (using git add submodule)
################################################################################
if(NOT EXISTS "${PROJECT_SOURCE_DIR}/external/eigen/CMakeLists.txt")
    message(FATAL_ERROR "The submodules were not downloaded! GIT_SUBMODULE was turned off or failed. Please update submodules and try again.")
endif()
set( EIGEN3_INCLUDE_DIR "external/eigen" )  # e.h. "C:/Program Files/eigen3"
if( NOT EIGEN3_INCLUDE_DIR )
    message( FATAL_ERROR "Please point the environment variable EIGEN3_INCLUDE_DIR to the include directory of your Eigen3 installation.")
else()
    include_directories ( "${EIGEN3_INCLUDE_DIR}" )
endif()



# Build examples only if set on in ccmake
if(Demo_BUILD_EXAMPLES)
    add_subdirectory(examples)
endif()