cmake_minimum_required(VERSION 3.20)
project(performance_command_center C CXX)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# The non-negotiable warning set from the course operating system (file 00).
add_compile_options(-Wall -Wextra -Wpedantic -Wconversion -Wshadow)
# Turn warnings into errors once you are fluent. Keep it off while learning:
# add_compile_options(-Werror)

# Build with -DSANITIZE=ON to run under Address/UB sanitizers.
option(SANITIZE "Enable Address/UB sanitizers" OFF)
if(SANITIZE)
  add_compile_options(-fsanitize=address,undefined -fno-omit-frame-pointer -g)
  add_link_options(-fsanitize=address,undefined)
endif()

enable_testing()
add_subdirectory(c_foundations/day01_sum)
