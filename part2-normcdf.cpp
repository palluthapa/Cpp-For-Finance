# include<iostream>
# include <cmath>

const double PI=3.141592653589793238462643383279;
const double ROOT_2_PI = sqrt( 2.0 * PI );

// Horner function definitions.
double Hornerfunction(double x, double a_0)
{
    return a_0;
}

double Hornerfunction(double x, double a_0, double a_1)
{
    return a_0+x*Hornerfunction(x,a_1);
}

double Hornerfunction(double x, double a_0, double a_1, double a_2)
{
    return a_0+x*Hornerfunction(x,a_1,a_2);
}

double Hornerfunction(double x, double a_0, double a_1, double a_2, double a_3)
{
    return a_0+x*Hornerfunction(x,a_1,a_2, a_3);
}


double Hornerfunction(double x, double a_0, double a_1, double a_2, double a_3, double a_4)
{
    return a_0+x*Hornerfunction(x,a_1,a_2, a_3, a_4);
}

double Hornerfunction(double x, double a_0, double a_1, double a_2, double a_3, double a_4, double a_5)
{
    return a_0+x*Hornerfunction(x,a_1,a_2, a_3, a_4, a_5);
}

double Hornerfunction(double x, double a_0, double a_1, double a_2, double a_3, double a_4, double a_5, double a_6)
{
    return a_0+x*Hornerfunction(x,a_1,a_2, a_3, a_4, a_5, a_6);
}

double Hornerfunction(double x, double a_0, double a_1, double a_2, double a_3, double a_4, double a_5, double a_6, double a_7)
{
    return a_0+x*Hornerfunction(x,a_1,a_2, a_3, a_4, a_5, a_6, a_7);
}

double Hornerfunction(double x, double a_0, double a_1, double a_2, double a_3, double a_4, double a_5, double a_6, double a_7, double a_8)
{
    return a_0+x*Hornerfunction(x,a_1,a_2, a_3, a_4, a_5, a_6, a_7, a_8);
}

// Cumulative Standard Normal Distribution Function.
double normcdf(double x)
{
    if (x<0) 
    {   return 1-normcdf(-x);}
    else 
    {
        double a_0 = 0.319381530;
        double a_1 = -0.356563782;
        double a_2 = 1.781477937;
        double a_3 = -1.821255978;
        double a_4 = 1.330274429;
        
        double k = 1/(1+0.2316419*x);
        double approx = 1-(1/ROOT_2_PI)*exp(-0.5*x*x)*k*Hornerfunction(k,a_0,a_1,a_2,a_3,a_4);
        return  approx;
    }
}