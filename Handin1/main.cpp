#include <iostream>
#include <cmath>

#include "2_6.h"
#include "3_3.h"
#include "5_3.h"
#include "5_4.h"
#include "5_6.h"
#include "5_9.h"
#include "5_10.h"

using namespace std; 


void test2_6()

{
    double initialGuess = 0.0, tolerance = 1e-10;
    cout << "Problem 2.6: \n";
    cout << "Root = " << newton_Raphson(initialGuess,tolerance) << " with initial guess = " << initialGuess << " and tolerance = " << tolerance << "\n";
    cout << "\n";
}

void test3_3()
{

    cout << "Problem 3.3: We create a data file with 100 grid points \n \n";
    implicit_Euler(100);
}

void test5_3()
{
    double a = 2.0, b=3.0;
    double *p_a, *p_b;
    p_a = &a;
    p_b = &b;

    cout << "Problem 5.3: \n";

    cout << "a = " << a << ",  b = " << b << "\n";

    cout << "After pointer swapping: \n";
    swap_pointer(p_a, p_b);

    cout << "a = " << a << ",  b = " << b << "\n";

    cout << "After an additional reference swapping: \n";
    swap_ref(a,b);

    cout << "a = " << a << ",  b = " << b << "\n \n";
}

void test5_4()
{
 double x [6] = {1,2,9,-1,-2,-3};

    cout << "Problem 5.4: \n";
    
    cout << "Consider the list x = [1,2,9,-1,-2,-3] \n";

    cout << "mean(x) = " << calc_mean(x,6) << "\n";

    cout << "std(x) = " << calc_std(x,6) << "\n \n";

}

void test5_6()
{
    cout << "Problem 5.6: \n";

    int am = 2, an = 2, bm = 2, bn = 2, len =2, scalar = 3;

    double** A;
    double** B;
    double** res;
    //double* x = new double [len];
    //double* res_vector = new double [am];

    A = AllocateMemory(am,an);
    B = AllocateMemory(bm,bn);
    res = AllocateMemory(am,bn);


    A[0][0] = 1; A[0][1] = 2; A[1][0] = 3; A[1][1] = 0;
    B[0][0] = 4; B[0][1] = 2; B[1][0] = 1; B[1][1] = 2;
    //x[0] = 2; x[1] = 3;

    Multiply(res,A,B,am,an,bm,bn);

    cout << "A = {{1,2},{3,0}} and B = {{4,2},{1,2}} \n";
    cout << "AB = " << "{{" << res[0][0] << "," << res[0][1] << "},{" << res[1][0] << "," << res[1][1] << "}} \n";


    FreeMemory(am,A);
    FreeMemory(bm,B);
    FreeMemory(am,res);
    //delete[] x;
    //delete[] res_vector;


    cout << "\n";
}

void test5_9()
{
    cout << "Problem 5.9: \n";

    int len =3;

    double** A;
    A = AllocateMemory(len,len);
    double* x = new double [len];
    double* res_vector = new double [len];

    A[0][0] = 1; A[0][1] = -1; A[0][2] = 2;
    A[1][0] = 3; A[1][1] = -2; A[1][2] = 5;
    A[2][0] = 2; A[2][1] = 2; A[2][2] = -1;

    x[0] = 8; x[1] = -3, x[2] = -3;  

    solve3by3(A,x,res_vector);

    cout << "Solving the system A*res = x \n";
    cout << "A = {{1,-1,2},{3,-2,5},{2,2,-1}} and x = (8,-3,-3) \n";
    cout << "res = (" << res_vector[0] << "," << res_vector[1] << "," << res_vector[2] << ")" << "\n" ;

    FreeMemory(len,A);
    delete[] res_vector;
    delete[] x;

    cout << "\n";
}

void test5_10()
{
    cout << "Problem 5.10: \n";

    int len =4;

    double** A;
    A = AllocateMemory(len,len);
    double* x = new double [len];
    double* res_vector = new double [len];

    A[0][0] = 4; A[0][1] = -3; A[0][2] = 1, A[0][3] = 2;
    A[1][0] = 3; A[1][1] = 1; A[1][2] = -5, A[1][3] = 6;
    A[2][0] = 1; A[2][1] = 1; A[2][2] = 2, A[2][3] = 4;
    A[3][0] = 5; A[3][1] = 1; A[3][2] = 3, A[3][3] = -2;

    x[0] = 4; x[1] = 5, x[2] = 8, x[3] = 7;  

    guassian_elimination(A,x,res_vector,len);

    cout << "Solving the system A*res = x \n";
    cout << "A = {{4,-3,1,2},{3,1,-5,6},{1,1,2,4},{5,1,3,-2}} and x = (4,5,8,7) \n";
    cout << "res = (" << res_vector[0] << "," << res_vector[1] << "," << res_vector[2] << "," << res_vector[3] << ")" << "\n" ;

    FreeMemory(len,A);
    delete[] res_vector;
    delete[] x;

    cout << "\n";
}

int main ()
{
    test2_6();
    test3_3();
    test5_3();
    test5_4();
    test5_6();
    test5_9();
    test5_10();

    return 0;
}