#include "Book.h"

#include <iostream>
#include <stdexcept>

Book::Book(
    const std::string& title,
    const std::string& author,
    int price,
    int bookID
)
    : title(title),
      author(author),
      price(price),
      bookID(bookID) {

    if (title.empty()) {
        throw std::invalid_argument("Book title cannot be empty");
    }

    if (author.empty()) {
        throw std::invalid_argument("Book author cannot be empty");
    }

    if (price < 0) {
        throw std::invalid_argument("Invalid price");
    }

    if (bookID <= 0) {
        throw std::invalid_argument("Invalid book ID");
    }
}

const std::string& Book::getTitle() const {
    return title;
}

const std::string& Book::getAuthor() const {
    return author;
}

void Book::setPrice(int price) {

    if (price < 0) {
        throw std::invalid_argument("Invalid price");
    }

    this->price = price;
}

int Book::getPrice() const {
    return price;
}

int Book::getBookID() const {
    return bookID;
}

void Book::printInfo() const {

    std::cout << "Title: " << title << std::endl;
    std::cout << "Author: " << author << std::endl;
    std::cout << "Price: " << price << std::endl;
    std::cout << "Book ID: " << bookID << std::endl;
}
