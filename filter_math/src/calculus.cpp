#include "calculus.h"

namespace filters{
    double integrate(double start, double stop, function f){
        // trapeziodal integration
        double integral_sum = 0;
        int N = 1000;
        double delta_x = (stop - start)/N;

        for(int i = 0; i <=N; i++){
            if(i == 0 || i == N){
                integral_sum += f(start + delta_x*i);
            }
            else{
                integral_sum += 2 * f(start + delta_x*i);
            }
        }

        return (integral_sum * delta_x) * 0.5;
    }
    
    double differentiate(double x, function f){
        double h = 0.0001;
        return (f(x + h) - f(x))/h;
    }
}