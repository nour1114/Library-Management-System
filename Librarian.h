#ifndef LIBRARIAN_H
#define LIBRARIAN_H

#include <string>

#include "User.h"

class Librarian : public User {
public:
    Librarian(
        const std::string& name,
        int memberID
    );

    void introduce() const override;
};

#endif
