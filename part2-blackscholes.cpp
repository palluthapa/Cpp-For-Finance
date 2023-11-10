# include<iostream>
# include <cmath>
# include <vector>
# include "part2-normcdf.cpp"
# include "part2-norminv.cpp"
# include "part2-randuniform.cpp"
using namespace std;

/*
We have a single model so one Class "BlackScholesModel" for the model but could have hierarchy of 
Classes for model that include other models like Local Volatility models etc. 
We have hierarchy of classes the "PathIndependentOptions" which will be completely independent and a 
class "MonteCarloPricer".
*/

class BlackScholesModel     // Model of Asset Price. 
{
    private:    // Member variables.
        double stockPrice;
        double volatility;
        double drift;
        double riskFreeRate;
        double date;    // Todays date.

        // Private Helper Function "generatePricePath" to make implementation easier.
        private:
        vector<double> generatePricePath(double toDate, int nSteps, double drift) const;

    public:
        // Accessor Functions(getters and setters).
        void SetStockPrice(double stockPrice);
        double GetStockPrice() const;
        void SetVolatility(double volatility);
        double GetVolatility() const;
        void SetDrift(double drift);
        double GetDrift() const;
        void SetRiskFreeRate(double riskFreeRate);
        double GetRiskFreeRate() const;
        void SetDate(double date);
        double GetDate() const;

        // Black-Scholes Price Path Function. Uses P measure(i.e. uses drift = mu).
        vector<double> generatePricePath(double toDate, int nSteps) const;

        // Black-Scholes Price Path Function. Uses Q measure(i.e. uses drift = r).       
        vector<double> generateRiskNeutralPricePath(double toDate, int nSteps) const;
                
};
inline double BlackScholesModel :: GetStockPrice() const {return stockPrice;}
inline double BlackScholesModel :: GetVolatility() const {return volatility;}
inline double BlackScholesModel :: GetDrift() const {return drift;}
inline double BlackScholesModel :: GetRiskFreeRate() const {return riskFreeRate;}
inline double BlackScholesModel :: GetDate() const {return date;}

// Member Function Definition of class BlackScholesModel.
vector<double> BlackScholesModel::generatePricePath(double toDate, int nSteps, double drift ) const
{
    vector<double> path(nSteps+1, 0.0); // Vector of size (nSteps+1) with all elements initialised to 0.
    path[0] = stockPrice;   // Initial stock price.
    vector<double> epsilon = randn(nSteps); // Vector of N~(0,1) for B.M. increments from one time step to next.
    double dt = (toDate-date)/nSteps;   // Time increment.
    double a = (drift - volatility*volatility*0.5)*dt;
    double b = volatility*sqrt(dt);
    double currentLogS = log(stockPrice);
    for (int i=0; i<nSteps; i++) 
    {
        double dLogS = a + b*epsilon[i];    //b*epsilon[i]~(sigma*sqrt(dt)*ei)~sigma(Wt(i+1)-Wt(i)).
        double logS = currentLogS + dLogS;
        path[i+1] = exp(logS);
        currentLogS = logS;
    }
    return path;
}

vector<double> BlackScholesModel::generatePricePath(double toDate, int nSteps ) const 
{
    return generatePricePath( toDate, nSteps, drift );  // Uses Helper Function.
}

vector<double> BlackScholesModel::generateRiskNeutralPricePath(double toDate, int nSteps ) const
{
    return generatePricePath(toDate, nSteps, riskFreeRate );    // Uses Helper Function.
}
// Accessor Functions(Setters).
void BlackScholesModel::SetStockPrice(double stockPrice)
{this->stockPrice = stockPrice;}
void BlackScholesModel::SetVolatility(double volatility)
{this->volatility = volatility;}
void BlackScholesModel::SetDrift(double drift)
{this->drift = drift;}
void BlackScholesModel::SetRiskFreeRate(double riskFreeRate)
{this->riskFreeRate = riskFreeRate;}
void BlackScholesModel::SetDate(double date)
{this->date = date;}

class PathIndependentOption     // Base(Parent) class.
{
    private:        // Member variables common to all path independent options.
        double maturity;
        double strike;
    public:
        // Accessor Functions(getters and setters).
        void SetMaturity(double maturity);
        double GetMaturity() const;
        void SetStrike(double strike);
        double GetStrike() const;

        /* Function common to all derived classes but with specific behaviour. Function with Polymorphic
        behaviour is given with keyword virtual. Both functions "payoff" and "price" are Pure virtual
        functions (virtual...=0) i.e. no implementation in Base class but have to be implemented in 
        derived class. Both are const as it will not modify member variables.
        */
        virtual double payoff(double StockAtMaturity) const =0;
        virtual double price(const BlackScholesModel& bsm) const =0;

        virtual ~PathIndependentOption(){};  // Destructor.
};
inline double PathIndependentOption :: GetMaturity() const {return maturity;}
inline double PathIndependentOption :: GetStrike() const {return strike;}
// Member Function Definition of class PathIndependentOption.
// Accessor Functions(Setters).
void PathIndependentOption::SetMaturity(double maturity)
{this->maturity = maturity;}
void PathIndependentOption::SetStrike(double strike)
{this->strike = strike;}

class CallOption: public PathIndependentOption    // Derived class from class PathIndependentOption.
{
    public:     
        double payoff(double x) const;
        double price(const BlackScholesModel& bsm) const;
        ~CallOption(){};    // Destructor.
};

// Member Function Definition of class CallOption.
double CallOption::price(const BlackScholesModel& bsm) const
{
    double S = bsm.GetStockPrice();
    double K = GetStrike();
    double sigma = bsm.GetVolatility();
    double r = bsm.GetRiskFreeRate();
    double T = GetMaturity() - bsm.GetDate();   // (T-t).
    double numerator = log(S/K) + (r+sigma*sigma*0.5)*T;
    double denominator = sigma*sqrt(T);
    double d1 = numerator/denominator;
    double d2 = d1-denominator;
    return S*normcdf(d1) - K*exp(-r*T)*normcdf(d2);
}

double CallOption::payoff(double x) const 
{
    return max(0.0, x- GetStrike());
}

class PutOption: public PathIndependentOption     // Derived class from class PathIndependentOption.
{
    public:
        double payoff(double x) const;
        double price(const BlackScholesModel& bsm) const;
        ~PutOption(){};     // Destructor.
};

// Member Function Definition of class PutOption.
double PutOption::price(const BlackScholesModel& bsm) const
{
    double S = bsm.GetStockPrice();
    double K = GetStrike();
    double sigma = bsm.GetVolatility();
    double r = bsm.GetRiskFreeRate();
    double T = GetMaturity() - bsm.GetDate();   // (T-t).
    double numerator = log(S/K) + (r+sigma*sigma*0.5)*T;
    double denominator = sigma*sqrt(T);
    double d1 = numerator/denominator;
    double d2 = d1-denominator;
    return K*exp(-r*T)*normcdf(-d2) - S*normcdf(-d1);
}

double PutOption::payoff(double x) const 
{
    return max(0.0, GetStrike() - x);
}

// Function that generates n independent Normally distributed random numbers with mu = 0 and sigma^2 = 1
// using Inverse Transform Sampling.
vector<double> randn(int n)
{
    vector<double> ret = randuniform(n);  // Vector of uniformly distributed random no. in (0,1).
    for (int i=0;i<n;i++)
     {   
         ret[i] = norminv(ret[i]);
     }
     return ret;
}