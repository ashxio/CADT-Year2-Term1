#include "../utils/Member.hpp"
#include <cassert>
#include <iostream>

void test_MemberBorrowBook() {
    Member member("John Doe");

    member.borrowBook("The Great Gatsby", "2024-11-10");
    member.borrowBook("1984", "2024-11-11");

    // Checking the first book
    BookNode* firstBook = member.getFirstBook();
    assert(firstBook->title == "The Great Gatsby");
    assert(firstBook->borrowDate == "2024-11-10");

    // Checking the second book
    assert(firstBook->next->title == "1984");
    assert(firstBook->next->borrowDate == "2024-11-11");

    std::cout << "test_MemberBorrowBook passed." << std::endl;
}

void test_MemberReturnBook() {
    Member member("John Doe");

    member.borrowBook("The Great Gatsby", "2024-11-10");
    member.borrowBook("1984", "2024-11-11");
    member.returnBook("The Great Gatsby");

    // Only the second book should remain
    BookNode* firstBook = member.getFirstBook();
    assert(firstBook->title == "1984");

    std::cout << "test_MemberReturnBook passed." << std::endl;
}

void test_MemberReturnNonExistentBook() {
    Member member("John Doe");

    member.borrowBook("The Great Gatsby", "2024-11-10");
    member.returnBook("Non-Existent Book");

    // The borrowed book list should remain unchanged
    BookNode* firstBook = member.getFirstBook();
    assert(firstBook->title == "The Great Gatsby");

    std::cout << "test_MemberReturnNonExistentBook passed." << std::endl;
}

int main() {
    test_MemberBorrowBook();
    test_MemberReturnBook();
    test_MemberReturnNonExistentBook();
    return 0;
}