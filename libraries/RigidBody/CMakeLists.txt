cmake_minimum_required (VERSION 3.15)

get_filename_component(ProjectId ${CMAKE_CURRENT_SOURCE_DIR} NAME)
string(REPLACE " " "_" ProjectId ${ProjectId})
project(${ProjectId})

#project(RigidBody)
file(GLOB SOURCES src/*.cpp)
add_library(${PROJECT_NAME} ${SOURCES})
# includes all defincations in include directory
target_include_directories( ${PROJECT_NAME}
    PUBLIC ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(${PROJECT_NAME} Rotations ${Boost_LIBRARIES})

add_executable(Demo_${PROJECT_NAME} demo.cpp)
target_link_libraries(Demo_${PROJECT_NAME} ${PROJECT_NAME} Rotations)

