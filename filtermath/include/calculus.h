#include <iostream>
#include <cmath>


namespace filters{

    typedef double function(double);
    typedef double function_2(double, double);
    typedef double function_3(double, double, double);

    double integrate(double start, double goal, function func);
    double integrate(double start, double goal, function_2 func, double param1);
    double integrate(double start, double goal, function_3 func, double param1, double param2);

    double differentiate(double x, function f);
    double differentiate(double x, function_2 f, double param1);
    double differentiate(double x, function_3 f, double param1, double param2);
}