target_sources(multi_level_menu
	PRIVATE
		menu.hpp
		menu_functions.hpp
		menu_functions.cpp
		menu_items.hpp
		menu_items.cpp
)

target_include_directories(multi_level_menu PRIVATE
	"${PROJECT_SOURCE_DIR}/menuitem"
)