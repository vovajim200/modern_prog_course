set(SOURCES
	test_insertion.cpp
)

add_executable(test_insertion ${SOURCES})
target_link_libraries(test_insertion
	gtest_main
	gmock_main
	insertion_sort_lib
)

add_test(test_insertion test_insertion)