#include <iostream>

#include "ComplexNumber.hpp"

ComplexNumber::ComplexNumber()
{
    mRealPart = 0.0;
    mImaginaryPart = 0.0;
}

ComplexNumber::ComplexNumber(double x, double y)
{
    mRealPart = x;
    mImaginaryPart = y;
}

ComplexNumber& ComplexNumber::operator=(const ComplexNumber& z)
{
    mRealPart = z.mRealPart;
    mImaginaryPart = z.mImaginaryPart;
    return *this;
}

// Overloading the unary - operator
ComplexNumber ComplexNumber::operator-() const
{
    ComplexNumber w;
    w.mRealPart = -mRealPart;
    w.mImaginaryPart = -mImaginaryPart;
    return w;
}

// Overloading the binary + operator
ComplexNumber ComplexNumber::operator+(const ComplexNumber& z) const
{
    ComplexNumber w;
    w.mRealPart = mRealPart + z.mRealPart;
    w.mImaginaryPart = mImaginaryPart + z.mImaginaryPart;
    return w;
}

// Overloading the binary - operator
ComplexNumber ComplexNumber::operator-(const ComplexNumber& z) const
{
ComplexNumber w;
w.mRealPart = mRealPart - z.mRealPart;
w.mImaginaryPart = mImaginaryPart - z.mImaginaryPart;
return w;
}


// Overloading the multiplication operator
ComplexNumber ComplexNumber::operator*(const ComplexNumber& z) const
{
ComplexNumber w;
w.mRealPart = mRealPart*z.mRealPart-mImaginaryPart*z.mImaginaryPart;
w.mImaginaryPart = mRealPart*z.mImaginaryPart + mImaginaryPart*z.mRealPart;
return w;
}

/*
// Overloading the insertion << operator
std::ostream& operator<<(std::ostream& output,const ComplexNumber& z)
{
    // Format as "(a + bi)" or as "(a - bi)"
    output << "(" << z.mRealPart << " ";
    if (z.mImaginaryPart >= 0.0)
    {
        output << "+ " << z.mImaginaryPart << "i)";
    }
    else
    {
        // z.mImaginaryPart < 0.0
        // Replace + with minus sign
        output << "- " << -z.mImaginaryPart << "i)";
    }
}
*/

double ComplexNumber::GetRealPart() const
{
    return mRealPart;
}

double ComplexNumber::GetImaginaryPart() const
{
    return mImaginaryPart;
}

double RealPart(const ComplexNumber& z)
{
    return z.mRealPart;
}

double ImaginaryPart(const ComplexNumber& z)
{
    return z.mImaginaryPart;
}

ComplexNumber::ComplexNumber(const ComplexNumber& z)
{
    mRealPart = z.mRealPart;
    mImaginaryPart = z.mImaginaryPart;
}

ComplexNumber::ComplexNumber(double real)
{
    mRealPart = real;
    mImaginaryPart = 0;
}

ComplexNumber ComplexNumber::CalculateConjugate() const
{
    ComplexNumber z_conj (mRealPart,-mImaginaryPart);
    return z_conj;
}

void ComplexNumber::SetConjugate()
{
    mRealPart = mRealPart;
    mImaginaryPart = - mImaginaryPart;
}

/*
int main ()
{
    ComplexNumber z1(2,3);
    std::cout << "Re(z1) = " <<  z1.GetRealPart() << " Im(z1) = " << z1.GetImaginaryPart() << "\n"; 
    std::cout << "Re(z1) = " <<  RealPart(z1) << " Im(z1) = " << ImaginaryPart(z1) << "\n"; 

    ComplexNumber z2(z1);
    std::cout << "Re(z2) = " <<  z2.GetRealPart() << " Im(z2) = " << z2.GetImaginaryPart() << "\n";

    ComplexNumber z3(4);
    std::cout << "Re(z3) = " <<  z3.GetRealPart() << " Im(z3) = " << z3.GetImaginaryPart() << "\n"; 

    ComplexNumber z1c;
    z1c = z1.CalculateConjugate();
     std::cout << "Re(z1c) = " <<  z1c.GetRealPart() << " Im(z4) = " << z1c.GetImaginaryPart() << "\n";
     
    z1.SetConjugate();
    std::cout << "Re(z1c) = " <<  z1.GetRealPart() << " Im(z1c) = " << z1.GetImaginaryPart() << "\n"; 

    ComplexNumber zprod;
    zprod = z1*z2;
     std::cout << "Re(zprod) = " <<  zprod.GetRealPart() << " Im(zprod) = " << zprod.GetImaginaryPart() << "\n"; 

    return 0;
}
*/