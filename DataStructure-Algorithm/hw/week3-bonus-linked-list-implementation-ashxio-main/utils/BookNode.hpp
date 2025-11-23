#ifndef BOOKNODE_HPP // to prevent error when include multiple time
#define BOOKNODE_HPP

#include <string>

class BookNode{
public:
    std::string title;
    std::string borrowDate;
    BookNode* next;

    // Constructor
    BookNode(std::string title, std::string borrowDate){
        // your code here
        this->title = title;
        this->borrowDate = borrowDate;
        this->next = nullptr;
    }
};

#endif