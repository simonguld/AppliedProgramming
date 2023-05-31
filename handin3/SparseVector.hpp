#ifndef SPARSE_VECTOR_HPP
#define SPARSE_VECTOR_HPP

#include <cassert>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>

#include "Vector.hpp"
#include "Matrix.hpp"





template<typename T> class SparseVector{
private:
	int mDim;
//	double mDenseFraction = 0.2; //fraction of vector elements assumed to be non-zero
	std::vector<T> mIndex;
	std::vector<T> mVal;

public:
	//creates an empty vector of dimensionality 0.
	SparseVector()
	{
		mDim=0;
		mIndex.assign(mDim,0);
		mVal.assign(mDim,0);
	}
	// Creates a vector of dimensionality dim. It starts with 0 nonzero elements
	// which need to be set using setValue
	SparseVector(unsigned int dim)
	{
		mDim=dim;
		int capacity;
	//	capacity = round(mDenseFraction*mDim+0.5);
		capacity = 0;
		mIndex.assign(capacity,0);
		mVal.assign(capacity,0);
	}	

	// assignment operators and copy constructor should be automatically
	// generated by the compiler when using a std::vector for internal storing.
	// However, test that assignment works!

	//sets the value v_i of the vector. if it does not exist it is added
	void setValue(unsigned int index, T value)
	{
		typename std::vector<T>::const_iterator it;
		it = find(mIndex.begin(),mIndex.end(),index);
		if (it != mIndex.end())
		{
			mVal[it-mIndex.begin()] = value;
		}
		else
		{
			typename std::vector<T>::const_iterator it2;
			it2 = lower_bound(mIndex.begin(),mIndex.end(),index);
			int ind = it2-mIndex.begin();
			if (it2 != mIndex.end())
			{	
				mIndex.insert(it2,index);
				mVal.insert(mVal.begin()+ind,value);
			}
			else
			{
				mIndex.push_back(index);
				mVal.push_back(value);
			}

		}
	}

	//returns the value v_i of the vector. Returns 0 if the value is not stored in lokationbyo
	T getValue(unsigned int index) const
	{
		typename std::vector<T>::const_iterator it;
		it = find(mIndex.begin(),mIndex.end(),index);
		if (it != mIndex.end())
		{
			return mVal[it-mIndex.begin()];
		}
		else
		{
			return 0;
		}
	}

	//returns the dimensionality of the vector
	unsigned int size() const
	{
		return mDim;
	}

	// returns the number stored elements
	unsigned int nonZeroes() const
	{
		return mVal.size();
	}

	//returns the index of the ith stored nonzero entry (in increasing order)
	unsigned int indexNonZero(unsigned int i) const
	{
		return mIndex[i];
	}

	//returns the value of the ith stored nonzero entry (in increasing order)
	T valueNonZero(unsigned int i) const
	{
		return mVal[i];
	}

	//adds x too the current vector
	SparseVector<T>& operator+= (SparseVector<T> const& x)
	{
		assert(size()==x.size());

		for (typename std::vector<T>::const_iterator it = x.mIndex.begin(); it != x.mIndex.end(); it++)
		{
			typename std::vector<T>::const_iterator it2 = find(mIndex.begin(),mIndex.end(),*it);
			if (it2 != mIndex.end())
			{
				mVal[it2-mIndex.begin()] += x.mVal[it-x.mIndex.begin()];

			}
			else
			{
				setValue(*it,x.mVal[it-x.mIndex.begin()]);
			}
		}
		//return v;
		return *this;
	}

	//subtracts x from the current vector
	SparseVector<T>& operator-= (SparseVector<T> const& x)
	{
		assert(size()==x.size());

		for (typename std::vector<T>::const_iterator it = x.mIndex.begin(); it != x.mIndex.end(); it++)
		{
			typename std::vector<T>::const_iterator it2 = find(mIndex.begin(),mIndex.end(),*it);
			if (it2 != mIndex.end())
			{
				mVal[it2-mIndex.begin()] -= x.mVal[it-x.mIndex.begin()];

			}
			else
			{
					setValue(*it,-x.mVal[it-x.mIndex.begin()]);	
			}
		}
		//return v;
		return *this;
	}
};


// computes z= x+y, equivalent to z=x, z+=y
template<class T>
SparseVector<T> operator+(SparseVector<T> const& x, SparseVector<T> const& y)
{
	SparseVector<T> z (x);
	z += y;
	return z;
}

// computes z= x-y, equivalent to z=x, z-=y
template<class T>
SparseVector<T> operator-(SparseVector<T> const& x, SparseVector<T> const& y)
{
		SparseVector<T> z (x);
	z -= y;
	return z;
}


// computes the matrix-vector product of a dense matrix and sparse vector z=Ax.
// The result is a dense vector.
template<class T>
Vector<T> operator* (Matrix<T> const& A, SparseVector<T> const& x)
{
	assert(x.size() == A.GetNumberOfColumns());

	int dim = A.GetNumberOfRows();
	Vector<T> v (dim);

	typename std::vector<T>::const_iterator it;
	for (int i = 0; i<dim; i++)
	{
		int non_zeroes = x.nonZeroes();
		for (int j = 0; j<non_zeroes; j++)
		{
			v[i] += A(i,x.indexNonZero(j)) * x.valueNonZero(j);
		}
	}
	return v;
}

// computes the matrix-vector product of a dense matrix and sparse vector z=x^TA.
// The result is a dense vector.
template<class T>
Vector<T> operator* (SparseVector<T> const& x, Matrix<T> const& A)
{
	assert (x.size() == A.GetNumberOfRows());
	int dim = A.GetNumberOfColumns();
	Vector<T> v (dim);

	for (int i = 0; i<dim; i++)
	{
		int non_zeroes = x.nonZeroes();
		for (int j=0; j<non_zeroes; j++)
		{
			v[i] += A(x.indexNonZero(j),i)*x.valueNonZero(j);
		}
	}
	return v;
}
#endif