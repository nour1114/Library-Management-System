#include "LoanFactory.h"

LoanFactory::LoanFactory()
    : nextLoanID(1) {
}


Loan LoanFactory::createLoan(
    int bookID,
    int memberID,
    const Date& borrowDate,
    const Date& returnDate
) {

    Loan newLoan(
        nextLoanID++,
        bookID,
        memberID,
        borrowDate,
        returnDate
    );

    return newLoan;
}
