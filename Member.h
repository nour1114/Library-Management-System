#ifndef MEMBER_H
#define MEMBER_H

#include <string>

#include "User.h"

class Member : public User {
private:
    std::string email;
    int phoneNum;

public:
    Member(
        const std::string& name,
        int memberID,
        const std::string& email,
        int phoneNum
    );

    void introduce() const override;
};

#endif
