#ifndef LOANFACTORY_H
#define LOANFACTORY_H

#include "Loan.h"

class LoanFactory {
private:
    int nextLoanID;

public:
    LoanFactory();

    Loan createLoan(
        int bookID,
        int memberID,
        const Date& borrowDate,
        const Date& returnDate
    );
};

#endif
