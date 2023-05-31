#include <iostream>

#include "5_6.h"
#include "5_10.h"
using namespace std;

//we are going to overload the function Multiply, thus allowing it to take various input types such as matrices, vectors and scalars

/*
void Multiply (double ** res, double **A, double **B, int ARows, int ACols, int BRows, int BCols);
void Multiply (double *res, double *A, double **B, int ACols, int BRows, int BCols);
void Multiply (double * res, double **A, double *B, int ARows, int ACols, int BRows) ;
void Multiply (double ** res, double scalar, double **B, int BRows, int BCols) ;
void Multiply (double ** res, double **B, double scalar, int BRows, int BCols) ;
*/


/*
int main ()
{

int am = 2, an = 2, bm = 2, bn = 2, len =2, scalar = 3;

double** A;
double** B;
double** res;
double* x = new double [len];
double* res_vector = new double [am];

A = AllocateMemory(am,an);
B = AllocateMemory(bm,bn);
res = AllocateMemory(am,bn);


A[0][0] = 1; A[0][1] = 2; A[1][0] = 3; A[1][1] = 0;
B[0][0] = 4; B[0][1] = 2; B[1][0] = 1; B[1][1] = 2;
x[0] = 2; x[1] = 3;

Multiply(res,A,B,am,an,bm,bn);

cout << "A = {{1,2},{3,0}} and B = {{4,2},{1,2}} \n";
cout << "AB = " << "{{" << res[0][0] << "," << res[0][1] << "},{" << res[1][0] << "," << res[1][1] << "}} \n";


FreeMemory(am,A);
FreeMemory(bm,B);
FreeMemory(am,res);
delete[] x;
delete[] res_vector;

    return 0;
}
*/

// Matrix-matrix multiplication. Result is written to res
void Multiply ( double **res , double **A, double **B,
int ARows , int ACols , int BRows , int BCols )
{
    //Check that dimensions are consistent
    if (ACols != BRows)
    {
        cout << "Matrix dimensions are not compatible! /n";
    }
    else
    {
        for (int i = 0; i<ARows;i++)
        {
            for (int j = 0; j<BCols; j++)
            {
                res[i][j] = 0; //initialize resulting value of element (i,j)
                for (int k=0; k<ACols; k++)
                {
                    res[i][j] += A[i][k] * B[k][j]; //calculate the value of element (i,j) of the matrix product A*B
                } 
            }
        }
    }
}

//Multiply column vector A (from the left) with matrix B to obtain the result res
void Multiply (double *res, double *A, double **B, 
int ACols, int BRows, int BCols)
{
    //check that dimensions are consistent
    if (ACols != BRows)
    {
        cout << "Matrix dimensions are not compatible! /n";
    }
    else
    {
        for (int j = 0; j<BCols; j++)
        {
            res[j] = 0; //initialize
                for (int k=0; k<ACols; k++)
                {
                    res[j] += A[k] * B[k][j]; //update value of resulting vector
                } 
        }
    }
}

//Multiply matrix A with row vector B to obtain the results res
void Multiply (double * res, double **A, double *B,
int ARows, int ACols, int BRows)
{
    if (ACols != BRows)
    {
        cout << "Matrix dimensions are not compatible! /n";
    }
    else
    {
        for (int i = 0; i<ARows;i++)
        {
            res[i] = 0;
                for (int k=0; k<ACols; k++)
                {
                    res[i] += A[i][k] * B[k];
                } 
        }
    }
}

//Multiply a matrix B with a scalar to obtain the results res
void Multiply (double ** res, double scalar, double **B, int BRows, int BCols)
{
    for (int i = 0; i < BRows; i++)
    {
        for (int j = 0; j<BCols; j++)
        {
            res[i][j] = scalar * B[i][j];
        }
    }
}

//Multiply a matrix B with a scalar to obtain the result res
void Multiply (double ** res, double **B, double scalar, int BRows, int BCols)
{
    Multiply(res,scalar,B,BRows,BCols);
}

