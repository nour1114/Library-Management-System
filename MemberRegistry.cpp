#include "MemberRegistry.h"

#include <iostream>


// ================= MEMBER =================

void MemberRegistry::addMember(
    const Member& member
) {

    for (const Member& existingMember : members) {

        if (existingMember.getMemberID() ==
            member.getMemberID()) {

            std::cout
                << "Member ID already exists!"
                << std::endl;

            return;
        }
    }

    members.push_back(member);

    std::cout
        << "Member added successfully!"
        << std::endl;
}


void MemberRegistry::displayMembers() const {

    if (members.empty()) {

        std::cout
            << "No members available."
            << std::endl;

        return;
    }

    for (const Member& member : members) {

        member.introduce();

        std::cout
            << "--------------------"
            << std::endl;
    }
}


Member* MemberRegistry::searchMember(
    int memberID
) {

    if (memberID <= 0) {
        return nullptr;
    }

    for (Member& member : members) {

        if (member.getMemberID() == memberID) {
            return &member;
        }
    }

    return nullptr;
}


const Member* MemberRegistry::searchMember(
    int memberID
) const {

    if (memberID <= 0) {
        return nullptr;
    }

    for (const Member& member : members) {

        if (member.getMemberID() == memberID) {
            return &member;
        }
    }

    return nullptr;
}


// ================= LIBRARIAN =================

void MemberRegistry::addLibrarian(
    const Librarian& librarian
) {

    for (
        const Librarian& existingLibrarian : librarians
    ) {

        if (existingLibrarian.getMemberID() ==
            librarian.getMemberID()) {

            std::cout
                << "Librarian ID already exists!"
                << std::endl;

            return;
        }
    }

    librarians.push_back(librarian);

    std::cout
        << "Librarian added successfully!"
        << std::endl;
}


void MemberRegistry::displayLibrarians() const {

    if (librarians.empty()) {

        std::cout
            << "No librarians available."
            << std::endl;

        return;
    }

    for (
        const Librarian& librarian : librarians
    ) {

        librarian.introduce();

        std::cout
            << "--------------------"
            << std::endl;
    }
}
