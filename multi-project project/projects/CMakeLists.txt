cmake_minimum_required(VERSION 3.2...3.27.5)

project("multi-project project")

add_subdirectory(insertion_sort)
add_subdirectory(insertion_sort_mf)

set(CMAKE_SUPPRESS_REGENERATION true)