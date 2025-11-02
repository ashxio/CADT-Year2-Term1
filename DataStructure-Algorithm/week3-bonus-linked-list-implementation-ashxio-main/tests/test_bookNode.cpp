#include "../utils/BookNode.hpp"
#include <cassert>

void test_BookNodeCreation(){
    BookNode node("123", "2024-1-1");
    assert(node.title == "123");
    assert(node.borrowDate == "2024-1-1");
    assert(node.next == nullptr);
}

int main(){
    test_BookNodeCreation();
    return 0;
}