################################################################################
# Target 1 Eigen and boost lambda test
if(BUILD_01_Eigen)
    add_executable (EigenTest
                    01_eigen/eigen.cpp)

    target_include_directories(EigenTest PUBLIC  ${Boost_INCLUDE_DIRS})

    set_target_properties(EigenTest PROPERTIES CXX_EXTENSIONS OFF)
    # target_compile_features(EigenTest PUBLIC cxx_std_11)
    # Link a target to libraries.
    target_link_libraries (EigenTest ${Boost_LIBRARIES})
endif()

################################################################################
# Target 2 Boost interprocess communication requires header only boost libraries
if(BUILD_02_Shared_Memory)
    add_executable (SharedMemory
                    02_boost_header_only/share_memory.cpp)

    target_link_libraries (SharedMemory ${Boost_LIBRARIES})
endif()



################################################################################
# Target 3 Requires compiled boost libraries
# On windows linking needs administrative permissions
# (since I'm using precompilede libraries)
if(BUILD_03_Boost_Chrono)
    add_executable (BoostChrono
                    03_boost_chrono/boost_chrono.cpp)
    #target_include_directories(BoostChrono PUBLIC  ${Boost_INCLUDE_DIRS})
    target_link_libraries (BoostChrono ${Boost_LIBRARIES})
endif()
