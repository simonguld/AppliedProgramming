#ifndef COMPLEXNUMBERHEADERDEF
#define COMPLEXNUMBERHEADERDEF
#include <iostream>

class ComplexNumber
{ 
private :
    double mRealPart;
    double mImaginaryPart;
public :
    ComplexNumber();
    ComplexNumber(double x, double y);
    double CalculateModulus() const;
    double CalculateArgument() const;
    ComplexNumber CalculatePower(double n) const;
    ComplexNumber& operator=(const ComplexNumber& z);
    ComplexNumber operator-() const;
    ComplexNumber operator+(const ComplexNumber& z) const;
    ComplexNumber operator-(const ComplexNumber& z) const;
    friend std :: ostream& operator <<(std :: ostream& output, const ComplexNumber&
    z);

    double GetRealPart() const;
    double GetImaginaryPart() const;
    friend double RealPart(const ComplexNumber& z);
    friend double ImaginaryPart(const ComplexNumber& z);
    ComplexNumber(const ComplexNumber& z);
    ComplexNumber(double real);
    ComplexNumber CalculateConjugate() const;
    void SetConjugate();

    ComplexNumber operator*(const ComplexNumber& z) const;

};
#endif