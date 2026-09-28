#ifndef MEMBERREGISTRY_H
#define MEMBERREGISTRY_H

#include <vector>

#include "Member.h"
#include "Librarian.h"

class MemberRegistry {
private:
    std::vector<Member> members;
    std::vector<Librarian> librarians;

public:

    // ================= MEMBER =================

    void addMember(const Member& member);

    void displayMembers() const;

    Member* searchMember(int memberID);
    const Member* searchMember(int memberID) const;


    // ================= LIBRARIAN =================

    void addLibrarian(const Librarian& librarian);

    void displayLibrarians() const;
};

#endif
