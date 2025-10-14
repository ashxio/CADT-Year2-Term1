#include <iostream>

using namespace std;

struct Node{
    int val;
    Node* next;
};
class LinkedList{
    //properties
    private:
        Node* head, *cur;
        int n;
        
    //constructors
    public: 
    LinkedList(){
        head = nullptr;
        n = 0;
    }
    int size(){return n;}
    
    //Challenge 1: Insert at the Front
    void insertFront(int val){
        Node* nNode = new Node{val, nullptr};
        nNode->next = head;
        head = nNode;
        n++;
    }
    
    void _traverse(){
        cur = head;
        while(cur->next){
            cur = cur->next;
        }
    }
    void insertEnd(int val){
        if (n==0){
            insertFront(val);
            return;
        }
        _traverse();
        Node* nNode = new Node{val, nullptr};
        cur->next = nNode;
        n++;
    }


    void print(){
        cur = head;
        while(cur){
        cout<<cur->val<<"->";
        cur = cur->next;
        }
    }
};