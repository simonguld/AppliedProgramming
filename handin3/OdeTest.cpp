#include <iostream>
#include <cmath>
#include <cassert>

#include "AbstractOdesolver.hpp"

int main {

AbstractOdeSolver M;
M.stepSize(0.1);

std::cout << M.stepSize << "\n";


    return 0;
}