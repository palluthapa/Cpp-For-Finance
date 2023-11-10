# include<iostream>
# include <cmath>

const double PI = 3.141592653589793238462643383279;
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

// Absolute value Function.
double absolute_value(double x)
{
    if (x>=0) return x;
    else return -x;
}

// Inverse of Cumulative Standard Normal Distribution Function.
double norminv(double x)
{   const double a_0 = 2.50662823884;
    const double a_1 = -18.61500062529;
    const double a_2 = 41.39119773534;
    const double a_3 = -25.44106049637;
    const double b_1 = -8.47351093090;
    const double b_2 = 23.08336743743;
    const double b_3 = -21.06224101826;
    const double b_4 = 3.13082909833;
    const double c_0 = 0.3374754822726147;
    const double c_1 = 0.9761690190917186;
    const double c_2 = 0.1607979714918209;
    const double c_3 = 0.0276438810333863;
    const double c_4 = 0.0038405729373609;
    const double c_5 = 0.0003951896511919;
    const double c_6 = 0.0000321767881768;
    const double c_7 = 0.0000002888167364;
    const double c_8 = 0.0000003960315187;
    double y = x - 0.5;
    double r;
    double s;
    if (absolute_value(y) < 0.42)
            {   
                r = pow(y,2);
                double Horner_3 = Hornerfunction(r,a_0,a_1,a_2,a_3);
                double Horner_4 = Hornerfunction(r, 1.0,b_1,b_2,b_3,b_4);
                return y*Horner_3/Horner_4;
            }
    else
    {   if (y<0) r = x;
        else r=1-x;
    }
    s = log(-log(r));
    double t = Hornerfunction(s, c_0,c_1,c_2,c_3,c_4,c_5,c_6,c_7,c_8);
    if (x > 0.5) 
    {return t;}
    else 
    {return -t;}
}
