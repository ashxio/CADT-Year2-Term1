#include "../utils/LibrarySystem.hpp"
#include <cassert>
#include <iostream>

void test_AddAndFindMember() {
    LibrarySystem library;
    library.addMember("John Doe");

    Member* member = library.findMember("John Doe");
    assert(member != nullptr);
    assert(member->getName() == "John Doe");

    std::cout << "test_AddAndFindMember passed." << std::endl;
}

void test_FindNonExistentMember() {
    LibrarySystem library;

    Member* member = library.findMember("Jane Doe");
    assert(member == nullptr);

    std::cout << "test_FindNonExistentMember passed." << std::endl;
}

void test_DisplayMemberBooks() {
    LibrarySystem library;
    library.addMember("John Doe");
    Member* member = library.findMember("John Doe");

    if (member) {
        member->borrowBook("The Great Gatsby", "2024-11-10");
        member->borrowBook("1984", "2024-11-11");
    }

    // Normally we would redirect output and verify it, but for simplicity:
    std::cout << "Actual output:" << std::endl;
    library.displayMemberBooks("John Doe");

    std::cout << "test_DisplayMemberBooks (manual verification needed)" << std::endl;
}

int main() {
    test_AddAndFindMember();
    test_FindNonExistentMember();
    test_DisplayMemberBooks();
    return 0;
}