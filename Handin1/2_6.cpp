#include <iostream>
#include <cassert>
#include <cmath>

#include "2_6.h"

using namespace std;

//We are going to implement the Newton-Raphson method to find the root of
// the function exp(x) + x^3 - 5

//defining the function whose root we want to find
double f (double x)
    { return exp(x) + pow(x,3) - 5;} 

//define the derivative of f
double fprime (double x)
    { return exp(x) + 3* pow(x,2); }

//newton_Raphson root solver
double newton_Raphson (double intialGuess, double epsilon)
    {
    double x_prev, x_next; //declare variables


    //intialize x_prev
    x_prev = intialGuess; 
    //initialize x_next using the Newton Raphson algorithm
    x_next = x_prev - f(x_prev)/fprime(x_prev); 

    //iterate until tolerance is met
    while( fabs (x_next-x_prev) > epsilon )
    {
        x_prev = x_next;
        x_next = x_prev - f(x_prev)/fprime(x_prev);
    }
    return x_next; //return root
}