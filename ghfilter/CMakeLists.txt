cmake_minimum_required(VERSION 3.2.0)

include_directories(include)

find_package(Eigen3 3.3 REQUIRED NO_MODULE)
find_package(sciplot)

set(GH_SOURCES
	src/GHFilter.cpp 
	include/GHFilter.h
	)
add_library(ghfilter ${GH_SOURCES})
target_link_libraries(ghfilter filtermath)
target_link_libraries(ghfilter Eigen3::Eigen)
target_link_libraries(ghfilter sciplot::sciplot)

