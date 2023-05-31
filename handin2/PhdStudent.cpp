#include <iostream>
#include <string>

#include "PhdStudent.hpp"



PhdStudent:: PhdStudent(std::string Name, double fines, double fees, bool FullTime)
{
    name = Name;
    tuition_fees = 0;
    fullTime = FullTime;
    SetLibraryFines(0);
}


double PhdStudent::MoneyOwed() const
{
    return 0.0;
}

/*
int main()
{

    PhdStudent Dog("Anna",20,33,0);

    std::cout << Dog.name << " " << Dog.tuition_fees << "  " << Dog.fullTime << "  " << Dog.GetLibraryFines() << "\n";

    return 0;
}
*/