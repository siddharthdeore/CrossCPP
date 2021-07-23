cmake_minimum_required (VERSION 3.15)
get_filename_component(ProjectId ${CMAKE_CURRENT_SOURCE_DIR} NAME)
string(REPLACE " " "_" ProjectId ${ProjectId})
project(${ProjectId})
#project(Rotations)

file(GLOB SOURCES src/*.cpp)

add_library(${PROJECT_NAME} ${SOURCES})
# includes all defincations in include directory
target_include_directories( ${PROJECT_NAME}
    PUBLIC ${PROJECT_SOURCE_DIR}/include
)

add_executable(Demo_${PROJECT_NAME} demo.cpp)
target_link_libraries(Demo_${PROJECT_NAME} ${PROJECT_NAME})
target_link_libraries (Demo_${PROJECT_NAME} ${Boost_LIBRARIES})