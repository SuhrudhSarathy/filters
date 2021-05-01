cmake_minimum_required(VERSION 3.2.0)
project(filters)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)



find_package(Eigen3 3.3 REQUIRED NO_MODULE)
find_package(sciplot)

add_subdirectory(filtermath)
add_subdirectory(kalman)
add_subdirectory(ghfilter)

# Add thing that directly deal with those in the filters
# directory
add_executable(test_linking test/test_linking.cpp)
target_link_libraries(test_linking PUBLIC filtermath)
target_include_directories(test_linking PUBLIC
						"${PROJECT_SOURCE_DIR}/filtermath/include"	
)

