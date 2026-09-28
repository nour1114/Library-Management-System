#ifndef BOOKCATALOG_H
#define BOOKCATALOG_H

#include <vector>

#include "Book.h"

class BookCatalog {
private:
    std::vector<Book> books;

public:
    void addBook(const Book& book);
    void removeBook(int bookID);

    Book* searchBook(int bookID);
    const Book* searchBook(int bookID) const;

    void displayBooks() const;
    int getBookCount() const;
};

#endif
