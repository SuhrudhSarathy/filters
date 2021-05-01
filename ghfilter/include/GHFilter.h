// Basic weights Execrice
// pg: 39 1.4.1

#include <iostream>
#include <vector>
#include <sciplot/sciplot.hpp>

using namespace sciplot;

class GHFilter{
    public:
        GHFilter(std::vector<float>&, float, float, float, float, float);
        void main();
        std::vector<float> get_sensored();
    private:
        // variables
        std::vector<float> data;
        float x0;
        float x_step;
        float t_step;
        float g;
        float h;

        std::vector<float> sensored;
};