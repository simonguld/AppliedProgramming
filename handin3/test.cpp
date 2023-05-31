#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <string>

#include "Vector.hpp"
#include "Matrix.hpp"
#include "SparseVector.hpp"
#include "LinearSystem.hpp"




int main ()
{

    //Vector test
    #if 0

    //test constructor for vector of given size
    Vector<double> B(4);
    
    std::cout << B[0] << ", " << B[1] << ", " << B[2] << ", " << B[3] << "\n";
    
       
    //test overloaded [] operator
    B[0] = 2; B[1] = 4; B[2]=6; B[3]=8;

    //test read-only version of []
    std::cout << B[0] << ", " << B[1] << ", " << B[2] << ", " << B[3] << "\n";
 
    //test copy-constructor
    Vector<double> C(B);
     std::cout << C[0] << ", " << C[1] << ", " << C[2] << ", " << C[3] << "\n";
    
    
//	int size() const
    std::cout << "Size = " << C.size() << "\n";

	// assignment operator
    Vector<double> D(4);
    D = B;
    std::cout << D[0] << ", " << D[1] << ", " << D[2] << ", " << D[3] << "\n";


    // overloading the unary - operator
	Vector<double> E(4);
    E = -B;
    std::cout << E[0] << ", " << E[1] << ", " << E[2] << ", " << E[3] << "\n";

    // overloading the binary +/- operators
    Vector<double> F(4);
    Vector<double> G(4);
    F = B+B;
    G = B-B;
    std::cout << F[0] << ", " << F[1] << ", " << F[2] << ", " << F[3] << "\n";
    std::cout << G[0] << ", " << G[1] << ", " << G[2] << ", " << G[3] << "\n";

	// scalar multiplication
    Vector<double> H(4);
    double a=3;
    H=B*a;
    std::cout << H[0] << ", " << H[1] << ", " << H[2] << ", " << H[3] << "\n";

    //get storage
    
    //the vector reference must be const.
    const std::vector<double> &I = H.getStorage();
    // I[0]=2; will generate an error, as H is kept const

    //check values are the same
    std::cout << I[0] << ", " << I[1] << ", " << I[2] << ", " << I[3] << "\n";

    //check addresses are the same
    std::cout << &H << "\n";
   std::cout << &I << "\n";
    
    
    //p-norm
    std::cout << B.CalculateNorm() << "\n";
#endif

//Matrix test

#if 1
    //constructor Matrix<T>(int numRows, int numCols)
    Matrix<double> A (2,2);



    //T(i,j) overloading with constant and change
	// overloaded assignment operator
    A(0,0) = 2; A(0,1) = 4; A(1,0) = 6; A(1,1)=8;

    std::cout << A(0,0) << ", " << A(0,1) << ", " << A(1,0) << ", " << A(1,1) << "\n";

    //copy constructor
    Matrix<double> B (A);

    std::cout << B(0,0) << ", " << B(0,1) << ", " << B(1,0) << ", " << B(1,1) << "\n";

	//int GetNumberOfRows() const
	//int GetNumberOfColumns() const
    std::cout << A.GetNumberOfRows() << ",  " << A.GetNumberOfColumns() << "\n";

    //assignment 
    Matrix <double> C (2,2);
    C = A;
    
    std::cout << C(0,0) << ", " << C(0,1) << ", " << C(1,0) << ", " << C(1,1) << "\n";


 // unary -
    Matrix <double> D (2,2);
    D = -A;
    std::cout << D(0,0) << ", " << D(0,1) << ", " << D(1,0) << ", " << D(1,1) << "\n";


 // binary +/-
    Matrix <double> E (2,2);
    E = A+A;
    std::cout << E(0,0) << ", " << E(0,1) << ", " << E(1,0) << ", " << E(1,1) << "\n";

    Matrix <double> F (2,2);
    F = A-A;
    std::cout << F(0,0) << ", " << F(0,1) << ", " << F(1,0) << ", " << F(1,1) << "\n";


	// scalar multiplication A*a
    Matrix <double> G (2,2);
    double a=3;
    G = A*a;
    
    std::cout << G(0,0) << ", " << G(0,1) << ", " << G(1,0) << ", " << G(1,1) << "\n";

    //get storage
    
    //the vector reference must be const.
    const std::vector<double> &I = G.getStorage();
    // I[0]=2; will generate an error, as H is kept const

    //check values are the same
    std::cout << I[0] << ", " << I[1] << ", " << I[2] << ", " << I[3] << "\n";

    //check addresses are the same
    std::cout << &G << "\n";
    std::cout << &I << "\n";
    


//matrix-vector multiplications v*A and A*v
    Vector<double> v (2);
    Vector<double> w (2);
    Vector<double> u (2);

    v[0]=2;v[1]=2;

    w = A*v;
    u = v*A;
    std::cout << w[0] << ", " << w[1] << "\n";
     std::cout << u[0] << ", " << u[1] << "\n";
 
 #endif


#if 0
//Sparse Vector test

//Default constructor, creates empty vector
SparseVector<double> A;

//Constructor making vector of dim 2
SparseVector<double> B (20);

//integrated copy constructor + capacity of 20%
SparseVector<double> C (B);
std::cout << C.nonZeroes() << "\n";

//integrated assignment operator 
A = B;

//set value
A.setValue(0,2); A.setValue(1,3); A.setValue(2,12); A.setValue(3,9); A.setValue(4,21); A.setValue(9,-1); A.setValue(13,19);


//get value
std::cout << A.getValue(0) << ",  " << A.getValue(1) << ", " << A.getValue(2) << ",  " << A.getValue(3) << ", " << A.getValue(4);
std::cout << ",  " << A.getValue(9) << ",  " << A.getValue(13) << " \n";


std::cout << A.size() << ",  " << A.nonZeroes() << "\n";

//test indexNonZero -> returns index of i'th non-zero elements 
std::cout << A.indexNonZero(3) << "\n";

//test valueNonZero --> returns value of i'th non-zero element
std::cout << A.valueNonZero(3) << "\n";

//add a vector x by overloading +=

//set values of C
C.setValue(1,1); C.setValue(5,3); //C.setValue(2,-3); C.setValue(4,1);
std::cout << C.getValue(0) << "\n";

A += C;
std::cout << A.getValue(0) << "\n";
//get value
std::cout << A.getValue(0) << ",  " << A.getValue(1) << ", " << A.getValue(2) << ", " << A.getValue(5) << "\n";
std::cout << A.nonZeroes() << "\n";

// substract a vector x by overloading -=

A -= C;
std::cout << A.getValue(0) << ",  " << A.getValue(1) << ", " << A.getValue(2) << ", " << A.getValue(5) << "\n";

//overloading + operator
SparseVector<double> D(20);
D = A + A;
std::cout << D.getValue(0) << ",  " << D.getValue(1) << ", " << D.getValue(2) << ", " << D.getValue(5) << "\n";

//overloading - operator
SparseVector<double> E(20);
E = A-A;
std::cout << E.getValue(0) << ",  " << E.getValue(1) << ", " << E.getValue(2) << ", " << E.getValue(5) << "\n";

// computes the matrix-vector product of a dense matrix and sparse vector z=Ax.
// The result is a dense vector.
Vector<double> v (3);
Matrix<double> F (3,3);
SparseVector<double> G (3);
G.setValue(0,2); G.setValue(1,1);

F(0,0) = 1; F(0,1) = 3; F(0,2) = 5;
F(1,0) = 2; F(1,1) = 2; F(1,2) = -1;
F(2,0) = 1; F(2,1) = 0; F(2,2) = 2;

v = F*G;
std::cout << v[0] << ", " << v[1] << ", " << v[2] << "\n";

// computes the matrix-vector product of a dense matrix and sparse vector z=x^TA.
// The result is a dense vector.
Vector<double> w (3);
w = G*F;
std::cout << w[0] << ", " << w[1] << ", " << w[2] << "\n";
#endif

#if 1

LinearSystem<double> linSyst (A, v);

#endif


    return 0;
}