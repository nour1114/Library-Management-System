#include <iostream>
#include <stdexcept>

#include "Book.h"
#include "Loan.h"
#include "Date.h"
#include "Member.h"
#include "Librarian.h"
#include "Library.h"

using namespace std;


int main() {

    // =========================================================
    // CREATE USERS
    // =========================================================

    Member user1(
        "Nour Ali",
        1114,
        "nourelsali2006@gmail.com",
        1157548083
    );

    Member user2(
        "Ahmed",
        2222,
        "ahmed@gmail.com",
        123456789
    );

    Librarian librarian1(
        "Yassen Elsayed",
        2228
    );


    // =========================================================
    // CREATE BOOKS
    // =========================================================

    Book book1(
        "Harry Potter 1",
        "J.K. Rowling",
        250,
        1001
    );

    Book book2(
        "Animal Farm",
        "George Orwell",
        150,
        1002
    );

    Book book3(
        "1984",
        "George Orwell",
        200,
        1003
    );


    // =========================================================
    // CREATE LIBRARY
    // =========================================================

    Library library;


    // =========================================================
    // CREATE DATES
    // =========================================================

    Date borrowDate(
        2026,
        9,
        20
    );

    Date returnDate(
        2026,
        10,
        5
    );

    Date invalidBorrowDate(
        2026,
        10,
        5
    );

    Date invalidReturnDate(
        2026,
        9,
        20
    );


    // =========================================================
    // ADD DATA
    // =========================================================

    library.addBook(book1);
    library.addBook(book2);
    library.addBook(book3);

    library.addMember(user1);
    library.addMember(user2);

    library.addLibrarian(librarian1);


    // =========================================================
    // DISPLAY INITIAL DATA
    // =========================================================

    cout << "\n========== MEMBERS ==========\n";

    library.displayMembers();


    cout << "\n========== LIBRARIANS ==========\n";

    library.displayLibrarians();


    cout << "\n========== BOOKS ==========\n";

    library.displayBooks();


    // =========================================================
    // TESTING
    // =========================================================

    cout << "\n========== TESTING ==========\n";


    // =========================================================
    // Test 1: Valid borrow
    // =========================================================

    cout << "\nTest 1: Valid borrow\n";

    library.borrowBook(
        1114,
        1001,
        borrowDate,
        returnDate
    );


    // =========================================================
    // Test 2: Remove borrowed book
    // =========================================================

    cout << "\nTest 2: Remove borrowed book\n";

    library.removeBook(1001);


    // =========================================================
    // Test 3: Return borrowed book
    // =========================================================

    cout << "\nTest 3: Return borrowed book\n";

    library.returnBook(1);


    // =========================================================
    // Test 4: Return non-existing loan
    // =========================================================

    cout << "\nTest 4: Return non-existing loan\n";

    library.returnBook(9999);


    // =========================================================
    // Test 5: Double return
    // =========================================================

    cout << "\nTest 5: Return already returned loan\n";

    library.returnBook(1);


    // =========================================================
    // Test 6: Borrow again after return
    // =========================================================

    cout << "\nTest 6: Borrow again after return\n";

    library.borrowBook(
        1114,
        1001,
        borrowDate,
        returnDate
    );


    // =========================================================
    // Test 7: Valid borrow for another member
    // =========================================================

    cout << "\nTest 7: Valid borrow for another member\n";

    library.borrowBook(
        2222,
        1003,
        borrowDate,
        returnDate
    );


    // =========================================================
    // Test 8: Book is already borrowed
    // =========================================================

    cout << "\nTest 8: Book is already borrowed\n";

    library.borrowBook(
        2222,
        1001,
        borrowDate,
        returnDate
    );


    // =========================================================
    // Test 9: Member does not exist
    // =========================================================

    cout << "\nTest 9: Member does not exist\n";

    library.borrowBook(
        9999,
        1002,
        borrowDate,
        returnDate
    );


    // =========================================================
    // Test 10: Book does not exist
    // =========================================================

    cout << "\nTest 10: Book does not exist\n";

    library.borrowBook(
        1114,
        9999,
        borrowDate,
        returnDate
    );


    // =========================================================
    // Test 11: Invalid loan dates
    // =========================================================

    cout << "\nTest 11: Invalid loan dates\n";

    library.borrowBook(
        1114,
        1002,
        invalidBorrowDate,
        invalidReturnDate
    );


    // =========================================================
    // Test 12: Remove available book
    // =========================================================

    cout << "\nTest 12: Remove available book\n";

    library.removeBook(1002);


    // =========================================================
    // Test 13: Remove non-existing book
    // =========================================================

    cout << "\nTest 13: Remove non-existing book\n";

    library.removeBook(9999);


    // =========================================================
    // Test 14: Search existing book
    // =========================================================

    cout << "\nTest 14: Search existing book\n";

    Book* result = library.searchBook(1003);

    if (result != nullptr) {

        cout << "Book found:\n";

        result->printInfo();
    }
    else {

        cout << "Book not found\n";
    }


    // =========================================================
    // Test 15: Search non-existing book
    // =========================================================

    cout << "\nTest 15: Search non-existing book\n";

    result = library.searchBook(9999);

    if (result != nullptr) {

        result->printInfo();
    }
    else {

        cout << "Book not found\n";
    }


    // =========================================================
    // Test 16: Display member loans
    // =========================================================

    cout << "\nTest 16: Display member loans\n";

    library.displayMemberLoans(2222);


    // =========================================================
    // Test 17: Member with no active loans
    // =========================================================

    cout << "\nTest 17: Member with no active loans\n";

    library.returnBook(2);

    library.displayMemberLoans(1114);


    // =========================================================
    // Test 18: Invalid price
    // =========================================================

    cout << "\nTest 18: Invalid price\n";

    try {

        book1.setPrice(-100);
    }
    catch (const invalid_argument& e) {

        cout << e.what() << endl;
    }


    // =========================================================
    // Test 19: Book count
    // =========================================================

    cout << "\nTest 19: Book count\n";

    cout << "Number of books: "
         << library.getBookCount()
         << endl;


    // =========================================================
    // Test 20: Duplicate book ID
    // =========================================================

    cout << "\nTest 20: Duplicate book ID\n";

    Book duplicateBook(
        "Dune",
        "Frank Herbert",
        300,
        1001
    );

    library.addBook(duplicateBook);


    // =========================================================
    // Test 21: Duplicate member ID
    // =========================================================

    cout << "\nTest 21: Duplicate member ID\n";

    Member duplicateMember(
        "Mona",
        1114,
        "mona@gmail.com",
        1000000000
    );

    library.addMember(duplicateMember);


    // =========================================================
    // Test 22: Duplicate librarian ID
    // =========================================================

    cout << "\nTest 22: Duplicate librarian ID\n";

    Librarian duplicateLibrarian(
        "Mona",
        2228
    );

    library.addLibrarian(duplicateLibrarian);


    // =========================================================
    // Test 23: Invalid date object
    // =========================================================

    cout << "\nTest 23: Invalid date object\n";

    try {

        Date invalidDate(
            2026,
            2,
            30
        );
    }
    catch (const invalid_argument& e) {

        cout << e.what() << endl;
    }


    // =========================================================
    // Test 24: Invalid book ID
    // =========================================================

    cout << "\nTest 24: Invalid book ID\n";

    try {

        Book invalidBook(
            "Invalid Book",
            "Unknown Author",
            100,
            -1
        );
    }
    catch (const invalid_argument& e) {

        cout << e.what() << endl;
    }


    // =========================================================
    // Test 25: Invalid member ID
    // =========================================================

    cout << "\nTest 25: Invalid member ID\n";

    try {

        Member invalidMember(
            "Test Member",
            -1,
            "test@gmail.com",
            123456789
        );
    }
    catch (const invalid_argument& e) {

        cout << e.what() << endl;
    }


    // =========================================================
    // Test 26: Invalid librarian ID
    // =========================================================

    cout << "\nTest 26: Invalid librarian ID\n";

    try {

        Librarian invalidLibrarian(
            "Test Librarian",
            0
        );
    }
    catch (const invalid_argument& e) {

        cout << e.what() << endl;
    }


    // =========================================================
    // Test 27: Invalid loan ID
    // =========================================================

    cout << "\nTest 27: Invalid loan ID\n";

    try {

        Loan invalidLoan(
            0,
            1001,
            1114,
            borrowDate,
            returnDate
        );
    }
    catch (const invalid_argument& e) {

        cout << e.what() << endl;
    }


    // =========================================================
    // Test 28: Search existing loan
    // =========================================================

    cout << "\nTest 28: Search existing loan\n";

    Loan* loanResult = library.searchLoan(3);

    if (loanResult != nullptr) {

        cout << "Loan found:\n";

        loanResult->displayInfo();
    }
    else {

        cout << "Loan not found\n";
    }


    // =========================================================
    // Test 29: Search non-existing loan
    // =========================================================

    cout << "\nTest 29: Search non-existing loan\n";

    Loan* loanResult2 = library.searchLoan(999);

    if (loanResult2 != nullptr) {

        loanResult2->displayInfo();
    }
    else {

        cout << "Loan not found\n";
    }


    // =========================================================
    // Test 30: Invalid search ID
    // =========================================================

    cout << "\nTest 30: Invalid search ID\n";

    result = library.searchBook(-1);

    if (result == nullptr) {

        cout << "Invalid book ID handled successfully."
             << endl;
    }


    // =========================================================
    // FINAL LOANS
    // =========================================================

    cout << "\n========== FINAL LOANS ==========\n";

    library.displayLoans();


    // =========================================================
    // CURRENT BOOKS
    // =========================================================

    cout << "\n========== CURRENT BOOKS ==========\n";

    library.displayBooks();


    return 0;
}
