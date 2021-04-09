#ifndef GAUSSIANXD_H
#define GAUSSIANXD_H

#include <iostream>
#include <Eigen/Dense>
#include <sciplot/sciplot.hpp>
#include <cmath>


using namespace Eigen;

namespace filters{
    
    void mean(MatrixXd&, VectorXd&);
    double mean(VectorXd&);
    void covariance(MatrixXd&, MatrixXd&);
    void covariance(VectorXd&, VectorXd&, MatrixXd&);

    class MultivariateGaussian{
        private:
            MatrixXd data_;
            VectorXd mean_;
            MatrixXd covariance_;

        public:
            MultivariateGaussian(MatrixXd&);
            MultivariateGaussian(VectorXd&, MatrixXd&);

            VectorXd get_mean();
            MatrixXd get_covariance();

            double probability(VectorXd&);



    };
} //namespace filters

#endif