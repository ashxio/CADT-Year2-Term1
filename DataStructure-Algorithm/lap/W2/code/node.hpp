#include <iostream>

using namespace std;

struct Node{
    int value;
    Node* next;
};

class LinkedList{
    private:
        Node* head, *tail, *current;
        int size;
        
    public: 
    LinkedList(){
        head = nullptr;
        tail = nullptr;
        size = 0;
    }
    int getSize() { return size; }
    int getHead(){
        if (!head) {
            cout << "List is empty!" << endl;
            return -1;
        }
        return head->value;
    }
    int getTail(){
        if (!tail) {
            cout << "List is empty!" << endl;
            return -1;
        }
        return tail->value;
    }

    // ------ Functions ------
    void _traverseToTail(){
        current = head;
        while(current->next){
            current = current->next;
        }
    }

    void _traverseToPos(int pos){
        if (pos < 0 || pos >= size || size == 0) {
            cout << "Traversal error!"<< endl;
            return;
        }
        current = head;
        for (int i=0; i<pos; i++){
            current = current->next;
        }
    }
    // Challenge 1: Insert at the Front
    void insertFront(int value){
        Node* newNode = new Node{value, nullptr};
        newNode->next = head;
        head = newNode;
        size++;
        // tail update in case of first insertion
        if (size == 1) tail = head;
    }
    
    // Challenge 2: Insert at the End
    void insertEnd(int value){
        if (size==0){
            insertFront(value);
            return;
        }
        Node* newNode = new Node{value, nullptr};
        tail->next = newNode;
        tail = newNode;
        size++;
    }
    //  Challenge 3: Insert at the Middle
    void insertMiddle(int value){
        if (size==0){
            insertFront(value);
            return;
        }
        // cus mid = 0 when size = 1, mid - 1 will crash
        if (size == 1) {
            Node* newNode = new Node{value, nullptr};
            newNode->next = head->next;
            head->next = newNode;
            tail = newNode;
            size++;
            return;
        }
        Node* newNode = new Node{value, nullptr};
        int mid = size / 2;
        _traverseToPos(mid-1);
        newNode->next = current->next;
        current->next = newNode;
        if (newNode->next == nullptr)tail = newNode;
        size++;
        
    }
    // Extra Challenge: Insert at any Position
    void insertAtPos(int pos, int value){
        // position is 0, insert at front
        if (pos==0){
            insertFront(value);
            return;
        }
        // position is equal to size, insert at end
        if (pos==size){
            insertEnd(value);
            return;
        }
        // position is invalid
        if (pos < 0 || pos > size)
        {
            cout << "Invalid position!" << endl;
            return;
        }
        // anywhere else
        Node* newNode = new Node{value, nullptr};
        _traverseToPos(pos-1);
        newNode->next = current->next;
        current->next = newNode;
        if (newNode->next == nullptr) tail = newNode;
        size++;
    }
    // Challenge 4: Delete at the Front
    void deleteFront(){
        if (size==0 || head==nullptr){
            cout << "List is empty!" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        size--;
        if (size==0 || head==nullptr){
            tail = nullptr;
        }
    }
    // Challenge 5: Delete from the End
    void deleteEnd(){
        if (size==0 || head==nullptr){
            cout << "List is empty!" << endl;
            return;
        }
        if (size==1){
            deleteFront();
            return;
        }
        _traverseToPos(size-2);
        Node* temp = current->next;
        current->next = nullptr;
        tail = current;
        delete temp;
        size--;
    }
    // Challenge 6: Delete in the Middle
    void deleteMiddle(){
        if (size==0 || head==nullptr){
            cout << "List is empty!" << endl;
            return;
        }
        if (size==1){
            deleteFront();
            return;
        }
        _traverseToPos((size/2)-1);
        Node* temp = current->next;
        current->next = temp->next;
        delete temp;
        if (current->next == nullptr) tail = current;
        size--;
    }
    // Extra Challenge: Delete at any Position
    void deleteAtPos(int pos){
        if (size==0 || head==nullptr){
            cout << "List is empty!" << endl;
            return;
        }
        // position is 0, delete at front
        if (pos==0){
            deleteFront();
            return;
        }
        // position is equal to size-1, delete at end
        if (pos==size-1){
            deleteEnd();
            return;
        }
        // position is invalid
        if (pos < 0 || pos >= size)
        {
        cout << "Invalid position!" << endl;
        return;
        }
        // anywhere else
        _traverseToPos(pos-1);
        Node* temp = current->next;
        current->next = temp->next;
        delete temp;
        size--;
    }
    // Challenge 7: Traverse the list and print 
    void print() {
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }
        current = head;
        while (current) {
            cout << current->value << "->";
            current = current->next;
        }
        cout << "nullptr" << endl;
    }
    // Challenge 8: Swap two nodes
    void swapTwoNodes(int pos1, int pos2) {
        // invalid cases
        if (!head || size < 2) {
            cout << "Error! List too small/empty." << endl;
            return;
        }
        if (pos1 < 0 || pos1 >= size || pos2 < 0 || pos2 >= size) {
            cout << "Invalid positions!" << endl;
            return;
        }
        if (pos1 == pos2) {
            cout << "Same positions." << endl;
            return;
        }

    // Normalize positions
        if (pos1 > pos2) swap(pos1, pos2);

    // Find first node
        Node* prev1 = nullptr;
        Node* first = head;
        if (pos1 != 0) {
            _traverseToPos(pos1 - 1);
            prev1 = current;
            first = current->next;
        }

    // Find second node
        Node* prev2 = nullptr;
        Node* second = head;
        if (pos2 != 0) {
            _traverseToPos(pos2 - 1);
            prev2 = current;
            second = current->next;
        }

    // Swap nodes
        if (first->next == second) {
            if (prev1) prev1->next = second; else head = second;
            first->next = second->next;
            second->next = first;
        } else {
            if (prev1) prev1->next = second; else head = second;
            if (prev2) prev2->next = first; else head = first;
            Node* temp = first->next;
            first->next = second->next;
            second->next = temp;
        }

    // Update tail
        if (first->next == nullptr) tail = first;
        if (second->next == nullptr) tail = second;
    }
    // Challenge 9: Search in Linked List
    bool search(int value) {
        current = head;
        while (current) {
            if (current->value == value) {
                return true;
            }
            current = current->next;
        }
        return false;
    }
};