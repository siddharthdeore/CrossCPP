#------------------------------------------------------------------------------#
# Compiler Checking (MINGW,MSYS,CYGWIN)
#------------------------------------------------------------------------------#

if (MINGW)
    # MinGW
    message(STATUS "> MinGW")
endif()
if (MSYS)
    # MSYS
    message(STATUS "> MSYS")
endif()
if (CYGWIN)
    # CYGWIN
    message(STATUS "> CYGWIN")
endif()
if (MSVC)
    # Microsoft Visual Studio
endif (MSVC)