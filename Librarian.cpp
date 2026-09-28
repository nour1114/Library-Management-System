#include "Librarian.h"

#include <iostream>

Librarian::Librarian(
    const std::string& name,
    int memberID
)
    : User(name, memberID) {
}

void Librarian::introduce() const {

    std::cout << "Name: " << name << std::endl;
    std::cout << "Member ID: " << memberID << std::endl;
}
