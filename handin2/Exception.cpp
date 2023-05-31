#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

#include "Exception.hpp"


Exception::Exception(std::string tagString, std::string probString)
{
    mTag = tagString;
    mProblem = probString;
}

void Exception::PrintDebug() const
{
    std::cerr << "** Error (" << mTag << ") ** \n";
    std::cerr << "Problem:  " << mProblem << "\n \n";
}

void PosChecker(double x)
    {
        if (x<0.0)
        {
            throw (Exception("Illegal operator", "The program attempted to calculate the square root of a negative number."));
        }
    }
/*
int main ()
{

    double x=-3;
    try
    {
        PosChecker(x);
        std::cout << sqrt(x) << "\n";
    }
    catch(Exception& error)
    {
        error.PrintDebug();
    }
    

    return 0;
}
*/