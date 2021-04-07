#include "gaussian.h"
#include <sciplot/sciplot.hpp>

using namespace sciplot;

double func(double x){
    return std::pow(x, 2);
}

int main(){
    filters::Gaussian gauss(22, 2);
    std::vector<double> list_of_pts;
    std::vector<double> x;
    for(double i = 18; i < 26; i+=0.1){
        x.push_back(i);
        list_of_pts.push_back(gauss.gaussian(i));
    }

    // compute the cdf

    std::cout << gauss.cdf(21.5, 22.5);
    Plot plt;
    plt.xlabel("Values");
    plt.ylabel("Pdf");
    plt.drawCurve(x, list_of_pts);
    plt.legend()
        .atOutsideBottom()
        .displayHorizontal()
        .displayExpandWidthBy(2);

    plt.show();
    plt.save("../plots/gaussians.pdf");
}