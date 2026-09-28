#ifndef LIBRARY_H
#define LIBRARY_H

#include "BookCatalog.h"
#include "MemberRegistry.h"
#include "LoanManager.h"

class Library {
private:
    BookCatalog bookCatalog;
    MemberRegistry memberRegistry;
    LoanManager loanManager;

public:

    // ================= BOOK =================

    void addBook(const Book& book);
    void removeBook(int bookID);

    Book* searchBook(int bookID);
    const Book* searchBook(int bookID) const;

    void displayBooks() const;
    int getBookCount() const;


    // ================= MEMBER =================

    void addMember(const Member& member);

    void displayMembers() const;

    Member* searchMember(int memberID);
    const Member* searchMember(int memberID) const;


    // ================= LIBRARIAN =================

    void addLibrarian(const Librarian& librarian);

    void displayLibrarians() const;


    // ================= LOAN =================

    void borrowBook(
        int memberID,
        int bookID,
        const Date& borrowDate,
        const Date& returnDate
    );

    void returnBook(int loanID);

    void displayLoans() const;

    Loan* searchLoan(int loanID);
    const Loan* searchLoan(int loanID) const;

    void displayMemberLoans(int memberID) const;
};

#endif
