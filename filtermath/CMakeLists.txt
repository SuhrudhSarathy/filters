cmake_minimum_required(VERSION 3.2.0)

include_directories(include)

find_package(Eigen3 3.3 REQUIRED NO_MODULE)
find_package(sciplot)


set(FILTER_MATH_SOURCES
	src/calculus.cpp include/calculus.h
	src/gaussian.cpp include/gaussian.h
	src/gaussianXd.cpp include/gaussianXd.h 
)
add_library(filtermath ${FILTER_MATH_SOURCES})
target_link_libraries(filtermath Eigen3::Eigen)
target_link_libraries(filtermath sciplot::sciplot)