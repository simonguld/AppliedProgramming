#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <iterator>

#include "Exception.hpp"
#include "OutofRangeException.hpp"
#include "FileNotOpenException.hpp"

void ReadFile (const std::string& fileName, double x[], double y[], int length)
{
    int len = 6;

    std::ifstream read_file (fileName.c_str());
    if (read_file.is_open() == false)
    {
        throw FileNotOpenException("File cannot be openened!");
    }

    //double len_x = sizeof(x)/sizeof(x[0]);
    //int len_xx = (int)(x);
    //double len_y = sizeof(y)/sizeof(y[0]);
    //std::cout << sizeof(y) << "   " << len_y << "\n";
    //std::cout.flush();
    //int len_yy = int(y);
    // std::cout << sizeof(x) << "  - " << sizeof(x)/sizeof(x[0]);

    if ( length!= len)
    {
        throw OutOfRangeException("Vectors have the wrong size. Change the 'len' parameter in the function ReadFile to change size");
    }

    for (int i = 0; i<len; i++)
    {
        read_file >> x[i] >> y[i];
    }

    read_file.close();
    std::cout << fileName << " read succesfully \n";
}

int main ()
{
    int length = 7;
    double x[length],y[length];

    //std::cout << sizeof(x) << "   " << sizeof(x)/sizeof(x[0]);

    try
    {
        ReadFile("xy.dat",x,y,length);
    }
    catch(Exception &error)
    {
        error.PrintDebug();
        
    }

    return 0;
}