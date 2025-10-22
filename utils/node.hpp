
#include <iostream>
using namespace std;

class Node{
    public: 
    int value;
    Node* next;
    Node* prev;

    public:
    Node (int value, Node* next, Node* prev){
        this->value = value;
        this->next = next;
        this->prev = prev;
    }
};


