target_sources(insertion_sort_mf
	PRIVATE
		io.cpp
		io.hpp
		sortings.cpp
		sortings.hpp
)

target_include_directories(insertion_sort_mf PRIVATE
	"${PROJECT_SOURCE_DIR}/sortings"
)