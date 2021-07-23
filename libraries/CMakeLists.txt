cmake_minimum_required (VERSION 3.15)
# get list of all subdirs in current working directory
list_subdir(sub_dirs ${CMAKE_CURRENT_SOURCE_DIR} 1)
# add all directories in libraries
foreach(subdir ${sub_dirs})
    add_subdirectory(${subdir})
    message("library : "  ${subdir})
endforeach()