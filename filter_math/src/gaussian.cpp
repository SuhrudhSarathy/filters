#include "gaussian.h"

namespace filters{

    Gaussian::Gaussian(double mean_, double std_) : mean(mean_), std(std_){}

    double Gaussian::gaussian(double x){
    return std::exp(-0.5 * std::pow((x - mean)/std::pow(std, 2), 2))/(std * std::sqrt(2*M_PI));

    }

    double Gaussian::cdf(double start, double stop){
        // trapeziodal integration
        double integral_sum = 0;
        int N = 1000;
        double delta_x = (stop - start)/N;

        for(int i = 0; i <=N; i++){
            if(i == 0 || i == N){
                integral_sum += gaussian(start + delta_x*i);
            }
            else{
                integral_sum += 2 * gaussian(start + delta_x*i);
            }
        }         
        return (integral_sum * delta_x) * 0.5;
    }

    // get set functions
    void Gaussian::set_mean(double mean_){
        mean = mean_;
    }

    void Gaussian::set_std(double std_){
        std = std_;
    }

    double Gaussian::get_mean(){
        return mean;
    }

    double Gaussian::get_std(){
        return std;
    }

    Gaussian add_two_gaussians(Gaussian g1, Gaussian g2){
        double mean1, mean2, std1, std2;
        mean1 = g1.get_mean();
        mean2 = g2.get_mean();
        std1 = g1.get_std();
        std2 = g2.get_std();

        Gaussian sum(mean1 + mean2, std::pow(std1, 2) + std::pow(std2, 2));

        return sum;
    }

    Gaussian multiply_two_gaussians(Gaussian g1, Gaussian g2){
        double mean1, mean2, std1, std2;
        mean1 = g1.get_mean();
        mean2 = g2.get_mean();
        std1 = pow(g1.get_std(), 2);
        std2 = pow(g2.get_std(), 2);

        double div = std1 + std2;
        double new_mean = (std1*mean2 + std2*mean1)/div;
        double new_std = std::sqrt(std1*std2/div);

        Gaussian mul(new_mean, new_std);
        
        return mul;

    }

    void add_two_gaussians(Gaussian& g, Gaussian& g1, Gaussian& g2){
        double mean1, mean2, std1, std2;
        mean1 = g1.get_mean();
        mean2 = g2.get_mean();
        std1 = g1.get_std();
        std2 = g2.get_std();

        g.set_mean(mean1 + mean2);
        g.set_std(std::pow(std1, 2) + std::pow(std2, 2));
    }

    void multiply_two_gaussians(Gaussian& g, Gaussian& g1, Gaussian& g2){
        double mean1, mean2, std1, std2;
        mean1 = g1.get_mean();
        mean2 = g2.get_mean();
        std1 = pow(g1.get_std(), 2);
        std2 = pow(g2.get_std(), 2);

        double div = std1 + std2;
        double new_mean = (std1*mean2 + std2*mean1)/div;
        double new_std = std::sqrt(std1*std2/div);

        g.set_mean(new_mean);
        g.set_std(new_std);

    }

} //namespace filters