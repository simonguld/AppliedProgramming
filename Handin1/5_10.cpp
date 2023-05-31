#include <iostream>
#include <cmath>

#include "5_10.h"

using namespace std;

//We are going to implement a module that solves the 3x3 equation Au=b, where A is invertible
//In particular, we are going to rewrite the input matrix A to an upper triangular form - using pivoting if needed -
// followed by a backward substitution to obtain the result.

double** AllocateMemory (int numRows, int numCols);
void FreeMemory (int numRows, double** matrix);

void backwards_substitution (double** B, double* b, double* u, int n);
void upper_triang (double **A, double** B, double *b , double *u, int n);
void swap_rows (double** B, double* b, int i, int k, int n);


/*
int main()
{

int len =4;

double** A;
A = AllocateMemory(len,len);
double* x = new double [len];
double* res_vector = new double [len];




A[0][0] = 0; A[0][1] = -2; A[0][2] = 1, A[0][3] = 2;
A[1][0] = 2; A[1][1] = 0; A[1][2] = -5, A[1][3] = 6;
A[2][0] = 1; A[2][1] = 1; A[2][2] = 2, A[2][3] = 4;
A[3][0] = 5; A[3][1] = 1; A[3][2] = 3, A[3][3] = -2;

x[0] = 4; x[1] = 5, x[2] = 8, x[3] = 7;  

guassian_elimination(A,x,res_vector,len);

cout << "Solving the system A*res = x \n";
cout << "A = {{4,-3,1,2},{3,1,-5,6},{1,1,2,4},{5,1,3,-2}} and x = {4,5,8,7} \n";
cout << "res = (" << res_vector[0] << "," << res_vector[1] << "," << res_vector[2] << "," << res_vector[3] << ")" << "\n" ;

FreeMemory(len,A);
delete[] res_vector;
delete[] x;

    return 0;
} 
*/

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



    guassian_elimination(A,x,res_vector,3);

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

void guassian_elimination (double **A, double *b , double *u, int n)
{
    //define a temporary copy of A to avoid altering the values of A
    double** B;  
    B = AllocateMemory(n,n);

    //Get B on an upper triangular form. The right hand side of this equation is written to u
    upper_triang(A,B,b,u,n);

    //Solve the upper triangular system Bx=u by backwards substitution and write the result to u
    backwards_substitution(B,u,u,n);
    FreeMemory(n,B);
}

void backwards_substitution (double** B, double* b, double* u, int n)
{
    //carry out backwards substitution algorithm
    for (int k=n-1; k>-1; k--)
    {
        u[k] = b[k];
        for (int j = n-1; j>k; j-- )
        {
            u[k] -= B[k][j] * u[j];
        }
        u[k] /= B[k][k];
    }
}

void upper_triang (double **A, double** B, double *b , double *u, int n)

{
    double diag1=0,diag2=0; //store values of diagonal elements in separate values to avoid overwriting in for loops.

    //Copy the values of A and b to B and u to avoid altering them outside the function
    for (int i=0; i<n; i++)
    {
        u[i] = b[i];
        for (int j = 0; j<n; j++)
        {
            B[i][j] = A[i][j];
        }
    }

    for (int i=0;i<n;i++)
    {
        double threshold = 0.01;
        //if diagonal element is smaller than threshold, perform pivoting
        if (fabs(B[i][i])<=threshold)
        {
            for (int j=i; j<n; j++)
                {
                    //continue until a sufficiently large diagonal element is found
                    if (fabs(B[j][i])>0.01)
                    {
                        //swap the rows i and j in matrix B and vector u
                        swap_rows(B,u,i,j,n);
                        break; //break out of for-loop when pivoting has been completed
                    }
                }
        }
            diag1 = B[i][i];
            //update values of the i'th row of u and B
            u[i] = u[i] / diag1;
            for (int j=i; j<n; j++)
             {
            
                B[i][j] = B[i][j]/diag1;  
            }
            for (int k = i+1; k<n; k++)
            {
                  diag2 = B[k][i]; //store value in separate variable to avoid overwriting it

                  //update value of row k in u and B
                    u[k] -= u[i]*diag2;
                    for (int j = i; j<n; j++)
                    {
                        B[k][j] -= diag2*B[i][j]; 
                    }
            }
        
    }

}


void swap_rows (double** B, double* b, int i, int k, int n)
{
    //swap rows m and n in matrix B and vector b
    swap(b[i],b[k]);
    for (int j=0; j<n; j++)
    {
        swap(B[i][j],B[k][j]);
    }

}


//Allocates matrix memory dynamically to a matrix with numRows rows and numCols columns
double** AllocateMemory (int numRows, int numCols)
{
    double** matrix;
    matrix = new double* [numRows];
    for (int i=0; i<numRows; i++)
    {
        matrix[i] = new double [numCols];
    }
    return matrix;
}

//Frees matrix memory of a dynamically allocated matrix with numRows rows
void FreeMemory (int numRows, double** matrix)
{
    for (int i = 0; i<numRows; i++)
    {
        delete[] matrix [i];
    }
    delete[] matrix;
}