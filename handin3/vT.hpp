#ifndef VECTORHEADERDEF_
#define VECTORHEADERDEF_

#include <cassert>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iostream>



template <class T> 
class Vectorz
{
private:

	std::vector<T> mVec; // data stored in vector
	int mSize; // size of vector

public:

Vectorz<T>(int size)
    {
        assert(size > 0);

        mSize = size;
        //std::vector<T>::data mVec;

        mVec.assign(mSize,0);
        //std::vector<T> mVec (size,0);
        std::cout << &mVec << "\n";
       // mVec = new std::vector<T> (size,0);
        
        for (int i = 0; i < mSize; i++)
        {
            mVec[i] = 0.0;
        }
          std::cout << mVec[1] << "\n";
        
        
    }
    

    /*
	~Vector<T>()
    {
        delete[] mVec;
    }
    */

	int size() const
    {
        return mSize;
    }
   
	T& operator[](int i)
    {
        assert(i >= 0 && i < mSize);
     
        return mVec[i];
       // return mSize
    }
    
	T const& operator[] (int i) const
    {
        assert(i >= 0 && i < mSize);
        return mVec[i];
    }
   
};



#endif