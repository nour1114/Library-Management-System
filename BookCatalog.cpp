#include "BookCatalog.h"

#include <iostream>

void BookCatalog::addBook(const Book& book) {

    for (const Book& existingBook : books) {

        if (existingBook.getBookID() == book.getBookID()) {

            std::cout << "Book ID already exists!" << std::endl;

            return;
        }
    }

    books.push_back(book);

    std::cout << "Book added successfully!" << std::endl;
}


void BookCatalog::removeBook(int bookID) {

    if (bookID <= 0) {

        std::cout << "Invalid book ID!" << std::endl;

        return;
    }

    for (size_t i = 0; i < books.size(); i++) {

        if (books[i].getBookID() == bookID) {

            books.erase(books.begin() + i);

            std::cout << "Book removed successfully!" << std::endl;

            return;
        }
    }

    std::cout << "Book not found!" << std::endl;
}


Book* BookCatalog::searchBook(int bookID) {

    if (bookID <= 0) {
        return nullptr;
    }

    for (Book& book : books) {

        if (book.getBookID() == bookID) {
            return &book;
        }
    }

    return nullptr;
}


const Book* BookCatalog::searchBook(int bookID) const {

    if (bookID <= 0) {
        return nullptr;
    }

    for (const Book& book : books) {

        if (book.getBookID() == bookID) {
            return &book;
        }
    }

    return nullptr;
}


void BookCatalog::displayBooks() const {

    if (books.empty()) {

        std::cout << "No books available." << std::endl;

        return;
    }

    for (const Book& book : books) {

        book.printInfo();

        std::cout << "--------------------" << std::endl;
    }
}


int BookCatalog::getBookCount() const {

    return static_cast<int>(books.size());
}

