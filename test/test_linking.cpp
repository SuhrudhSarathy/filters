#include "calculus.h"
#include <iostream>

using namespace filters;

double f(double x){
	return 2 * x;
}

int main(){
	double result = integrate(-1, 3, f);
	std::cout << result << "\n";
}