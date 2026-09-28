#ifndef LOANMANAGER_H
#define LOANMANAGER_H

#include <vector>

#include "Loan.h"
#include "LoanFactory.h"
#include "BookCatalog.h"
#include "MemberRegistry.h"

class LoanManager {
private:
    std::vector<Loan> loans;
    LoanFactory loanFactory;

public:

    void borrowBook(
        int memberID,
        int bookID,
        const Date& borrowDate,
        const Date& returnDate,
        BookCatalog& bookCatalog,
        MemberRegistry& memberRegistry
    );

    void returnBook(int loanID);

    Loan* searchLoan(int loanID);
    const Loan* searchLoan(int loanID) const;

    void displayLoans() const;

    void displayMemberLoans(int memberID) const;

    bool isBookBorrowed(int bookID) const;
};

#endif
