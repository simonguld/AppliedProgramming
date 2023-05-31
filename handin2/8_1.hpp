#ifndef HEADER_8_2_
#define HEADER_8_2_

#include<vector>
#include<algorithm>
#include<iostream>
#include<cassert>

template<unsigned int N> class RainArray
{
    private:
    std::vector<double> mData(N);
    public:
        //overload the [] operator
        double& operator [] (int index)
        {
            double error = 1e-6;
            assert (mData[index]<=1+error && mData[index]>=0-error);
            return mData[index];
        }
        
}

#endif

int main()
{
    std::cout << "hej";

    return 0;
}