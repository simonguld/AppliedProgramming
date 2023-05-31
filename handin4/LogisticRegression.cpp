#include <iostream>
#include <fstream>
#include <cmath>
#include <cassert>

#include "armadillo.hpp"


double goldenLineSearch (int& iterations, double (*pFunc) (arma::rowvec omega, arma::colvec y, arma::mat x),
arma::rowvec gradient, arma::rowvec omega, arma::colvec y, arma::mat x, double tol=0.2)
{   
    //choose alpha to minimize func (x_k - alpha * grad(x_k) )

    double alpha1, alpha2;
    double f1, f2;
    double a = 0, b = 1;
    double tau = (sqrt(5)-1)/2;

    alpha1 = a + (1-tau)*(b-a);
    alpha2 = a + tau * (b-a); 
    f1 = (*pFunc) (omega - alpha1 * gradient, y, x);
    f2 = (*pFunc) (omega - alpha2 * gradient, y, x);

    while (fabs(b-a)>tol && iterations < 100)
    {
        if (f1 > f2)
        {
            a = alpha1;
            alpha1 = alpha2;
            f1 = f2;
            alpha2 = a+tau*(b-a);
            f2 = (*pFunc) (omega - alpha2 * gradient, y, x);
        }
        else
        {
            b = alpha2;
            alpha2 = alpha1;
            f2 = f1;
            alpha1 = a + (1-tau) * (b-a);
            f1 = (*pFunc) (omega - alpha1 * gradient, y, x);
        }
        iterations += 1;
    }
    return (alpha1+alpha2)/2;
}


double logRegFunc (arma::Row<double> omega, arma::Col<double> y, arma::Mat<double> x)
{
    int points = x.n_rows;
    double func = 0;

    for (int i = 0; i < points; i++)
    {
        func += log( 1 + exp ( -y[i] * arma::dot(omega,x.row(i) ) ) );
    }

    return func/points;
}

arma::Row<double> calculateGradient (arma::Row<double> omega, arma::Col<double> y, arma::Mat<double> x)
{
    int points = x.n_rows;
    int dim = x.n_cols;

    arma::Row<double> grad (dim, arma::fill::zeros);

    for (int i = 0; i<points; i++)
    {
        grad -= y[i] * 1/(1+ exp( y[i]* arma::dot(omega,x.row(i)) ))  * x.row(i);
    }
    return grad/points;
}   

int main()
{
    int dim = 34; //dimensionality of each vector
    int n_points = 200; 
    int n_test_points = 151;

    //mat is shorthand for Mat<double>, colvec/vec shorthand for Col<double>, rowvec shorthand for Row<double>
    arma::Mat<double> x_data, x_test;
    arma::Col<double> y_data(n_points, arma::fill::zeros);

    x_data.zeros(n_points,dim);
    x_test.zeros(n_test_points,dim);

 
    #if 1
    //read dataY:
    std::ifstream read_Y("dataY.dat");
    assert(read_Y.is_open());
    for (int i = 0; i < n_points; i++)
    {
        read_Y >> y_data[i];
    }
    read_Y.close();

    //read dataX:
    std::ifstream read_X("dataX.dat");
    read_X.precision(6);
    assert(read_X.is_open());
    for (int j= 0; j < n_points; j++)
    {   arma::Row<double> initializer (dim);
        for (int i = 0; i<dim; i++)
        {   
            read_X >> initializer[i];
        }
        x_data.row(j) = initializer;
    }
    read_X.close();

    //read dataXtest:
    std::ifstream read_X_test("dataXtest.dat");
    assert(read_X_test.is_open());
    for (int j= 0; j < n_test_points; j++)
    {   arma::Row<double> initializer (dim);
        for (int i = 0; i<dim; i++)
        {   
            read_X_test >> initializer[i];
        }
        x_test.row(j) = initializer;
    }
    read_X_test.close();

    #endif

   #if 1
    //create file LogReg.dat to hold labels
    std::ofstream write_test("LogReg.dat");
    assert(write_test.is_open());

    //create file to test that algorithm labeling agrees mostly with Ydata when used on Xdata
    std::ofstream write_data ("DataYlog.dat");
    assert(write_data.is_open());

    //find optimal omega:
   
    int m = 0;
    double alpha = 0.6, tol = 1e-7, max_iterations = 1e5;
    arma::Row<double> gradient (dim,arma::fill::ones);
    arma::Row<double> omega (dim,arma::fill::zeros);

    while (arma::norm(gradient) > tol && m<max_iterations)
    {
        //std::cout << "start loop omega norm : " << norm(omega) << "\n";

        gradient = calculateGradient(omega,y_data,x_data);

        //As it turns out, performing a golden line search results in a total of app 32.000 function calls, whereas
        //simply using alpha=0.6 results in about 27.000
        #if 0
        double beta = goldenLineSearch(m, logRegFunc, gradient, omega, y_data, x_data);
        omega -= beta * gradient;
        #endif
        omega -= alpha*gradient;
        
        m += 1;
    }
    std::cout << "norm(gradient) = " << arma::norm(gradient) << "\n";
    std::cout << "steepest descent # of iterations = " << m << "\n";

    arma::Row<double> pert (dim,arma::fill::ones);

    //Check that omega is a minimum:
    
    std::cout << "L(omega) = " << logRegFunc(omega,y_data,x_data) << ", L(omega + 0.05*I) = " << logRegFunc(omega+0.05*pert,y_data,x_data);
    std::cout << ",  L(omega - 0.05*I) = " << logRegFunc(omega-0.05*pert,y_data,x_data) << "\n";

    for (int i= 0; i < n_test_points; i++)
    {
        double avoid_div_by_zero = 1e-7;
        double sign_test,sign_data;
        
        double dot_test = arma::dot(omega,x_test.row(i));
        double dot_data = arma::dot(omega,x_data.row(i));

        if (dot_test == 0)
        {
            sign_test = 0;
        }
        else
        {
            sign_test = dot_test / fabs(dot_test);
        }

        if (dot_data == 0)
        {
            sign_data = 0;
        }
        else
        {
            sign_data = dot_data / fabs(dot_data);
        }
        write_test << sign_test << "\n";
        write_data << sign_data << "\n";
    }
    write_test.close();
    write_data.close();

    //Test whether algorithm matches k-nearest for x_data:
    arma::Col<double> y_data_log (n_test_points,arma::fill::zeros);

    std::ifstream read_y_log ("DataYlog.dat");
    assert(read_y_log.is_open());
    for (int i = 0; i < n_test_points; i++)
    {
        read_y_log >> y_data_log[i];
    }
    read_y_log.close();

    double sum_data = 0;
    for (int i = 0; i < n_test_points; i++)
    {
        
        if (y_data[i] != y_data_log[i])
        {
            sum_data += 1;
        }
    }
    std::cout << "# of log-assigned labels disagreeing with dataY.dat: " << sum_data << "\n";

    #endif

    return 0;
}