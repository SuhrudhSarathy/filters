#include "kalman_one_dim.h"
#include <iostream>
#include <sciplot/sciplot.hpp>
#include <tuple>

using namespace sciplot;

int main(){
    Dog doggo(10, 0);
    std::vector<double> movement = doggo.movement(100, 0.5);

    tuple init = std::make_tuple(10, 2);
    tuple meas = std::make_tuple(0.5, 2);
    double R = 17;
    
    KalmanFilter KF(init, meas, R);
    std::vector<tuple> filtered = KF.filter(movement);

    std::vector<double> filtered_x;
    for(auto val: filtered){
        filtered_x.push_back(std::get<0>(val));
    }

    Plot plt;
    Vec x = linspace(0, movement.size(), movement.size());


    plt.drawPoints(x, movement).label("Movement");
    plt.drawCurve(x, filtered_x).label("Filtered");
    plt.legend()
        .atOutsideBottom()
        .displayHorizontal()
        .displayExpandWidthBy(2);
    plt.show();
    plt.save("../plots/test_1.pdf");
}