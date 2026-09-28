#include "Library.h"

#include <iostream>


// ================= BOOK =================

void Library::addBook(
    const Book& book
) {

    bookCatalog.addBook(book);
}


void Library::removeBook(
    int bookID
) {

    if (loanManager.isBookBorrowed(bookID)) {

        std::cout
            << "Book cannot be removed because "
               "it is currently borrowed!"
            << std::endl;

        return;
    }

    bookCatalog.removeBook(bookID);
}


Book* Library::searchBook(
    int bookID
) {

    return bookCatalog.searchBook(bookID);
}


const Book* Library::searchBook(
    int bookID
) const {

    return bookCatalog.searchBook(bookID);
}


void Library::displayBooks() const {

    bookCatalog.displayBooks();
}


int Library::getBookCount() const {

    return bookCatalog.getBookCount();
}


// ================= MEMBER =================

void Library::addMember(
    const Member& member
) {

    memberRegistry.addMember(member);
}


void Library::displayMembers() const {

    memberRegistry.displayMembers();
}


Member* Library::searchMember(
    int memberID
) {

    return memberRegistry.searchMember(memberID);
}


const Member* Library::searchMember(
    int memberID
) const {

    return memberRegistry.searchMember(memberID);
}


// ================= LIBRARIAN =================

void Library::addLibrarian(
    const Librarian& librarian
) {

    memberRegistry.addLibrarian(librarian);
}


void Library::displayLibrarians() const {

    memberRegistry.displayLibrarians();
}


// ================= LOAN =================

void Library::borrowBook(
    int memberID,
    int bookID,
    const Date& borrowDate,
    const Date& returnDate
) {

    loanManager.borrowBook(
        memberID,
        bookID,
        borrowDate,
        returnDate,
        bookCatalog,
        memberRegistry
    );
}


void Library::returnBook(
    int loanID
) {

    loanManager.returnBook(loanID);
}


void Library::displayLoans() const {

    loanManager.displayLoans();
}


Loan* Library::searchLoan(
    int loanID
) {

    return loanManager.searchLoan(loanID);
}


const Loan* Library::searchLoan(
    int loanID
) const {

    return loanManager.searchLoan(loanID);
}


void Library::displayMemberLoans(
    int memberID
) const {

    loanManager.displayMemberLoans(memberID);
}
