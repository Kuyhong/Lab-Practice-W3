
#include <iostream>
using namespace std;

class Node {
public: 
    int value;
    Node* next;
    Node* prev;

    Node(int value, Node* next = nullptr, Node* prev = nullptr) {
        this->value = value;
        this->next = next;
        this->prev = prev;
    }
};
