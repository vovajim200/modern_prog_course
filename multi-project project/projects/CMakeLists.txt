cmake_minimum_required(VERSION 3.2...3.27.5)

project("multi-project project")

enable_testing()
add_subdirectory(lib/googletest)

add_subdirectory(insertion_sort)
add_subdirectory(insertion_sort_mf)
add_subdirectory(multi_level_menu)
add_subdirectory(sort)
add_subdirectory(long_number)
add_subdirectory(vector)

set(CMAKE_SUPPRESS_REGENERATION true)