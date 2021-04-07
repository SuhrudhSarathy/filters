#include <random>
#include <vector>
#include "calculus.h"

namespace filters{

    class Gaussian{
        private:
            double mean, std;
        public:
            Gaussian(double, double);

            // gaussian(x)
            double gaussian(double);
            double cdf(double, double);
            // get set functions
            void set_mean(double);
            void set_std(double);

            double get_mean();
            double get_std();
    };

    Gaussian add_two_gaussians(Gaussian g1, Gaussian g2);
    
    Gaussian multiply_two_gaussians(Gaussian g1, Gaussian g2);

    void add_two_gaussians(Gaussian& g, Gaussian& g1, Gaussian& g2);

    void multiply_two_gaussians(Gaussian& g, Gaussian& g1, Gaussian& g2);
}