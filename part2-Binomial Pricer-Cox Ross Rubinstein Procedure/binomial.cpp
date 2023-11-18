# include <iostream>
# include "binomial.h"
# include <cmath>
using namespace std;

// Member Function Definition of Class BinomialModel.

// Accessor Functions (Setters).
void BinomialModel::SetStock(double stock) 
{S0 = stock;}
void BinomialModel::SetU(double U) 
{this->U = U;}
void BinomialModel::SetD(double D) 
{this->D = D;}
void BinomialModel::SetR(double R) 
{this->R = R;}

double BinomialModel::RiskNeutProb() const
{
    return (double)(R-D)/(U-D);
}
double BinomialModel::S(int n, int i) const     // Compute Stock price at the node i, time n.
{
    return S0*pow(1+U,i)*pow(1+D,n-i);
}
void BinomialModel::CheckData() const
{ 
    // Making sure that 0<S0, -1<D<U, -1<R.
    if (S0<=0.0 || U<=-1.0 || D<=-1.0 || U<=D || R<=-1.0)
    { 
        cout << "Illegal data range" << endl;
        cout << "Terminating program" << endl;
        exit(1);
    }
    // Checking for arbitrage.
    if (R>=U || R<=D)
    { 
        cout << "Arbitrage exists " << endl;
        cout << "Terminating program " << endl;
        exit(1);
    }
};

// Member Function Definition of Class Option.
// Accessor Functions getters and setters.
void Option:: SetN(int N)
{this->N=N;};   // Sets Expiry date N.
int Option:: GetN() const
{return N;};

// Member Function Definition of Class EuropeanOption.
double EuropeanOption::PriceByCRR(const BinomialModel& Model) const
{   /*Function PriceByCRR which returns the price at time 0 */
    double q = Model.RiskNeutProb();  // Risk neutral probability.
    int N = GetN();
    std::vector<double> Price(N+1);
    // Fixing terminal condition.
    for (int i=0;i<=N;i++)
    {
        Price[i] = Payoff(Model.S(N,i));
    }
    // For each period n we compute in all the nodes.
    for (int n=N-1; n>=0; n--)
    {
        for (int i=0;i<=n; i++)
        {
            Price[i]=(q*Price[i+1]+(1-q)*Price[i])/(1+Model.GetR());
        }
    }
    return Price[0];
}

/*Function PriceByCRR which computes the price at any time step n and node i, and the replicating 
  strategy. The function returns the price at time 0 */
double EuropeanOption::PriceByCRR(const BinomialModel& Model,  BinLattice<double>& PriceTree, BinLattice<double>& StrategyTree, BinLattice<double>& BondTree) const
{    
    double q= Model.RiskNeutProb();
    int N=GetN();
    PriceTree.SetN(N);
    StrategyTree.SetN(N-1);
    BondTree.SetN(N-1);
    
    /*Fix the terminal consdition*/
    for (int i=0;i<=N;i++)
    {   PriceTree.SetNode(N,i,Payoff(Model.S(N,i)));
        
    }
    
    /*For each period n we compute in all the nodes*/
    
    for (int n=N-1; n>=0; n--)
    {
        for (int i=0;i<=n; i++)
        {   StrategyTree.SetNode(n,i,(PriceTree.GetNode(n+1,i+1)-PriceTree.GetNode(n+1,i))/(Model.S(n+1,i+1)-Model.S(n+1,i)));
            PriceTree.SetNode(n,i,(q*PriceTree.GetNode(n+1,i+1)+(1-q)*PriceTree.GetNode(n+1,i))/(1+Model.GetR()));
            BondTree.SetNode(n,i,(PriceTree.GetNode(n,i)-StrategyTree.GetNode(n,i)*Model.S(n,i))/(pow(1+Model.GetR(),n)));
            
        }
    }
    PriceTree.Display();
    StrategyTree.Display();
    BondTree.Display();
    return PriceTree.GetNode(0,0);    
}

// Member Function Definition of Class AmericanOption.

double AmericanOption::PriceBySnell(const BinomialModel& Model) const
{   /*Function PriceBySnell which returns the price at time 0 */
    double q=Model.RiskNeutProb();
    int N=GetN();
    std::vector<double> Price(N+1);
    // continuation value
    double ContValue;
    for (int i=0;i<=N;i++)
    {
        Price[i]=Payoff(Model.S(N,i));
    }
    
    for (int n=N-1; n>=0; n--)
    {
        for (int i=0;i<=n;i++)
        {
            ContValue=(q*Price[i+1]+(1-q)*Price[i])/(1+Model.GetR());
            Price[i]=Payoff(Model.S(n,i));
            if (ContValue>Price[i]) Price[i]=ContValue;
        }
    }
    
    return Price[0];
}

/*Function PriceBySnell which computes the price at any time step n and node i, and the stopping strategy. The function returns the price at time 0 */
double AmericanOption::PriceBySnell(const BinomialModel& Model, BinLattice<double>& PriceTree, BinLattice<bool>& StoppingTree) const
{
    double q = Model.RiskNeutProb();
    int N = GetN();
    PriceTree.SetN(N);
    StoppingTree.SetN(N);
    double ContVal;
    for (int i=0;i<=N;i++)
    { 
        PriceTree.SetNode(N,i,Payoff(Model.S(N,i)));
        StoppingTree.SetNode(N,i,1);
    }
    for (int n=N-1;n>=0;n--)
    {
        for (int i=0;i<=n;i++)
        {
            ContVal=(q*PriceTree.GetNode(n+1,i+1)+(1-q)*PriceTree.GetNode(n+1,i))/(1+Model.GetR());
            PriceTree.SetNode(n,i,Payoff(Model.S(n,i)));
            StoppingTree.SetNode(n,i,1);
            if (ContVal>PriceTree.GetNode(n,i))
            {   
                PriceTree.SetNode(n,i,ContVal);
                StoppingTree.SetNode(n,i,0);
            }
            else if (PriceTree.GetNode(n,i)==0.0)
            {   
                StoppingTree.SetNode(n,i,0);
            }
        }
    }
    return PriceTree.GetNode(0,0);    
}

// Member Function Definition of Class Call.
double Call::Payoff(double z) const
{ 
    if(z>K) 
        return z-K;
    return 0.0;
}
// Accessor Functions.
double Call:: GetK() const
{return K;}
void Call:: SetK(double K)
{this->K=K;}

// Member Function Definition of Class Put.
double Put::Payoff(double z) const
{ 
    if (z<K) 
        return K-z;
    return 0.0;
}
// Accessor Functions.
double Put:: GetK() const
{return K;}
void Put:: SetK(double K)
{this->K=K;}

// Member Function Definition of Class BearSpread.
double BearSpread::Payoff(double z)
{
    
    if ((K1<z) && (z<K2)) 
        return K2-z;
    else if (z<=K1) 
        return K2-K1;
    else 
        return 0;
}
// Accessor Functions.
double BearSpread::GetK1() const
{return K1;}
double BearSpread::GetK2() const
{return K2;}
void BearSpread::SetK1(double K1)
{this->K1=K1;}
void BearSpread::SetK2(double K2)
{this->K2=K2;}

// Member Function Definition of Class BullSpread.
double BullSpread::Payoff(double z)
{   
    if ((K1<z) && (z<K2)) 
        return z-K1;
    else if (z<=K1) 
        return 0;
    else 
        return K2-K1;
}
// Accessor Functions.
double BullSpread::GetK1() const
{return K1;}
void BullSpread::SetK1(double K1)
{this->K1=K1;}
double BullSpread::GetK2() const
{return K2;}
void BullSpread::SetK2(double K2)
{this->K2=K2;}

// Member Function Definition of Class DoubleDigitalOption.
double DoubleDigitalOption::Payoff(double z)
{    
    if ((K1<z) && (z<K2)) 
        return 1.0;
    return 0.0;
}
// Accessor Functions.
double DoubleDigitalOption::GetK1() const
{return K1;}
void DoubleDigitalOption::SetK1(double K1)
{this->K1=K1;}
double DoubleDigitalOption::GetK2() const
{return K2;}
void DoubleDigitalOption::SetK2(double K2)
{this->K2=K2;}

// Member Function Definition of Class DigitalCall.
double DigitalCall::Payoff(double z)
{ 
    if(z>K) 
        return 1.0;
    return 0.0;
}
// Accessor Functions.
double DigitalCall:: GetK() const
{return K;}
void DigitalCall:: SetK(double K)
{this->K=K;}

// Member Function Definition of Class DigitalPut.
double DigitalPut::Payoff(double z)
{ 
    if(z<K) 
        return 1.0;
    return 0.0;
}
// Accessor Functions.
double DigitalPut:: GetK() const
{return K;}
void DigitalPut:: SetK(double K)
{this->K=K;}

// Member Function Definition of Class Strangle.
double Strangle::Payoff(double z)
{   
    if ((K1<z) && (z<=K2)) 
        return 0.0;
    else if (z<=K1) 
        return K1-z;
    else 
        return z-K2;
}
// Accessor Functions.
double Strangle::GetK1() const
{return K1;}
void Strangle::SetK1(double K1)
{this->K1=K1;}
double Strangle::GetK2() const
{return K2;}
void Strangle::SetK2(double K2)
{this->K2=K2;}

// Member Function Definition of Class Butterfly.
double Butterfly::Payoff(double z)
{   
    if ((K1<z) && (z<=(K1+K2)/2)) 
        return z-K1;
    else if ((z<=K2) && (z>(K1+K2)/2)) 
        return K2-z;
    else 
        return 0.0;
}
// Accessor Functions.
double Butterfly::GetK1() const
{return K1;}
void Butterfly::SetK1(double K1)
{this->K1=K1;}
double Butterfly::GetK2() const
{return K2;}
void Butterfly::SetK2(double K2)
{this->K2=K2;}

// Functions which compute the approximation of the price of an European or American options by means of the binomial approximation.
double ApproxEuropeanCallBS(double S0, double sigma, double r, double T, double K)
{
    int N=150;
    double h=T/N;
    BinomialModel m;
    Call c;
    c.SetK(K);
    c.SetN(N);
    m.SetStock(S0);
    m.SetR(exp(r*h)-1);
    m.SetU(exp(r*h+sigma*sqrt(h))-1);
    m.SetD(exp(r*h-sigma*sqrt(h))-1);
    return c.PriceByCRR(m);
}

double ApproxEuropeanPutBS(double S0, double sigma, double r, double T, double K)
{
    int N=150;
    double h=T/N;
    BinomialModel m;
    Put p;
    p.SetK(K);
    p.SetN(N);
    m.SetStock(S0);
    m.SetR(exp(r*h)-1);
    m.SetU(exp(r*h+sigma*sqrt(h))-1);
    m.SetD(exp(r*h-sigma*sqrt(h))-1);    
    return p.PriceByCRR(m);
}

double ApproxAmericanCallBS(double S0, double sigma, double r, double T, double K)
{
    int N=150;
    double h=T/N;
    BinomialModel m;
    Call c;
    c.SetK(K);
    c.SetN(N);
    m.SetStock(S0);
    m.SetR(exp(r*h)-1);
    m.SetU(exp(r*h+sigma*sqrt(h))-1);
    m.SetD(exp(r*h-sigma*sqrt(h))-1);
    return c.PriceBySnell(m);
}

double ApproxAmericanPutBS(double S0, double sigma, double r, double T, double K)
{
    int N=150;
    double h=T/N;
    BinomialModel m;
    Put p;
    p.SetK(K);
    p.SetN(N);
    m.SetStock(S0);
    m.SetR(exp(r*h)-1);
    m.SetU(exp(r*h+sigma*sqrt(h))-1);
    m.SetD(exp(r*h-sigma*sqrt(h))-1);
    return p.PriceBySnell(m);
    }

// Second version: Only one function to compute the approximation of an American call/put and only one function to compute the approximation of an European call/put.
double ApproxAmericanCallPutBS(double S0, double sigma, double r, double T, double K, AmericanOption& option)
{  /* We use dynamic cast because the function SetK is defined in the classes Call and Put, not in class Option or in class Euroption.*/
    int N=150;
    double h=T/N;
    BinomialModel m;
    option.SetN(N);
    m.SetStock(S0);
    m.SetR(exp(r*h)-1);
    m.SetU(exp(r*h+sigma*sqrt(h))-1);
    m.SetD(exp(r*h-sigma*sqrt(h))-1);    
    if(dynamic_cast<Call*>(&option))
    {   
        Call* c= dynamic_cast<Call*>(&option);
        c->SetK(K);
        return c->PriceBySnell(m);
    }
    else     
    {   
        Put* p= dynamic_cast<Put*>(&option);
        p->SetK(K);
        return p->PriceBySnell(m);
    }   
};

// Functions which compute the approximation of an American/European call/put and the replicating strategy.
double ApproxEuropeanCallPutBS(double S0, double sigma, double r, double T, double K, EuropeanOption& option)
{ 
/* We use dynamic cast because the function SetK is defined in the classes Call and Put, not in class Option or class Euroption.*/
    int N=150;
    double h=T/N;
    BinomialModel m;
    option.SetN(N);
    m.SetStock(S0);
    m.SetR(exp(r*h)-1);
    m.SetU(exp(r*h+sigma*sqrt(h))-1);
    m.SetD(exp(r*h-sigma*sqrt(h))-1);
    if(dynamic_cast<Call*>(&option))
    {
        Call* c= dynamic_cast<Call*>(&option);
        c->SetK(K);
        return c->PriceByCRR(m);
    }
    else    
    {   
        Put* p= dynamic_cast<Put*>(&option);
        p->SetK(K);
        return p->PriceByCRR(m);
    }
};

double ApproxEurCallBS(double S0, double sigma, double r, double T, double K, BinLattice<double>& PriceTree,BinLattice<double>& StrategyTree, BinLattice<double>& BondTree)
{
    int N=150;
    double h=T/N;
    BinomialModel m;
    Call c;
    c.SetK(K);
    c.SetN(N);
    m.SetStock(S0);
    m.SetR(exp(r*h)-1);
    m.SetU(exp(r*h+sigma*sqrt(h))-1);
    m.SetD(exp(r*h-sigma*sqrt(h))-1);
    double price=c.PriceByCRR(m,PriceTree,StrategyTree,BondTree);
    PriceTree.Display();
    StrategyTree.Display();
    BondTree.Display();
    return price;
}

double ApproxAmericanCallBS(double S0, double sigma, double r, double T, double K, BinLattice<double>& PriceTree,BinLattice<bool>& StoppingTree)
{
    int N=150;
    double h=T/N;
    BinomialModel m;
    Call c;
    c.SetK(K);
    c.SetN(N);
    m.SetStock(S0);
    m.SetR(exp(r*h)-1);
    m.SetU(exp(r*h+sigma*sqrt(h))-1);
    m.SetD(exp(r*h-sigma*sqrt(h))-1);
    double price=c.PriceBySnell(m,PriceTree,StoppingTree);
    PriceTree.Display();
    StoppingTree.Display();
    return price;
}

double ApproxAmericanPutBS(double S0, double sigma, double r, double T, double K, BinLattice<double>& PriceTree,BinLattice<bool>& StoppingTree)
{
    int N=150;
    double h=T/N;
    BinomialModel m;
    Put c;
    c.SetK(K);
    c.SetN(N);
    m.SetStock(S0);
    m.SetR(exp(r*h)-1);
    m.SetU(exp(r*h+sigma*sqrt(h))-1);
    m.SetD(exp((r)*h-sigma*sqrt(h))-1);
    double price=c.PriceBySnell(m,PriceTree,StoppingTree);
    PriceTree.Display();
    StoppingTree.Display();
    return price;
}