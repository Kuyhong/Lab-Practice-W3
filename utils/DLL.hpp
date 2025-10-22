#ifndef DLL_HPP
#define DLL_HPP
#include <iostream>
#include "node.hpp"
using namespace std;

//A5
class DLL_HeadTail {
    private:
    Node* head;
    Node* tail;
    int n;

    public:
    DLL_HeadTail (Node* head, Node* tail, int n){
        this->head = head;
        this->tail = tail;
        this->n = n;
    }

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

    //A4:
    void erase(Node* target) {
        if (target == nullptr) return;

        if (target == head) {
            head = head->next;
            if (head) head->prev = nullptr;
            else tail = nullptr;
        } else if (target == tail) {
            tail = tail->prev;
            if (tail) tail->next = nullptr;
            else head = nullptr;
        } else {
            target->prev->next = target->next;
            target->next->prev = target->prev;
        }

        delete target;
        n--;
    }
};
#endif