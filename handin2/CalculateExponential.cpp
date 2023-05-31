#include <iostream>

#include "CalculateExponential.hpp"


//Allocates matrix memory dynamically to a matrix with numRows rows and numCols columns
ComplexNumber** AllocateMemory (int numRows, int numCols)
{
    ComplexNumber** matrix;
    matrix = new ComplexNumber* [numRows];
    for (int i=0; i<numRows; i++)
    {
        matrix[i] = new ComplexNumber [numCols];
    }
    return matrix;
}

//Frees matrix memory of a dynamically allocated matrix with numRows rows
void FreeMemory (int numRows, ComplexNumber** matrix)
{
    for (int i = 0; i<numRows; i++)
    {
        delete[] matrix [i];
    }
    delete[] matrix;
}

double Factorial(int n)
{
    if (n==0)
    {
        return 1;
    }
    else
    {
        return n*Factorial(n-1);
    }
}

// Matrix-matrix multiplication. Result is written to res
void Multiply (ComplexNumber **res ,ComplexNumber **A,ComplexNumber **B,
int ARows , int ACols , int BRows , int BCols )
{
    //Check that dimensions are consistent
    if (ACols != BRows)
    {
        std::cout << "Matrix dimensions are not compatible! /n";
    }
    else
    {
        for (int i = 0; i<ARows;i++)
        {
            for (int j = 0; j<BCols; j++)
            {
               res[i][j] = ComplexNumber(0,0); //initialize resulting value of element (i,j)
                //std::cout << "res" << i << j << "= " << res[i][j].GetRealPart() << " " << res[i][j].GetImaginaryPart() << "\n";
                for (int k=0; k<ACols; k++)
                {
                    res[i][j] = res[i][j] + A[i][k] * B[k][j]; //calculate the value of element (i,j) of the matrix product A*B
                } 
            }
        }
    }
}

void CalculateExponential(ComplexNumber **A, int nMax, ComplexNumber **res)
{
    int len = 3;
    ComplexNumber** Bold;
    ComplexNumber** Bnew;
    Bold = AllocateMemory(len,len);
    Bnew = AllocateMemory(len,len);

    for (int i = 0; i<len; i++)
    {
        for (int j = 0; j<len; j++)
        {
            if (i==j)
            {
                res[i][j] = ComplexNumber(1);
                Bnew[i][j] = A[i][j];
            }
            else
            {
                res[i][j] = ComplexNumber(0);
                Bnew[i][j] = A[i][j];
            }
        }
    }

    for (int i = 0; i<nMax; i++)
    {
        double scalar = 1/Factorial(i+1);
        //std::cout << "scal = " << scalar << "\n";
        ComplexNumber complex_scalar(scalar,0);

       // std::cout << "comp_s = " << complex_scalar.GetRealPart() << " " << complex_scalar.GetImaginaryPart() << "\n";
          for (int k = 0; k<len; k++)
        {
            for (int j = 0; j<len; j++)
            {
                ComplexNumber res_temp;
                res_temp =  complex_scalar* Bnew[k][j];
               // std::cout << "res_t = " << res_temp.GetRealPart() << " " << res_temp.GetImaginaryPart() << "\n";
                //std::cout << "B" << k << j << "= " <<  Bnew[k][j].GetRealPart() << " " <<  Bnew[k][j].GetImaginaryPart() << "\n";
                res[k][j] = res[k][j] + res_temp;
                Bold[k][j] = Bnew[k][j];
            }
        }

        Multiply(Bnew,Bold,A,len,len,len,len);
    }
    FreeMemory(len,Bold);
    FreeMemory(len,Bnew);
}



/*

int main ()
{
    ComplexNumber** A;
    ComplexNumber** res;
    //ComplexNumber** res2;
    int n=3;

    A = AllocateMemory(n,n);
    res = AllocateMemory(n,n);
    //res2 = AllocateMemory(n,n);
    A[0][0] = ComplexNumber(2,3), A[0][1] = ComplexNumber(1,0), A[0][2] = ComplexNumber(2,1);
    A[1][0] = ComplexNumber(2,1), A[1][1] = ComplexNumber(4,-1), A[1][2] = ComplexNumber(-3,-0.5);
    A[2][0] = ComplexNumber(3,-2), A[2][1] = ComplexNumber(2,1), A[2][2] = ComplexNumber(0,1);

    

    CalculateExponential(A,10,res);
    
    std::cout << "res = \n {{(" <<  res[0][0].GetRealPart() << ", " << res[0][0].GetImaginaryPart() << "), (";
    std::cout <<  res[0][1].GetRealPart() << ", " << res[0][1].GetImaginaryPart() << "), (";
    std::cout <<  res[0][2].GetRealPart() << ", " << res[0][2].GetImaginaryPart() << ")}, \n";

    std::cout << "{(" <<  res[1][0].GetRealPart() << ", " << res[1][0].GetImaginaryPart() << "), (";
    std::cout <<  res[1][1].GetRealPart() << ", " << res[1][1].GetImaginaryPart() << "), (";
    std::cout <<  res[1][2].GetRealPart() << ", " << res[1][2].GetImaginaryPart() << ")}, \n";
    std::cout << "{(" <<  res[2][0].GetRealPart() << ", " << res[2][0].GetImaginaryPart() << "), (";
    std::cout <<  res[2][1].GetRealPart() << ", " << res[2][1].GetImaginaryPart() << "), (";
    std::cout <<  res[2][2].GetRealPart() << ", " << res[2][2].GetImaginaryPart() << ")}}, \n" ;



    FreeMemory(n,A);
    FreeMemory(n,res);

    return 0;
}

*/