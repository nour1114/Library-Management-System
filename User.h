#ifndef USER_H
#define USER_H

#include <string>

class User {
protected:
    std::string name;
    int memberID;

public:
    User(const std::string& name, int memberID);

    int getMemberID() const;

    virtual void introduce() const = 0;

    virtual ~User() = default;
};

#endif
