#ifndef BOOK_H
#define BOOK_H

#include <string>

#include "Printable.h"

class Book : public Printable {
private:
    std::string title;
    std::string author;
    int price;
    int bookID;

public:
    Book(
        const std::string& title,
        const std::string& author,
        int price,
        int bookID
    );

    const std::string& getTitle() const;
    const std::string& getAuthor() const;

    void setPrice(int price);

    int getPrice() const;
    int getBookID() const;

    void printInfo() const override;
};

#endif
