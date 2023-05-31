#include <iostream>
#include <cassert>
#include <cmath>

#include "5_3.h"

using namespace std;

//function that swaps the value of two doubles using pointers
void swap_pointer(double *a, double *b)
{
    double z;

    z = *a;
    *a = *b;
    *b = z;
}

//function that swaps the value of two doubles using references
void swap_ref(double &a, double &b)
{
    double z;

    z = a;
    a = b;
    b = z;
}


