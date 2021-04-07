#include <iostream>
#include "GHFilter.h"
#include <sciplot/sciplot.hpp>
#include <vector>

// test the filter based on the data given in the book
// weights = {158.0, 164.2, 160.3, 159.9, 162.1, 164.6, 169.6, 167.4, 166.4, 171.0, 171.2, 172.6}
// data = {159.2, 161.8, 162.1, 160.78, 160.985 ,163.311, 168.1, 169.696168.204 ,169.164 170.892 172.629}

using namespace sciplot;
int main(){
    std::vector<float> weights = {158.0, 164.2, 160.3, 159.9, 162.1, 164.6, 169.6, 167.4, 166.4, 171.0, 171.2, 172.6};

    GHFilter filter(weights, 160, 1.0, 0.6, 0.66, 1.0);

    std::vector<float> data = filter.get_sensored();

    for(auto val: data){
        std::cout << val << ", " ;
    }
    std::cout << std::endl;

    Vec x = linspace(0.0, 12.0, 12);

    Plot plt;
    plt.palette("set2");
    plt.legend()
        .atOutsideBottom()
        .displayHorizontal()
        .displayExpandWidthBy(2);
    plt.drawPoints(x, weights).label("Measurements");
    plt.drawCurve(x, data).label("Filtered Data");
    plt.save("./plots/test_1.pdf");
    plt.show();

}

/* Observations:
    1. The more the g value the more you trust the measurement
    2. The more the h value the more you trust your prediction
*/