# pragma once
# include <iostream>
# include <vector>
# include <cmath>

class BinomialModel
{
    private:
        double S0;
        double U;
        double D;
        double R;
    public:
        double RiskNeutProb() const;    // Function that computes the risk-neutral probability.
        double S(int n, int i) const;   // Function that computes the stock price at node (n,i).

        // Accessor Functions getters and setters.
        double GetR() const;
        double GetStock() const;
        double GetU() const;
        double GetD() const;
        void SetStock(double);
        void SetU(double);
        void SetD(double);
        void SetR(double);
        // Checking model data.
        void CheckData() const;
};

template<typename Type> class BinLattice    // Use of Class Templates so that data type is not
// hardwired inside the class, but passed to it as a parameter. The declaration and definition of class
// template needs to be written in header(.h) file.
{
    private:
        int N;  // Number of time steps in Binomial Tree.
        std::vector<std::vector<Type>> Lattice;     // Vector of vector to store Option Prices.
    public:
        void SetN(int N)
        {
            this->N=N;  // Sets N.
            Lattice.resize(N+1);       //Sets size of Lattice vector to (N+1).
            for (int n=0; n<=N;n++) 
                Lattice[n].resize(n+1);  // Sets size of inner vectro to (n+1) for each n.
        };

        void SetNode(int n, int i, Type x)    // Set the value stored at time step n, node i.
        {Lattice[n][i]=x;};

        Type GetNode(int n, int i) const      // Return the value stored at time step n, node i.
        {return Lattice[n][i];};
        
        void Display() const        // Print the value stored at time step n,node i.
        {
            for (int n=0;n<=N;n++)
            {
                for (int i=0;i<=n;i++)
                    std::cout << GetNode(n,i) << " ";
                std::cout << std::endl;
            }
            std::cout << std::endl;
        }
};

class Option
{
    private: 
        int N; // Time steps to expiry.
    public:
        // Accessor Functions getters and setters.
        void SetN(int N);   // Sets Expiry date N.
        int GetN() const;

        virtual double Payoff(double z) const=0;      // Payoff function.
        virtual ~Option(){};    // Destructor.
};

class EuropeanOption: public virtual Option     // Virtual Inheritance.
{
    public:
        // Function PriceByCRR which returns the price at time 0.
        double PriceByCRR(const BinomialModel& Model) const;

        /*Function PriceByCRR which computes the price at any time step n and node i, and the replicating strategy. The function returns the price at time 0 */
        double PriceByCRR(const BinomialModel& Model, BinLattice<double>& PriceTree, BinLattice<double>& StrategyTree, BinLattice<double>& BondTree) const;
        
        virtual ~EuropeanOption(){};    // Destructor.
};

class AmericanOption: public virtual Option     // Virtual Inheritance.
{ 
    public:
        // Function PriceBySnell returns the price at time 0.
        double PriceBySnell(const BinomialModel& Model) const;
        /*Function PriceBySnell which computes the price at any time step n and node i, and the stopping strategy. The function returns the price at time 0 */
        double PriceBySnell(const BinomialModel& Model, BinLattice<double>& PriceTree, BinLattice<bool>& StoppingTree) const;
        virtual ~AmericanOption(){};
};

class Call: public EuropeanOption, public AmericanOption    // Multiple Inheritance.
// Call inherit from both EuropeanOption and AmericanOption classes, so its a subclass of both.
{
    private: 
        double K;   // Strike Price.
    public:
        double GetK() const;
        void SetK(double K);
        double Payoff(double z) const;
        ~Call(){};
};

class Put: public EuropeanOption, public AmericanOption    // Multiple Inheritance.
{
    private: 
        double K;
    public:
        double GetK() const;
        void SetK(double K);
        double Payoff(double z) const;
        ~Put(){};
};

class BearSpread: public EuropeanOption
{
private:
    double K1; // Strike Price 1.
    double K2; // Strike Price 2.
public:
    double GetK1() const;
    void SetK1(double K1);
    double GetK2() const;
    void SetK2(double K2);
    double Payoff(double z);
    ~BearSpread(){};
};

class BullSpread: public EuropeanOption
{
private:
    double K1; // Strike Price 1.
    double K2; // Strike Price 2.
public:
    double GetK1() const;
    void SetK1(double K1);
    double GetK2() const;
    void SetK2(double K2);
    double Payoff(double z);
    ~BullSpread(){};
};

class DoubleDigitalOption: public EuropeanOption
{
private:
    double K1; // Strike Price 1.
    double K2; // Strike Price 2.
public:
    double GetK1() const;
    void SetK1(double K1);
    double GetK2() const;
    void SetK2(double K2);
    double Payoff(double z);
    ~DoubleDigitalOption(){};
};

class DigitalCall: public EuropeanOption
{
private:
    double K; // Strike Price.
public:
    double GetK() const;
    void SetK(double K);
    double Payoff(double z);
    ~DigitalCall(){};
};

class DigitalPut: public EuropeanOption
{
private:
    double K; // Strike Price.
public:
    double GetK() const;
    void SetK(double K);
    double Payoff(double z);
    ~DigitalPut(){};
};

class Strangle: public EuropeanOption
{
private:
    double K1; // Strike Price 1.
    double K2; // Strike Price 2.
public:
    double GetK1() const;
    void SetK1(double K1);
    double GetK2() const;
    void SetK2(double K2);
    double Payoff(double z);
    ~Strangle(){};
};

class Butterfly: public EuropeanOption
{
private:
    double K1; // Strike Price 1.
    double K2; // Strike Price 2.
public:
    double GetK1() const;
    void SetK1(double K1);
    double GetK2() const;
    void SetK2(double K2);
    double Payoff(double z);
    ~Butterfly(){};
};

// Approximation of Black-Scholes Model using Binomial model.
/* Functions which compute the approximation of the price of an European or American options by means of the binomial approximation */

double ApproxEuropeanCallBS(double S0, double sigma, double r, double T, double K);
double ApproxEuropeanPutBS(double S0, double sigma, double r, double T, double K);
double ApproxAmericanPutBS(double S0, double sigma, double r, double T, double K);
double ApproxAmericanCallBS(double S0, double sigma, double r, double T, double K);

/* Second version: Only one function to compute the approximation of an American call/put and only one function to compute the approximation of an European call/put*/

double ApproxAmericanCallPutBS(double S0, double sigma, double r, double T, double K, AmericanOption& option);
double ApproxEuropeanCallPutBS(double S0, double sigma, double r, double T, double K, EuropeanOption& option);

/* Functions which compute the approximation of an American/European call/put and the replicating strategy*/


double ApproxAmericanCallBS(double S0, double sigma, double r, double T, double K, BinLattice<double>& PriceTree,BinLattice<bool>& StoppingTree);
double ApproxAmericanPutBS(double S0, double sigma, double r, double T, double K, BinLattice<double>& PriceTree,BinLattice<bool>& StoppingTree);
double ApproxEurCallBS(double S0, double sigma, double r, double T, double K, BinLattice<double>& PriceTree,BinLattice<double>& StrategyTree, BinLattice<double>& BondTree);

// Inline Accessor functions definitions.
inline double BinomialModel:: GetR() const
{return R;}
inline double BinomialModel:: GetStock() const
{return S0;}
inline double BinomialModel:: GetU() const
{return U;}
inline double BinomialModel:: GetD() const
{return D;}
