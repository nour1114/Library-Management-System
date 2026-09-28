#include "User.h"

#include <stdexcept>

User::User(const std::string& name, int memberID)
    : name(name),
      memberID(memberID) {

    if (name.empty()) {
        throw std::invalid_argument("Name cannot be empty");
    }

    if (memberID <= 0) {
        throw std::invalid_argument("Invalid member ID");
    }
}

int User::getMemberID() const {
    return memberID;
}
