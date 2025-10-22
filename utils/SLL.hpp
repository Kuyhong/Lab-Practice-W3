<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 9174eb4e4deb94c6e6543ae8d0a492054dea3034
// Singly and doubly linked list utilities for benchmarks
#ifndef SLL_HPP
#define SLL_HPP

#include <string>
#include <chrono>
#include <iostream>

struct SLLNode {
    int val;
    SLLNode* next;
    SLLNode(int v) : val(v), next(nullptr) {}
};

struct SLL_HeadOnly {
    SLLNode* head = nullptr;

    void push_front(int v) {
        SLLNode* node = new SLLNode(v);
        node->next = head;
        head = node;
    }

    void pop_front() {
        if (!head) return;
        SLLNode* tmp = head;
        head = head->next;
        delete tmp;
    }

    void push_back(int v) {
        SLLNode* node = new SLLNode(v);
        if (!head) { head = node; return; }
        SLLNode* cur = head;
        while (cur->next) cur = cur->next;   // O(n)
        cur->next = node;
    }

    void pop_back() {
        if (!head) return;
        if (!head->next) { delete head; head = nullptr; return; }
        SLLNode* cur = head;
        while (cur->next->next) cur = cur->next;  // O(n)
        delete cur->next;
        cur->next = nullptr;
    }
};

struct SLL_HeadTail {
    SLLNode* head = nullptr;
    SLLNode* tail = nullptr;

    void push_front(int v) {
        SLLNode* node = new SLLNode(v);
        if (!head) head = tail = node;
        else { node->next = head; head = node; }
    }

    void pop_front() {
        if (!head) return;
        SLLNode* tmp = head;
        head = head->next;
        if (!head) tail = nullptr;
        delete tmp;
    }

    void push_back(int v) {
        SLLNode* node = new SLLNode(v);
        if (!tail) head = tail = node;
        else { tail->next = node; tail = node; }
    }

    void pop_back() {
        if (!head) return;
        if (head == tail) { delete head; head = tail = nullptr; return; }
        SLLNode* cur = head;
        while (cur->next != tail) cur = cur->next;
        delete tail;
        tail = cur;
        tail->next = nullptr;
    }
};

struct DLLNode {
    int val;
    DLLNode* next;
    DLLNode* prev;
    DLLNode(int v) : val(v), next(nullptr), prev(nullptr) {}
};

struct DLL_HeadTail {
    DLLNode* head = nullptr;
    DLLNode* tail = nullptr;

    void push_front(int v) {
        DLLNode* node = new DLLNode(v);
        node->next = head;
        if (head) head->prev = node;
        else tail = node;
        head = node;
    }

    void pop_front() {
        if (!head) return;
        DLLNode* tmp = head;
        head = head->next;
        if (head) head->prev = nullptr;
        else tail = nullptr;
        delete tmp;
    }

    void push_back(int v) {
        DLLNode* node = new DLLNode(v);
        node->prev = tail;
        if (tail) tail->next = node;
        else head = node;
        tail = node;
    }

    void pop_back() {
        if (!tail) return;
        DLLNode* tmp = tail;
        tail = tail->prev;
        if (tail) tail->next = nullptr;
        else head = nullptr;
        delete tmp;
    }
};

template<typename List>
void benchmark(const std::string& name, List& list, int N) {
    auto t1 = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < N; i++) list.push_back(i);
    for (int i = 0; i < N; i++) list.pop_back();
    auto t2 = std::chrono::high_resolution_clock::now();
    std::cout << name << ": " << std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count() << " ms\n";
}

#endif // SLL_HPP
<<<<<<< HEAD
=======

>>>>>>> 82157a5e40422b9489d714ca7fd930c10a492bd2
=======
>>>>>>> 9174eb4e4deb94c6e6543ae8d0a492054dea3034
