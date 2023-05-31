#include <iostream>
#include <cassert>
#include <cmath>

#include "5_4.h"

using namespace std;



//function that calculates the mean of a vector a[]:

double calc_mean (double a[], int length)
{
    double sum=0;
    for(int i=0; i<length; i++)
    {
        sum += a[i];
    }
    return sum/length;
}

// function that calculates the corrected sample standard deviation
double calc_std (double a[], int length)
{
if (length ==1)
{
    return 0;
}
else
{
    double mean, square_sum,std;
    mean = calc_mean(a,length);

    square_sum=0;
    for (int i= 0; i<length; i++)
    {
        square_sum += (a[i] - mean)*(a[i] - mean);

    }
    std = sqrt(square_sum/(length-1));
    return std;
}
}

    
