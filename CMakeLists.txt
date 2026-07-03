cmake_minimum_required(VERSION 3.20)
project(AoC2026 CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_compile_options(-Wall -Wextra -Wpedantic)

add_subdirectory(core)

file(GLOB DAY_DIRS RELATIVE "${CMAKE_SOURCE_DIR}" "${CMAKE_SOURCE_DIR}/day*")
list(SORT DAY_DIRS)

foreach(DAY_DIR ${DAY_DIRS})
  if(IS_DIRECTORY "${CMAKE_SOURCE_DIR}/${DAY_DIR}")
    file(GLOB DAY_SOURCES "${CMAKE_SOURCE_DIR}/${DAY_DIR}/*.cpp")
    if(DAY_SOURCES)
      add_executable(${DAY_DIR} ${DAY_SOURCES})
      target_link_libraries(${DAY_DIR} PRIVATE core)
    endif()
  endif()
endforeach()