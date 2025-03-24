cmake_minimum_required(VERSION 3.15)
project(HW2)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)

# Fetch termcolor (header-only)
FetchContent_Declare(
        termcolor
        GIT_REPOSITORY https://github.com/ikalnytskyi/termcolor.git
        GIT_TAG master
)
FetchContent_MakeAvailable(termcolor)

# Main executable
add_executable(${PROJECT_NAME}
        cart.cpp
        main.cpp
        )

# Include termcolor headers
target_include_directories(${PROJECT_NAME} PRIVATE ${termcolor_SOURCE_DIR}/include)

# Copy menu.txt to executable output directory
configure_file(menu.txt menu.txt COPYONLY)
