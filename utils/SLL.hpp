#ifndef SLL_HPP
#define SLL_HPP
#include "node.hpp"

class SLL_HeadOnly {
    Node* head = nullptr;
    int n = 0;
    
    void push_Front(int value){
        Node* nNode = new Node(value, nullptr, nullptr);
        nNode->next = head;
        head = nNode;
        n++;
    }

    void pop_Front(){
        if (head == nullptr){
            return;
        }
        Node* temp = head;
        head = temp->next;
        delete temp;
        n--;
    }

    void push_Back(int value){
        Node* nNode = new Node(value, nullptr, nullptr);
        if (head == nullptr){
            nNode->next = head;
            head = nNode;
            n++;
            return;
        }
        Node* current = head;
        while (current->next != nullptr){
            current = current->next;
        }
        current->next = nNode;
        n++;
    }

    void pop_Back(){
        if (head == nullptr){
            return;
        }

        if (head->next == nullptr){
            delete head;
            head = nullptr;
            n--;
            return;
        }
        Node* current = head;
        while (current->next->next != nullptr){
            current = current->next;
        }
        Node* temp = current->next;
        current->next = nullptr;
        delete temp;
        n--;
    }
};

#endif // SLL_HPP