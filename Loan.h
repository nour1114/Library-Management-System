#ifndef LOAN_H
#define LOAN_H

#include "Date.h"

class Loan {
private:
    int loanID;
    int bookID;
    int memberID;

    Date borrowDate;
    Date returnDate;

    bool returned;

public:

    Loan(
        int loanID,
        int bookID,
        int memberID,
        const Date& borrowDate,
        const Date& returnDate
    );

    int getLoanID() const;
    int getBookID() const;
    int getMemberID() const;

    bool isReturned() const;

    void markAsReturned();

    void displayInfo() const;
};

#endif
