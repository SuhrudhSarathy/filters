#include "gaussian.h"
#include <sciplot/sciplot.hpp>

using namespace sciplot;

// multiplication of two gaussians

int main(){
    filters::Gaussian gauss1(1, 0.5);
    filters::Gaussian gauss2(2, 0.7);

    std::vector<double> list_of_pts;
    std::vector<double> gauss1_pts;
    std::vector<double> gauss2_pts;
    std::vector<double> x;

    double sum = 0;
    for(double i = 0; i < 4; i+=0.01){
        double product = gauss1.gaussian(i) * gauss2.gaussian(i);
        sum += product;
        x.push_back(i);
        list_of_pts.push_back(product);
        gauss1_pts.push_back(gauss1.gaussian(i));
        gauss2_pts.push_back(gauss2.gaussian(i));
    }
    for(auto val: list_of_pts){
        val /= sum;
    }
    Plot plt;
    plt.drawCurve(x, list_of_pts).label("Sum");
    plt.drawCurve(x, gauss1_pts).label("Gauss 1");
    plt.drawCurve(x, gauss2_pts).label("Gauss 2");
    plt.legend()
        .atOutsideBottom()
        .displayHorizontal()
        .displayExpandWidthBy(2);
    plt.show();
}