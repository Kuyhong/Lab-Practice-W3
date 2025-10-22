#ifndef SLL_HPP
#define SLL_HPP
#include "node.hpp"

//A3
class SLL {
private:
    Node* head;
    int size;

public:
    SLL(Node* head = nullptr, int size = 0) {
        this->head = head;
        this->size = size;
    }

    void append(int val) {
        Node* nNode = new Node(val, nullptr, nullptr);
        if (head == nullptr) {
            head = nNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr)
                temp = temp->next;
            temp->next = nNode;
        }
        size++;
    }

    void rotateRight(int k) {
        if (head == nullptr || k == 0 || size == 0) return;
        k = k % size;
        if (k == 0) return;

        Node* tail = head;
        int len = 1;
        while (tail->next != nullptr) {
            tail = tail->next;
            len++;
        }

        Node* newTail = head;
        for (int i = 1; i < len - k; i++)
            newTail = newTail->next;

        Node* newHead = newTail->next;
        newTail->next = nullptr;
        tail->next = head;
        head = newHead;
    }

    void print() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};


//A5
class SLL_HeadOnly {
    private:
    Node* head;
    int n;
    
    public:
    SLL_HeadOnly (Node* head, int n){
        this->head = head;
        this->n = n;
    }

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

    //A1:
    void traverse_n(int n) {
        if (head == nullptr) return;
        Node* current = head;
        for (int i = 0; i < n; i++) {
            cout << current->value << " ";
            current = current->next;
            if (current == nullptr) current = head;
        }
        cout << endl;
    }

    //A4:
    void erase_WithPredecessor(Node* predecessor, Node* target) {
        if (target == nullptr) return;

        if (predecessor == nullptr) {
            head = target->next;
        } else {
            predecessor->next = target->next;
        }

        delete target;
        n--;
    }

    void erase(Node* target) {
        if (target == nullptr || target->next == nullptr) return;

        Node* nextNode = target->next;
        target->value = nextNode->value;
        target->next = nextNode->next;
        delete nextNode;
        n--;
    }
};

class SLL_HeadTail {
    private:
    Node* tail;
    Node* head;
    int n;

    public:
    SLL_HeadTail(Node* head, Node* tail, int n){
        this->head = head;
        this->tail = tail;
        this->n = n;
    }

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
#endif 
