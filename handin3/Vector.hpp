#ifndef VECTORHEADERDEF
#define VECTORHEADERDEF

#include <cassert>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iostream>



template <class T> 
class Vector
{
private:
	std::vector<T> mData; // data stored in vector
	int mSize; // size of vector

public:

	Vector<T>(int size)
    {
        assert(size > 0);

        mSize = size;
        mData.assign(mSize,0);        
    }
    

	int size() const
    {
        return mSize;
    }
   
	T& operator[](int i)
    {
        assert(i >= 0 && i < mSize);
     
        return mData[i];
    }
    
	T const& operator[] (int i) const
    {
        assert(i >= 0 && i < mSize);
        return mData[i];
    }
   

    // overloading the unary - operator
	Vector<T> operator-() const
    {
        Vector<T> v(mSize);
        for (int i = 0; i < mSize; i++)
        {
            v[i] = -mData[i];
        }
        return v;
    }

    // overloading the binary + operator
	Vector<T> operator+(const Vector& v1) const
    {
        assert(mSize == v1.mSize);

        Vector<T> v(mSize);
        for (int i = 0; i < mSize; i++)
        {
            v[i] = mData[i] + v1.mData[i];
        }
        return v;
    }

    // overloading the binary - operator
	Vector<T> operator-(const Vector& v1) const
    {
        assert(mSize == v1.mSize);

        Vector<T> v(mSize);
        for (int i = 0; i < mSize; i++)
        {
            v[i] = mData[i] - v1.mData[i];
        }
        return v;
    }

	// scalar multiplication
	Vector<T> operator*(double a) const
    {
        Vector<T> v(mSize);
        for (int i = 0; i < mSize; i++)
        {
            v[i] = a*mData[i];
        }
        return v;
    }

    //get const. reference to mData
    std::vector<T> const& getStorage() const
    {
        return mData;
    }

	// p-norm method
	double CalculateNorm(int p = 2) const
    {
        double sum = 0.0;
        for (int i = 0; i < mSize; i++)
        {
            sum += pow(std::abs(mData[i]), p);
        }
        return pow(sum, 1.0 / ((double)(p)));
    }
};


#endif


