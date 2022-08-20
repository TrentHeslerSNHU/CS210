#include <iostream>
#include <iomanip>
#include <string>
#include "investment.h"

using namespace std;

/**
 * Prints a specified character n times
 * @param numChars the number of times to print the char
 * @param charToPrint the char to be printed
 */
string printNCharString(const int &numChars, const char &charToPrint)
{
     string finalString;

     // Append the desired number of chars to a string
     for (int i = 0; i < numChars; i++)
     {
          finalString = finalString + charToPrint;
     }

     // Return the completed string
     return finalString;
}

/**
 * Prints tables showing balances with and without interest
 * @param withoutPayments an account without monthly payments
 * @param withPayments an account with monthly payments
 */
void printTable(Investment* withoutPayments, InvestmentWithPayments* withPayments) {
    
    // Print table header and legend
    cout << "     Balance and Interest Without Additional Monthly Deposits     " << endl;
    cout << printNCharString(64, '=') << endl;
    cout << setw(5) << right << "Year";
    cout << setw(25) << right << "Year End Balance";
    cout << setw(32) << right << "Year End Earned Interest" << endl;
    cout << printNCharString(64, '-') << endl;
    
    //Print the data values for each year
    for(int i = 1; i <= (withoutPayments->getTerm() / 12); i++) {
        cout << setw(3) << i;
        cout << setw(26) << fixed << setprecision(2) << withoutPayments->getClosingBalance(i * 12) << "     ";
        cout << (withoutPayments->getInterestAccrued(i * 12) - withoutPayments->getInterestAccrued((i - 1) * 12)) << endl;
    }

    // Pause between tables
    cout << "Press enter to continue..." << endl;
    cin.clear();
    cin.ignore();

    // Print second table header and legend
    cout << "      Balance and Interest With Additional Monthly Deposits       " << endl;
    cout << printNCharString(64, '=') << endl;
    cout << setw(5) << right << "Year";
    cout << setw(25) << right << "Year End Balance";
    cout << setw(32) << right << "Year End Earned Interest" << endl;
    cout << printNCharString(64, '-') << endl;

    //Print the data values for each year
    for(int i = 1; i <= (withPayments->getTerm() / 12); i++) {
        cout << setw(3) << i;
        cout << setw(26) << fixed << setprecision(2) << withPayments->getClosingBalance(i * 12) << "     ";
        cout << (withPayments->getInterestAccrued(i * 12) - withPayments->getInterestAccrued((i - 1) * 12)) << endl;
    }

    //Pause before returning
    cout << "Press enter to continue..." << endl;
    cin.ignore();
}

/**
 * Prints the data entry menu
 */
void dataEntry() {
    double initialInvestment;
    double monthlyDeposit;
    double interestRate;
    int investmentTerm;

    //Create an inestment object
    Investment* withoutPayments;
    withoutPayments = new Investment;

    //Create an investment object with payments
    InvestmentWithPayments* withPayments;
    withPayments = new InvestmentWithPayments;

    //Data entry header
    cout << printNCharString(34, '*') << endl;
     cout << printNCharString(11, '*');
     cout << " Data Input ";
     cout << printNCharString(11, '*') << endl;
    
    //Get initial investment amount
    cout << "Initial investment amount: ";
    cin >> initialInvestment;

    //If user enters invalid input, get new input
    while (cin.fail() || initialInvestment <= 0.0) {
        cin.clear();
        cin.ignore();
        cout << "Please enter a valid dollar amount, greater than 0." << endl;
        cout << "Initial investment amount: ";
        cin >> initialInvestment;
    }

    //Store data in investment objects
    withoutPayments->setPrinciple(initialInvestment);
    withPayments->setPrinciple(initialInvestment);

    //Get monthly deposit
    cout << "Monthly deposit: ";
    cin >> monthlyDeposit;

    //If user enters invalid input, get new input
    while (cin.fail() || monthlyDeposit <= 0.0) {
        cin.clear();
        cin.ignore();
        cout << "Please enter a valid dollar amount, greater than 0." << endl;
        cout << "Monthly deposit: ";
        cin >> monthlyDeposit;
    }

    //Store data in investment object
    withPayments->setMonthlyPayment(monthlyDeposit);

    //Get annual interest rate
    cout << "Annual interest: ";
    cin >> interestRate;

    //If user enters invalid input, get new input
    while (cin.fail() || interestRate <= 0.0) {
        cin.clear();
        cin.ignore();
        cout << "Please enter a valid interest rate, greater than 0." << endl;
        cout << "Annual interest: ";
        cin >> interestRate;
    }

    //Store data in investment objects
    withoutPayments->setRate(interestRate);
    withPayments->setRate(interestRate);

    //Get the term of the investment
    cout << "Number of years: ";
    cin >> investmentTerm;

    //If user enters invalid input, get new input
    while (cin.fail() || investmentTerm <= 0) {
        cin.clear();
        cin.ignore();
        cout << "Please enter a valid integer number, greater than 0." << endl;
        cout << "Number of years: ";
        cin >> investmentTerm;
    }

    //Store data in investment objects
    withoutPayments->setTerm(investmentTerm * 12);
    withPayments->setTerm(investmentTerm * 12);

    cin.ignore();
    cout << endl << endl;

    //Print a table for the created investments
    printTable(withoutPayments,withPayments);

    //Cleanup
    delete withoutPayments;
    delete withPayments;
}

//Controls the main operation of the program
int main() {
    char userChoice = 'y';

    //Loop until user says to stop
    while(userChoice == 'y' || userChoice == 'Y') {
        //Call the data entry menu
        dataEntry();
        cout << endl;

        //Ask if the user wants to go again
        cout << "Would you like to calculate another? (y/n) ";
        cin >> userChoice;

        //If the user enters invalid input, clear the buffer
        if(cin.fail()) {
            cin.clear();
            cin.ignore();
        }
    }
    return 0;
}