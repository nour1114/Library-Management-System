#include "Member.h"

#include <iostream>
#include <stdexcept>

Member::Member(
    const std::string& name,
    int memberID,
    const std::string& email,
    int phoneNum
)
    : User(name, memberID),
      email(email),
      phoneNum(phoneNum) {

    if (email.empty()) {
        throw std::invalid_argument("Email cannot be empty");
    }

    if (phoneNum <= 0) {
        throw std::invalid_argument("Invalid phone number");
    }
}

void Member::introduce() const {

    std::cout << "Name: " << name << std::endl;
    std::cout << "Member ID: " << memberID << std::endl;
    std::cout << "Email: " << email << std::endl;
    std::cout << "Phone Number: " << phoneNum << std::endl;
}
