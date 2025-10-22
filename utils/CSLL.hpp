#ifndef CSLL_HPP
#define CSLL_HPP
#include <iostream>
#include "node.hpp"

class CSLL {
private:
    Node* head = nullptr;
    Node* tail = nullptr;
    int n = 0;

public:
    //A1:
    void push_Back(int value) {
        Node* nNode = new Node(value, nullptr, nullptr);
        if (head == nullptr) {
            head = tail = nNode;
            tail->next = head;
        } else {
            tail->next = nNode;
            tail = nNode;
            tail->next = head;
        }
        n++;
    }

    void traverse_n(int steps) {
        if (head == nullptr) return;
        Node* current = head;
        for (int i = 0; i < steps; i++) {
            cout << current->value << " ";
            current = current->next;
        }
        cout << endl;
    }

    //A2:
    void deleteWithPredecessor(Node*& head) {
        if (head == nullptr){
            return;
        }
        Node* prev = nullptr;
        Node* cur = head;
        while (cur->next != nullptr) {
            prev = cur;
            cur = cur->next;
        }
        if (prev == nullptr) {
            delete head;
            head = nullptr;
        } else {
            prev->next = nullptr;
            delete cur;
        }
    }

    void deleteWithoutPredecessor(Node* target) {
        if (target == nullptr || target->next == nullptr){
            return;
        }
        Node* nextNode = target->next;
        target->value = nextNode->value;
        target->next = nextNode->next;
        delete nextNode;
    }

    //A3:
    void append(int val) {
        Node* nNode = new Node(val, nullptr, nullptr);
        if (head == nullptr) {
            head = nNode;
            nNode->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head)
                temp = temp->next;
            temp->next = nNode;
            nNode->next = head;
        }
        n++;
    }

    void rotateRight(int k) {
        if (head == nullptr || k == 0 || n == 0){
            return;
        } 
        k = k % n;
        if (k == 0) {
            return;
        }
        int moveSteps = n - k;
        Node* tail = head;
        for (int i = 0; i < moveSteps - 1; i++){
            tail = tail->next;
        }
        head = tail->next;
    }

    void print() {
        if (head == nullptr){
            return;
        }
        Node* temp = head;
        do {
            cout << temp->value << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};

#endif