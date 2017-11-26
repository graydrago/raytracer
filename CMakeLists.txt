cmake_minimum_required(VERSION 3.5)

project(raytracer)

function(add_flag flag)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${flag}" PARENT_SCOPE)
endfunction()

set(SOURCE_EXE
  src/ShadeRec.cpp src/World.cpp main.cpp)

add_executable( ${PROJECT_NAME} ${SOURCE_EXE} )

# common flags
add_flag("-std=c++11")
add_flag("-Wall")
#add_flag("-v")

target_link_libraries( ${PROJECT_NAME} SDL2)
