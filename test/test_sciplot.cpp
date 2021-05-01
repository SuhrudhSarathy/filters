#include <iostream>
#include <sciplot/sciplot.hpp>

using namespace sciplot;
int main(){
    Vec x = linspace(0.0, 2*PI, 200);
    Plot plt;
    plt.xlabel("x");
    plt.ylabel("y");

    plt.xrange(0.0, PI);
    plt.yrange(0.0, 1.0);

    plt.legend()
        .atOutsideBottom()
        .displayHorizontal()
        .displayExpandWidthBy(2);
    plt.drawCurve(x, std::sin(x)).label("sin(x)");
    plt.show();    
}