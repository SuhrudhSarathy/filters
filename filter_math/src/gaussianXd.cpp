#include "gaussianXd.h"
#include <Eigen/Dense>
#include <iostream>


using namespace Eigen;

namespace filters

{
    void mean(MatrixXd& data, VectorXd& mean){
        // X_bar = X_transpose * j/N ; where J is a N*1 vector of ones and N is the totl number of data points
        int N = data.rows();
        const VectorXd J = VectorXd::Ones(N);
        mean = data.transpose() * J / N;
    }
    double mean(VectorXd& data){
        float N = data.rows();
        auto sum = data.sum();
        return sum/N;
    }

    void covariance(MatrixXd& data, MatrixXd& covariance){
        // cov = X_transpose * (I - J/n) * X
        // I = Identity
        // J = Ones matrix

        int N = data.rows();
        MatrixXd J = MatrixXd::Ones(N, N);
        MatrixXd I = MatrixXd::Identity(N, N);
        covariance = (data.transpose() * (I - (J/N)) * data)/(N-1);
    }

    void covariance(VectorXd& data1, VectorXd& data2, MatrixXd& cov){
        // construct a hstack
        MatrixXd M(data1.rows(), data1.cols() + data2.cols());
        M << data1, data2;
        
        covariance(M, cov);
    }

    MultivariateGaussian::MultivariateGaussian(MatrixXd& data) : data_(data)
    {
        mean(data, mean_);
        covariance(data, covariance_);

    }

    MultivariateGaussian::MultivariateGaussian(VectorXd& mean, MatrixXd& cov) : mean_(mean), covariance_(cov)
    {}

    VectorXd MultivariateGaussian::get_mean(){
        return mean_;
    }

    MatrixXd MultivariateGaussian::get_covariance(){
        return covariance_;
    }

    double MultivariateGaussian::probability(VectorXd& x){
        MatrixXd in = (x-mean_).transpose() * covariance_.inverse() * (x-mean_) * (-0.5);
        int N = x.rows();
        double denom = std::sqrt(std::pow(2*M_PI, N) * covariance_.norm());

        std::cout << in << std::endl;

        std:: cout << std::exp(in.value()) << std::endl;
        return 0.0;
    }
}
