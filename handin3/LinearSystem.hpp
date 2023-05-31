#ifndef LIN_SYS_
#define LIN_SYS_

#include <cassert>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iostream>

#include "Vector.hpp"
#include "Matrix.hpp"


//Expand so as to handle Ax=b and xA=b

template <class T> class LinearSystem
{
    private:
        Matrix<T> mMat; // entries of matrix
        Vector<T> mVec; //entries of left hand vector
	    int mNumRows, mNumCols; // dimensions

        LinearSystem<T> (double rows, double cols, Matrix<T>  matrix, Vector<T> vector)
        {
            
        }

    
    public:

        LinearSystem<T> (Matrix<T>  matrix, Vector<T> vector)
        {
            mNumRows = matrix.GetNumberOfRows();
            mNumCols = matrix.GetNumberOfColumns();

            mVec = vector;
            mMat = matrix;
        }
        




       // std::vector<T> Solve(); 



};


#endif