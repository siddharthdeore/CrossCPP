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
