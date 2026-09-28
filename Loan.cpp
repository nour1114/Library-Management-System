#include "Loan.h"

#include <iostream>
#include <stdexcept>

Loan::Loan(
    int loanID,
    int bookID,
    int memberID,
    const Date& borrowDate,
    const Date& returnDate
)
    : loanID(loanID),
      bookID(bookID),
      memberID(memberID),
      borrowDate(borrowDate),
      returnDate(returnDate),
      returned(false) {

    if (loanID <= 0) {
        throw std::invalid_argument("Invalid loan ID");
    }

    if (bookID <= 0) {
        throw std::invalid_argument("Invalid book ID");
    }

    if (memberID <= 0) {
        throw std::invalid_argument("Invalid member ID");
    }

    if (returnDate.isBefore(borrowDate)) {
        throw std::invalid_argument(
            "Return date cannot be before borrow date"
        );
    }
}

int Loan::getLoanID() const {
    return loanID;
}

int Loan::getBookID() const {
    return bookID;
}

int Loan::getMemberID() const {
    return memberID;
}

bool Loan::isReturned() const {
    return returned;
}

void Loan::markAsReturned() {
    returned = true;
}

void Loan::displayInfo() const {

    std::cout << "Loan ID: " << loanID << std::endl;

    std::cout << "Book ID: " << bookID << std::endl;

    std::cout << "Member ID: " << memberID << std::endl;

    std::cout << "Borrow Date: "
              << borrowDate.toString()
              << std::endl;

    std::cout << "Return Date: "
              << returnDate.toString()
              << std::endl;

    std::cout << "Status: "
              << (returned ? "Returned" : "Active")
              << std::endl;
}
