// implement a kalman filter to track the position of a dog

#include <cmath>
#include <random>
#include <vector>
#include <sciplot/sciplot.hpp>
#include <tuple>

typedef std::tuple<double, double> tuple;
class Dog{
    private:
        double init_position;
        double init_velocity;
    public:
        Dog(double init_pos, double init_vel);
        std::vector<double> movement(int timesteps, float deltat);
        
};

class KalmanFilter{
    private:
        tuple position; // x = mean of the measurement with variance P
        tuple movement; // dx = mean of the movement and variance Q
        double R;

    public:
        KalmanFilter(const tuple& pose_mean, const tuple& pose_std, double R);
        tuple predict(const tuple&, const tuple&);
        tuple update(const tuple&, const tuple&);

        std::vector<tuple> filter(std::vector<double>& raw);        

};