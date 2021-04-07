#include "kalman_one_dim.h"
#include <iostream>
Dog::Dog(double pos, double vel) : init_position(pos), init_velocity(vel){}

std::vector<double> Dog::movement(int timestamps, float deltaT){
    std::random_device rd{};
    std::mt19937 gen{rd()};

    std::normal_distribution<double> d(0, 1);
    std::vector<double> pos;
    for(int i = 0; i < timestamps;i++){
        pos.push_back(init_position + i * init_velocity * deltaT + d(gen));
    }

    return pos;
}
KalmanFilter::KalmanFilter(const tuple& init_pos, const tuple& init_movement, double R_) : R(R_){
    position = std::make_tuple(std::get<0>(init_pos), std::get<1>(init_pos));
    movement = std::make_tuple(std::get<0>(init_movement), std::get<1>(init_movement));
}

tuple KalmanFilter::predict(const tuple& posterior, const tuple& movement){
    double x, P;
    x = std::get<0>(posterior);
    P = std::get<1>(posterior);

    double dx, Q;
    dx = std::get<0>(movement);
    Q = std::get<1>(movement);

    x = x + dx;
    P = P + Q;

    // std::cout << x << P << dx << Q << std::endl;

    tuple prior = std::make_tuple(x, P);
    return prior;
}

tuple KalmanFilter::update(const tuple& prior, const tuple& measurement){
    double x, P;
    double z;

    x = std::get<0>(prior);
    P = std::get<1>(prior);

    z = std::get<0>(measurement);

    double y = z - x; // correction
    double K = P/(P+R); // R is measurement noise

    x = x + K * y;
    P = (1-K)*P; // update step

    tuple posterior = std::make_tuple(x, P);

    return posterior;
    
}
std::vector<tuple> KalmanFilter::filter(std::vector<double>& raw)
{   
    tuple posterior = position;
    tuple prior = std::make_tuple(0, 0);
    std::vector<tuple> filtered;
    for(auto val: raw){
        prior = predict(posterior, movement);

        //make the tuple
        tuple measurement = std::make_tuple(val, R);
        posterior = update(prior, measurement);
        filtered.push_back(posterior);
    }
    return filtered;
}