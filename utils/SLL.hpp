#ifndef SLL_HPP
#define SLL_HPP
#include "node.hpp"

//A5
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

class SLL_HeadTail {
    Node* tail = nullptr;
    Node* head = nullptr;
    int n = 0;

    void push_Front(int value){
        Node* nNode = new Node(value, nullptr, nullptr);
        if (head == nullptr){
            head = tail = nNode;
        } else {
            nNode->next = head;
            head = nNode;
        }
        n++;
    }

    void pop_Front(){
        Node* temp = head;
        if (head == nullptr){
            return;
        }
        if (head == tail){
            tail = nullptr;
            head = nullptr;
            delete temp;
        } else {
            head = temp->next;
            delete temp;
        }
        n--;
    }

    void push_Back(int value){
        Node* nNode = new Node(value, nullptr, nullptr);
        if (head == nullptr){
            head = tail = nNode;
        } else {
            tail->next = nNode;
            tail = nNode; 
        }
    }

    void pop_Back(){
        if (head == nullptr){
            return;
        } else if (head == tail){
            delete head;
            head = nullptr;
            tail = nullptr;
        } else {
            Node* current = head;
            while (current->next->next != nullptr){
                current = current->next;
            }
            current->next = nullptr;
            delete tail;
            tail = current;
        }
        n--;
    }
};

class DLL_HeadTail {
    public:
    Node* head = nullptr;
    Node* tail = nullptr;
    int n = 0;

    void push_Front(int value) {
        Node* nNode = new Node(value, nullptr, nullptr);
        if (head == nullptr) {
            head = tail = nNode;
        } else {
            head->prev = nNode;
            nNode->next = head;
            nNode->prev = nullptr;
            head = nNode;
        }
        n++;
    }

    void pop_Front() {
        if (head == nullptr) return;
        Node* temp = head;
        if (head == tail) {
            head = tail = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
        n--;
    }

    void push_Back(int value) {
        Node* nNode = new Node(value, nullptr, nullptr);
        if (tail == nullptr) {
            head = tail = nNode;
        } else {
            tail->next = nNode;
            nNode->prev = tail;
            tail = nNode;
        }
        n++;
    }

    void pop_Back() {
        if (tail == nullptr) return;
        Node* temp = tail;
        if (head == tail) {
            head = tail = nullptr;
        } else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete temp;
        n--;
    }
};
#endif 
