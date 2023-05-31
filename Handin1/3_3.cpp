#include <iostream>
#include <fstream>
#include <cassert>
#include <cmath>

#include "3_3.h"
using namespace std;

// We are going to implement the implicit Euler method to solve y' = -y, y(0)=1 and print out the result
// given an number of gridpoints specified by the user


void implicit_Euler(int n)
{

    double y_0, a, b, h;
    a = 0; //left endpoint of interval
    b = 1; //right endpoint of interval
    y_0 = 1; //starting value for y

    double x,y;
    //Initialize x and y
    x=0; 
    y=y_0;
    //Calculate step size given the number of steps n
    h = (b-a)/(double(n));

    //create data file and data_output variable
    ofstream data_output("xy.dat");
    assert(data_output.is_open());
    
    //print initial values to file
    data_output << x << "," << y << "\n";

    //calculate and print values of x and y to file
    for (int i=0;i<n;i++)
    {
        x += h;
        y = 1/(h+1) * y;

        data_output << x << "," << y << "\n";
    }
    data_output.close();
}

