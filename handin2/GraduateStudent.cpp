#include <iostream>
#include <string>

#include "GraduateStudent.hpp"

GraduateStudent:: GraduateStudent() : Student()
{
    fullTime = 1;
    tuition_fees = 0;
}


GraduateStudent:: GraduateStudent(std::string Name, double fines, double fees, bool FullTime)
{
    name = Name;
    tuition_fees = 0;
    fullTime = FullTime;
    SetLibraryFines(fines);
}


double GraduateStudent::MoneyOwed() const
{
    double money_owed = GetLibraryFines(); 
    return money_owed;
}

/*
int main()
{
    GraduateStudent Jim;
    Jim.name = "Jim";
    std::cout << Jim.name << Jim.tuition_fees << "  " << Jim.fullTime << "  " << Jim.GetLibraryFines() << "\n";

    GraduateStudent Dog("Anna",20,33,0);

    std::cout << Dog.name << Dog.tuition_fees << "  " << Dog.fullTime << "  " << Dog.GetLibraryFines() << "\n";

    return 0;
}
*/