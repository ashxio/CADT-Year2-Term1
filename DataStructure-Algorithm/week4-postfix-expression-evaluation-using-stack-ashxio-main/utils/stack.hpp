
#include <stdexcept>

#ifndef STACK
#define STACK

using namespace std;

struct Node {
    float number;
    Node *next;
};

class Stack{
    // complete the Stack ADT here
private:
    Node *top;
    float n;
public:
    Stack() {
        top = nullptr;
        n = 0;
    }

    float peek() {
        if(n == 0) {
            cout << "it's empty" << endl;
            return 0;
        }

        return top->num;
    }

    void push(float num) {
        Node *newNode = new Node{num, top};
        top = newNode;
        n++ ;
    }

    float pop() {
        if(n == 0) {
            cout << "it's empty" << endl;
            return 0;
        }

        Node *temp = top;
        float val = top->num;
        top = top->next;
        n-- ;
        delete temp;
        return val;
    }

    void print() {
        Node *current = top;
        while(current !=  nullptr) {
            cout << current->num;
            if(current->next != nullptr) cout << " -> " ;
            current = current->next;
        }

        cout<<endl;
    }

    bool isEmpty() {return n==0;}

};

#endif