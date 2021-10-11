################################################################################
# Target 1 Eigen and boost lambda test
# if(BUILD_01_Eigen)
    add_executable (example_EigenTest 01_eigen/eigen.cpp)

    target_include_directories(example_EigenTest PUBLIC  ${Boost_INCLUDE_DIRS})
    set_target_properties(example_EigenTest PROPERTIES CXX_EXTENSIONS OFF)
    # target_compile_features(example_EigenTest PUBLIC cxx_std_11)
    # Link a target to libraries.
    target_link_libraries (example_EigenTest)
# endif()

################################################################################
# Target 2 Boost interprocess communication requires header only boost libraries
# if(BUILD_02_Shared_Memory)
    add_executable (example_SharedMemory 02_boost_header_only/share_memory.cpp)
    target_link_libraries (example_SharedMemory ${SYSTEM_LIB} )
# endif()

################################################################################
# Target 3 Requires compiled boost libraries
# On windows linking needs administrative permissions
# (I'm using precompilede libraries)
# if(BUILD_03_Boost_Chrono)
    add_executable (example_BoostChrono 03_boost_chrono/boost_chrono.cpp)
    #target_include_directories(example_BoostChrono PUBLIC  ${Boost_INCLUDE_DIRS})
    target_link_libraries (example_BoostChrono ${Boost_LIBRARIES})
# endif()

################################################################################
# Target 4 Example of shared own libraries
# if(BUILD_04_Rigid_Body)
add_executable (example_VSCMG 04_VSCMG/vscmg.cpp)
#target_include_directories(example_VSCMG PUBLIC  ${Boost_INCLUDE_DIRS})
target_link_libraries (example_VSCMG VSCMG)
# endif()

################################################################################
# Target 5 Example of shared own libraries
# if(BUILD_05_Rigid_Body)
add_executable (example_Timer 05_timer/timer_test.cpp)
target_link_libraries (example_Timer pthread rt)
# endif()
