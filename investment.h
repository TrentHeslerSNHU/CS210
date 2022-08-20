#ifndef INVESTMENT_H
#define INVESTMENT_H

//Class declarations
class Investment {
    protected:
        int term;
        double principle;
        double rate;
    
    public:
        //Constructor
        Investment();

        //Setters and getters
        void setTerm(int newTerm){term = newTerm;};
        void setPrinciple(double newPrinciple){principle = newPrinciple;};
        void setRate(double newRate){rate = newRate;};
        const int& getTerm(){return term;};
        const double& getPrinciple(){return principle;};
        const double& getRate(){return rate;};

        //Calculation functions
        const double getInterestAccrued(const int&);
        const double getInterestAccrued();
        const double getClosingBalance(const int&);
        const double getClosingBalance();
};

class InvestmentWithPayments : public Investment {
    protected:
        double monthlyPayment;

    public:
        //Constructor
        InvestmentWithPayments();

        //Setters and getters
        void setMonthlyPayment(double newPayment){monthlyPayment = newPayment;};
        const double& getMonthlyPayment(){return monthlyPayment;};

        //Calculation function overrides
        const double getInterestAccrued(const int&);
        const double getInterestAccrued();
        const double getClosingBalance(const int&);
        const double getClosingBalance();
};

#endif