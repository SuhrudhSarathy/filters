#include <iostream>
#include <Eigen/Dense>

using namespace Eigen;

int main(){
    Matrix3f haha;
    haha << 1, 2, 3,
            4, 5, 6,
            7, 8, 9;
    std::cout << haha << std::endl;
}