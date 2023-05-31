#include <iostream>

#include "OutOfRangeException.hpp"

OutOfRangeException::OutOfRangeException(std::string prob) : Exception ("FILE", prob)
{

}


