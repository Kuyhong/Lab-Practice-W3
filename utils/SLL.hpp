#ifndef SLL_HPP
#define SLL_HPP

// ==============================
// (i) Singly Linked List — head only
// ==============================
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

// ==============================
// (ii) Singly Linked List — head + tail
// ==============================
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

// ==============================
// (iii) Doubly Linked List — head + tail
// ==============================
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

#endif // SLL_HPP