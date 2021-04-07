// Basic weights Execrice
// pg: 39 1.4.1

#include "GHFilter.h"

GHFilter::GHFilter(std::vector<float>& data_, float x0_, float x_step_, float g_, float h_, float t_step_)
: data(data_), x0(x0_), x_step(x_step_), t_step(t_step_), g(g_), h(h_)
{
    main();
}

void GHFilter::main(){
    float x_est = x0;
    for(auto& d: data){

        // prediction
        float x_pred = x_est + (x_step*t_step);
        x_step = x_step;

        // update step
        float residual = d - x_pred;
        x_step = x_step + h * (residual/t_step);
        x_est = x_pred + g * residual;
        sensored.push_back(x_est);
    }
}

std::vector<float> GHFilter::get_sensored(){
    return sensored;
}