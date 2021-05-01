// Exercise generating random data

#include "GHFilter.h"

#include <iostream>
#include <vector>
#include <random>
#include <cmath>
#include <Eigen/Dense>
#include <sciplot/sciplot.hpp>

using namespace sciplot;

std::vector<float> randomised_data(std::vector<float>& data, float noise_factor){
    std::random_device rd;
    std::mt19937 gen(rd());

    std::normal_distribution<float> dis(2, 4);
    std::vector<float> randomised;
    for(auto val: data){
        randomised.push_back(val + dis(gen));
    }

    return randomised;
}

std::vector<float> data_gen(float start, float step, int count){
    std::vector<float> data;
    float accel = 9;
    for(int i = 0; i < count; i++){
        data.push_back(start + accel * pow(i, 2));
    }
    return data;
}
int main(){
    // get data
    std::vector<float> data_ = data_gen(10, 0, 20);
    std::vector<float> data = randomised_data(data_, 2);

    GHFilter filter(data, 150 ,0.5, 0.4, 0.04, 1);

    std::vector<float> filtered = filter.get_sensored();

    Vec x = linspace(0.0, data.size(), data.size());

    Plot plt;
    plt.palette("set2");
    plt.legend()
        .atOutsideBottom()
        .displayHorizontal()
        .displayExpandWidthBy(2);
    plt.drawPoints(x, data).label("Measurements");
    plt.drawCurve(x, filtered).label("Filtered Data");
    plt.save("./plots/test_2_accel.pdf");
    plt.save("./plots/test_2_accel.png");
    plt.show();

}
