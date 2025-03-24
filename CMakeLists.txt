cmake_minimum_required(VERSION 3.15)
project(HW2)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)

# Fetch termcolor
FetchContent_Declare(
        termcolor
        GIT_REPOSITORY https://github.com/ikalnytskyi/termcolor.git
        GIT_TAG master
)

FetchContent_MakeAvailable(termcolor)

# Define your executable
add_executable(${PROJECT_NAME}
        cart.cpp
        main.cpp
        )

# Add termcolor's include directory
target_include_directories(${PROJECT_NAME} PRIVATE ${termcolor_SOURCE_DIR}/include)
