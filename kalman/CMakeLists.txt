cmake_minimum_required(VERSION 3.2.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(Eigen3 3.3 REQUIRED NO_MODULE)
find_package(sciplot)

include_directories(include)

set(KALMAN_SOURCE
	src/kalman_one_dim.cpp
	include/kalman_one_dim.h
	)
add_library(kalman ${KALMAN_SOURCE})
target_link_libraries(kalman filtermath)
target_link_libraries(kalman Eigen3::Eigen)
target_link_libraries(kalman sciplot::sciplot)

