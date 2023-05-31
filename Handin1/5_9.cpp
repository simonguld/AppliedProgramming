#include <iostream>

#include "5_9.h"
#include "5_10.h"

using namespace std;

/*
int main ()
{
    int len =3;

    double** A;
    A = AllocateMemory(len,len);
    double* x = new double [len];
    double* res_vector = new double [len];

    A[0][0] = 0; A[0][1] = -2; A[0][2] = 1;
    A[1][0] = 0; A[1][1] = -5; A[1][2] = 6;
    A[2][0] = 1; A[2][1] = 1; A[2][2] = 2;

    x[0] = 5; x[1] = 8, x[2] = 7;  

    solve3by3(A,x,res_vector);

    cout << "Solving the system A*res = x \n";
    cout << "A = {{1,-1,2},{3,-2,5},{2,2,-1}} and x = (8,-3,-3) \n";
    cout << "res = (" << res_vector[0] << "," << res_vector[1] << "," << res_vector[2] << ")" << "\n" ;

    FreeMemory(len,A);
    delete[] res_vector;
    delete[] x;




    return 0;
}
*/


//module that solves a nonsingular 3x3 matrix equation
void solve3by3 (double **A, double *b , double *u)
{
    guassian_elimination(A,b,u,3);
}
