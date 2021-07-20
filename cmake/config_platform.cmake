#------------------------------------------------------------------------------#
# Platform Checking (UNIX,WIN32,APPLE)
#------------------------------------------------------------------------------#

if (UNIX)
    # All Unix like platforms
    set(SYSTEM_LIB
        -lrt
        )
endif()

if(UNIX AND NOT APPLE)
    # Linux spesific
    set(LINUX TRUE)
else()
    # Apple spesific
    message(STATUS "> Apple")
endif()

if(LINUX)
    message(STATUS "> Linux")
endif()

if (WIN32)
    # Windows
    message(STATUS "> Windows")
endif (WIN32)