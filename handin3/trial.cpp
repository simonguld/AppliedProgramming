// lower_bound/upper_bound example
#include <iostream>     // std::cout
#include <algorithm>    // std::lower_bound, std::upper_bound, std::sort
#include <vector>       // std::vector

#include "vT.hpp"

int& ful(int& x)
{
  return x;
}

int main () {

  int x = 22;

  //std::cout << ful(x) << "\n";

  Vectorz<double> B (2);
  Vectorz<double> C(2);
  //C = B;

  std::vector<double> k (2);
  k[0]=2; k[1] = 1;
  B[0]=2; B[1]=-0.33;
  std::cout << "B: " << B[0] << ", " << B[1]  << "\n";
 
  std::cout << "C: " << C[0] << ", " << C[1]  << "\n";

  std::vector<double>::const_iterator it = find(k.begin(),k.end(),2);
  std::cout << k[it-k.begin()] << "\n";


  /*
  int myints[] = {10,20,30,30,20,10,10,20};
  std::vector<int> v(myints,myints+8);           // 10 20 30 30 20 10 10 20

  std::sort (v.begin(), v.end());                // 10 10 10 20 20 20 30 30

  std::vector<int>::iterator low,up;
  low=std::lower_bound (v.begin(), v.end(), 20); //          ^
  up= std::upper_bound (v.begin(), v.end(), 20); //                   ^


 //   std::cout << v.begin() << "   " "\n"; //<< v.begin() << "\n";
  std::cout << "lower_bound at position " << (low- v.begin()) << '\n';
  std::cout << "upper_bound at position " << (up - v.begin()) << '\n';

*/
  return 0;
}