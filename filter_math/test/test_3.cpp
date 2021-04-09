#include "gaussianXd.h"
#include <Eigen/Dense>
#include <iostream>
#include <vector>

using namespace Eigen;

int main(){
    VectorXd mean(2, 1);
    mean << 2,
            17;
    MatrixXd covariance(2, 2);
    covariance << 10.0, 0,
                0.0, 4.0;
    filters::MultivariateGaussian dist(mean, covariance);

    sciplot::Vec x = sciplot::linspace(-10, 15, 0.2);
    sciplot::Vec y = sciplot::linspace(5, 25, 0.2);
    std::vector<double> z;
    for(auto x_: x){
        for(auto y_: y){
            VectorXd vec(2, 1);
            vec << x_,
                   y_;

            double z_ = dist.probability(vec);
            z.push_back(z_);
        }
    }
    for(auto val: z){
        std::cout << val << std::endl;
    }
}