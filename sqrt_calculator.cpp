#include <iostream>
#include <cmath>
#include <cassert>
using namespace std;

double sq_solver(double x,double tolerance = 1e-6);


int main ()
{


cout << sq_solver(2);


    return 0;
}

double sq_solver(double x,double tolerance)
{
    int n=0;
    double root,a,b;
    b=x;
    a=0;
    root = (b-a)/2;
    while (fabs(root*root-x)>tolerance & n<100)
    {
        n +=1;
        if (root*root>x)
        {
            b=root; 
        }
        else
        {
            a=root;
        }
        root = a+(b-a)/2;
    }
    return root;
}