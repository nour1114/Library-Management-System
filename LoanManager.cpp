#include "LoanManager.h"

#include <iostream>


// ================= BORROW =================

void LoanManager::borrowBook(
    int memberID,
    int bookID,
    const Date& borrowDate,
    const Date& returnDate,
    BookCatalog& bookCatalog,
    MemberRegistry& memberRegistry
) {

    if (memberID <= 0) {
        std::cout << "Invalid member ID!" << std::endl;
        return;
    }

    if (bookID <= 0) {
        std::cout << "Invalid book ID!" << std::endl;
        return;
    }

    if (returnDate.isBefore(borrowDate)) {

        std::cout
            << "Invalid dates: return date cannot "
               "be before borrow date!"
            << std::endl;

        return;
    }

    if (bookCatalog.searchBook(bookID) == nullptr) {

        std::cout
            << "Book not found"
            << std::endl;

        return;
    }

    if (memberRegistry.searchMember(memberID) == nullptr) {

        std::cout
            << "Member not found"
            << std::endl;

        return;
    }

    if (isBookBorrowed(bookID)) {

        std::cout
            << "Book is already borrowed!"
            << std::endl;

        return;
    }


    // Create the loan using LoanFactory

    Loan newLoan = loanFactory.createLoan(
        bookID,
        memberID,
        borrowDate,
        returnDate
    );


    loans.push_back(newLoan);


    std::cout
        << "Book borrowed successfully!"
        << std::endl;

    std::cout
        << "Loan ID: "
        << newLoan.getLoanID()
        << std::endl;
}


// ================= RETURN =================

void LoanManager::returnBook(int loanID) {

    if (loanID <= 0) {

        std::cout
            << "Invalid loan ID!"
            << std::endl;

        return;
    }


    Loan* loan = searchLoan(loanID);

    if (loan == nullptr) {

        std::cout
            << "Loan not found!"
            << std::endl;

        return;
    }


    if (loan->isReturned()) {

        std::cout
            << "Book is already returned!"
            << std::endl;

        return;
    }


    loan->markAsReturned();


    std::cout
        << "Book returned successfully!"
        << std::endl;
}


// ================= SEARCH =================

Loan* LoanManager::searchLoan(int loanID) {

    if (loanID <= 0) {
        return nullptr;
    }

    for (Loan& loan : loans) {

        if (loan.getLoanID() == loanID) {
            return &loan;
        }
    }

    return nullptr;
}


const Loan* LoanManager::searchLoan(
    int loanID
) const {

    if (loanID <= 0) {
        return nullptr;
    }

    for (const Loan& loan : loans) {

        if (loan.getLoanID() == loanID) {
            return &loan;
        }
    }

    return nullptr;
}


// ================= DISPLAY =================

void LoanManager::displayLoans() const {

    if (loans.empty()) {

        std::cout
            << "No loans available."
            << std::endl;

        return;
    }


    for (const Loan& loan : loans) {

        loan.displayInfo();

        std::cout
            << "--------------------"
            << std::endl;
    }
}


void LoanManager::displayMemberLoans(
    int memberID
) const {

    if (memberID <= 0) {

        std::cout
            << "Invalid member ID!"
            << std::endl;

        return;
    }


    bool found = false;


    for (const Loan& loan : loans) {

        if (
            loan.getMemberID() == memberID &&
            !loan.isReturned()
        ) {

            loan.displayInfo();

            std::cout
                << "--------------------"
                << std::endl;

            found = true;
        }
    }


    if (!found) {

        std::cout
            << "Member has no active loans."
            << std::endl;
    }
}


// ================= VALIDATION =================

bool LoanManager::isBookBorrowed(
    int bookID
) const {

    if (bookID <= 0) {
        return false;
    }


    for (const Loan& loan : loans) {

        if (
            loan.getBookID() == bookID &&
            !loan.isReturned()
        ) {

            return true;
        }
    }


    return false;
}
