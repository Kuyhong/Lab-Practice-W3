#include<iostream>
#include "../utils/node.hpp"
#ifndef NODE_HPP

void deleteWithPredecessor(Node* head) {
    Node* prev = nullptr;
    Node* cur = head;
    while (cur->next != nullptr) {
        prev = cur;
        cur = cur->next;
    }
    prev->next = nullptr;
    delete cur;  
}

void deleteWithoutPredecessor(Node* head) {
    
}
#endif