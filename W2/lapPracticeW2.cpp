#include <iostream>
#include <string>
#include "node.hpp"

using namespace std;

int main() {

    LinkedList list;

    list.insertFront(3);
    list.insertFront(1);
    list.print();
    cout << "the size of list is : " << list.getSize() << endl;
    cout << "the tail of the list is : " << list.getTail() << endl;
    cout << "the head of the list is : " << list.getHead() << endl;

    return 0;
}