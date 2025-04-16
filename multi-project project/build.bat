@echo off

set BUILD_TYPE=Ninja
set BUILD_SUFFIX=ninja

chcp 65001

set BUILD_FOLDER=build_%BUILD_SUFFIX%
set SOURCE_FOLDER=projects

if not exist %BUILD_FOLDER% mkdir %BUILD_FOLDER%

cd %BUILD_FOLDER%

cmake -G %BUILD_TYPE% ..\%SOURCE_FOLDER%
cmake --build .

copy ..\%SOURCE_FOLDER%\insertion_sort\run_insertion_sort.bat .\insertion_sort
copy ..\%SOURCE_FOLDER%\insertion_sort_mf\run_insertion_sort_mf.bat .\insertion_sort_mf
copy ..\%SOURCE_FOLDER%\multi_level_menu\run_menu.bat .\multi_level_menu

copy ..\run_tests.bat .

pause