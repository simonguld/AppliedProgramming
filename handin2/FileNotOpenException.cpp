#include <iostream>
#include <string>

#include "FileNotOpenException.hpp"

FileNotOpenException::FileNotOpenException(std::string prob) : Exception("FILE",prob)
{
}

/*
int main()
{
    FileNotOpenException err("hej");

    err.PrintDebug();


    return 0;
}
*/
