#include <iostream>
#include <cmath>
#include <string>
#include <cassert>

#include "Student.hpp"

Student::Student()
{
    name = "Unspecified";
    tuition_fees = 0;
    library_fines = 0;
}

Student::Student(std::string Name, double fines, double fees)
{
    name = Name;
    tuition_fees=fees;
    SetLibraryFines(fines);

}


double Student::MoneyOwed() const
{
    return tuition_fees + library_fines;
}


void Student::SetLibraryFines (double amount)
{
    if (amount<0)
    {
        std::cout << "Library fines must be non-negative! \n";
        std::cout << "Enter a positive number for the library fines followed by enter \n";
        std::cin >> library_fines;
    }
    else
    {
        library_fines = amount;
    }    
}

double Student::GetLibraryFines () const
{
    return library_fines;
}



/*
int main ()
{

Student B; 
B.name = "Bjarne";
B.tuition_fees = 32;
B.SetLibraryFines(20);
std::cout << B.name << " " << B.tuition_fees << "\n";

Student A(B);

std::cout << A.name << " " << A.tuition_fees << "\n";

std::cout << A.MoneyOwed() << "\n";
std::cout << A.GetLibraryFines() << "\n";

Student C("Niels",-11,22);

std::cout << C.name << " " << C.tuition_fees << " " << C.GetLibraryFines() << " " << C.MoneyOwed() << "\n";

    return 0;
}
*/