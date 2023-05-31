#include <iostream>
#include <fstream>
#include <cmath>
#include <cassert>

#include <vector>
#include <algorithm>

//In this script, we are going the apply the k-nearest-neighbours algorithm on 151 test points
//given 200 data points each assignes a binary label. 
//each test points is assigned a label corresponding to the majority label of the k nearest data points

//we are provided 200 points of dimension 34 in "dataX.dat" and 200 corresponding labels (values 1 or -1)
//in dataY.dat.

//dataXtest.dat contains 151 points, each of which must be assigned a label in accordance with the 
// nearest neighbor classification using a majority voting scheme

////
// NB! We are using 0-indexing, meaning that the each point (i,j) in the data files 
// are indexed as (i-1,j-1)
////

int k = 5; //# of closest points considered in order to assign label


double calculateDistance (std::vector<double> x, std::vector<double> xi);



int main()
{
    int dim = 34; //dimensionality of each vector
    int n_points = 200; 
    int n_test_points = 151;

    //construct vector containers for dataX, dataY and dataXtest
    std::vector<std::vector<double>> x_data;
    std::vector<double> y_data (n_points,0);
    std::vector<std::vector<double>> x_test;

    x_data.reserve(n_points);
    x_test.reserve(n_test_points);

    //ready dataY:
    std::ifstream read_Y("dataY.dat");
    assert(read_Y.is_open());
    for (int i = 0; i < n_points; i++)
    {
        read_Y >> y_data[i];
    }
    read_Y.close();

    //read dataX:
    std::ifstream read_X("dataX.dat");
    assert(read_X.is_open());
    for (int j= 0; j < n_points; j++)
    {   std::vector<double> initializer (dim,0);
        for (int i = 0; i<dim; i++)
        {   
            read_X >> initializer[i];
        }
        x_data.push_back(initializer);
    }
    read_X.close();

    //read dataXtest:
    std::ifstream read_X_test("dataXtest.dat");
    assert(read_X_test.is_open());
    for (int j = 0; j < n_test_points; j++)
    {   std::vector<double> initializer (dim,0);
        for (int i = 0; i<dim; i++)
        {   
            read_X_test >> initializer[i];
        }
        x_test.push_back(initializer);
    }
    read_X_test.close();
    
    //create file NN.dat to hold labels
    std::ofstream write_label("NN.dat");
    assert(write_label.is_open());

    for (int i = 0; i<n_test_points; i++)
    {
        std::vector<double> u (2,0);
        std::vector<std::vector<double>> P; //structure is (d,y)
        P.reserve(k);
       
        for (int j = 0; j<n_points; j++)
        {
            double dist = calculateDistance(x_test[i], x_data[j]);
            if (j<k)
            {
                P.push_back({dist,y_data[j]});
                if (j == k-1)
                {
                    std::sort(P.begin(),P.end());
                }
            }
            else
            {
                if (dist<P[k-1][0]) 
                {
                    P.pop_back();
                    P.push_back({dist,y_data[j]});
                    std::sort(P.begin(),P.end());
                }
            }      
        }

            double sum = 0;
            for (int m = 0; m<k; m++)
            {
                sum += P[m][1];
            }
          
            double tol =1e-8;
            double sign;
            if (fabs(sum)<tol)
            {
                sign = 0;
            }
            else
            {
                sign = sum / fabs(sum);
            }   
            write_label << sign << "\n";
            
/*
        std::cout << P[0][0] << ",   " << P[0][1] << "\n";
        std::cout << P[1][0] << ",   " << P[1][1] << "\n";
        std::cout << P[2][0] << ",   " << P[2][1] << "\n";
        std::cout << P[3][0] << ",   " << P[3][1] << "\n";
        std::cout << P[4][0] << ",   " << P[4][1] << "\n \n \n";

*/
    }
    write_label.close();

    return 0;
}


double calculateDistance (std::vector<double> x, std::vector<double> xi)
{
    assert(x.size() == xi.size());
    double sq_distance;
    int dim = x.size();
    for (int i = 0; i<dim; i++)
    {
        sq_distance += pow(x[i]-xi[i],2);
    }
    return sqrt(sq_distance);
}
