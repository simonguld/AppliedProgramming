#include <iostream>
#include <cmath>

#include "Matrix2x2.hpp"


Matrix2x2& Matrix2x2::operator=(const Matrix2x2& z)
{
    
    val00 = z.val00;
    val01 = z.val01;
    val10 = z.val10;
    val11 = z.val11;
    
    return *this;
}


Matrix2x2 Matrix2x2::operator-() const
{
    Matrix2x2 A;
    A.val00 = - val00;
    A.val01 = - val01;
    A.val10 = - val10;
    A.val11 = - val11;
    return A;
}


Matrix2x2 Matrix2x2::operator+(const Matrix2x2& z) const
{ 
    Matrix2x2 A;
    A.val00 = val00 + z.val00;
    A.val01 = val01 + z.val01;
    A.val10 = val10 + z.val10;
    A.val11 = val11 + z.val11;
    return A;
}


Matrix2x2 Matrix2x2::operator-(const Matrix2x2& z) const
{
    Matrix2x2 A;
    A.val00 = val00 - z.val00;
    A.val01 = val01 - z.val01;
    A.val10 = val10 - z.val10;
    A.val11 = val11 - z.val11;
    return A;

}



void Matrix2x2::MultScalar(double scalar)
{
    val00 = val00*scalar;
    val01 = val01*scalar;
    val10 = val10*scalar;
    val11 = val11*scalar;
}


Matrix2x2::Matrix2x2()
{
    val00 = 0, val01 = 0, val10 = 0, val11 = 0;
}

Matrix2x2::Matrix2x2(const Matrix2x2& other)
{
    val00 = other.Getval00();
    val01 = other.Getval01();
    val10 = other.Getval10();
    val11 = other.Getval11();
}
        
Matrix2x2::Matrix2x2(double a,double b,double c,double d)
{
    val00 = a;
    val01 = b;
    val10 = c;
    val11 = d; 
}


double Matrix2x2::CalcDeterminant() const
{
    return val00*val11 - val10*val01;
}


Matrix2x2 Matrix2x2::CalcInverse() const
{
        double determinant = CalcDeterminant();
        if (determinant == 0)
        {
            std::cout << "Matrix singular! \n";
            Matrix2x2 undefined(NAN,NAN,NAN,NAN);
            return undefined;
        }
        else
        {
            //Using the formula   inverse(A) = 1/det(A) * adjoint (A)

            Matrix2x2 adjoint(val11,-val01,-val10,val00);

            adjoint.MultScalar(1/determinant);
            return adjoint;
        }
}

/*

int main ()
    {
        int len = 2;

        Matrix2x2 A(2,1,4,3);

        std::cout << A.Getval00() << "\n";

        Matrix2x2 B;

        std::cout << B.Getval01() << "\n";


        Matrix2x2 C(A);
        C.MultScalar(2);
        std::cout << C.Getval00() << "\n";
           std::cout << C.Getval01() << "\n";
              std::cout << C.Getval10() << "\n";
                 std::cout << C.Getval11() << "\n";

        std::cout << C.CalcDeterminant() << "\n";
        std::cout << "\n \n";

        Matrix2x2 invA;

        invA = A.CalcInverse();

      std::cout << invA.Getval00() << "\n";
           std::cout << invA.Getval01() << "\n";
              std::cout << invA.Getval10() << "\n";
                 std::cout << invA.Getval11() << "\n";
        Matrix2x2 E;
        E = -A;
    
         std::cout << E.Getval00() << "\n";
           std::cout << E.Getval01() << "\n";
              std::cout << E.Getval10() << "\n";
                 std::cout << E.Getval11() << "\n";


        Matrix2x2 F;
        F = A-E;

              std::cout << F.Getval00() << "\n";
           std::cout << F.Getval01() << "\n";
              std::cout << F.Getval10() << "\n";
                 std::cout << F.Getval11() << "\n";
        return 0;
    }


*/