cmake_minimum_required(VERSION 3.20)
project(AoC2026 CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_compile_options(-Wall -Wextra -Wpedantic)

add_subdirectory(core)

file(GLOB DAY_DIRS RELATIVE "${CMAKE_SOURCE_DIR}" "${CMAKE_SOURCE_DIR}/day*")
list(SORT DAY_DIRS)

foreach(DAY ${DAY_DIRS})
    if(IS_DIRECTORY ${CMAKE_SOURCE_DIR}/${DAY})
        add_executable(${DAY} ${DAY}/${DAY}.cpp)
        target_compile_features(${DAY} PRIVATE cxx_std_23)
        set_target_properties(${DAY} PROPERTIES
            RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/${DAY}
        )
    endif()
endforeach()
