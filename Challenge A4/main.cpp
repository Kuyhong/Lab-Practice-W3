#include <iostream>
#include <chrono>
#include <vector>
#include <numeric>
#include <random>

using namespace std;
using namespace chrono;

struct DLLNode {
    int val;
    DLLNode *prev, *next;
    DLLNode(int v) : val(v), prev(nullptr), next(nullptr) {}
};

struct SLLNode {
    int val;
    SLLNode *next;
    SLLNode(int v) : val(v), next(nullptr) {}
};

// Build DLL with n nodes
DLLNode* buildDLL(int n, vector<DLLNode*>& nodeRefs) {
    DLLNode* head = new DLLNode(0);
    nodeRefs.push_back(head);
    DLLNode* curr = head;
    for (int i = 1; i < n; ++i) {
        DLLNode* newNode = new DLLNode(i);
        curr->next = newNode;
        newNode->prev = curr;
        curr = newNode;
        nodeRefs.push_back(newNode);
    }
    return head;
}

// Build SLL with n nodes
SLLNode* buildSLL(int n, vector<SLLNode*>& nodeRefs) {
    SLLNode* head = new SLLNode(0);
    nodeRefs.push_back(head);
    SLLNode* curr = head;
    for (int i = 1; i < n; ++i) {
        SLLNode* newNode = new SLLNode(i);
        curr->next = newNode;
        curr = newNode;
        nodeRefs.push_back(newNode);
    }
    return head;
}

// Erase DLL node in O(1)
void eraseDLL(DLLNode* node) {
    if (node->prev) node->prev->next = node->next;
    if (node->next) node->next->prev = node->prev;
}

// Erase SLL with known predecessor
void eraseSLLWithPrev(SLLNode* prev) {
    SLLNode* toDelete = prev->next;
    if (toDelete)
        prev->next = toDelete->next;
}

// Erase SLL without known predecessor (requires traversal)
void eraseSLLNoPrev(SLLNode*& head, SLLNode* target) {
    if (head == target) {
        head = head->next;
        return;
    }
    SLLNode* curr = head;
    while (curr && curr->next != target)
        curr = curr->next;
    if (curr && curr->next == target)
        curr->next = target->next;
}

// Measure erase time
template <typename Func>
double timeIt(Func f, int trials = 5) {
    vector<double> durations;
    for (int i = 0; i < trials; ++i) {
        auto t0 = high_resolution_clock::now();
        f();
        auto t1 = high_resolution_clock::now();
        durations.push_back(duration<double, micro>(t1 - t0).count());
    }
    return accumulate(durations.begin(), durations.end(), 0.0) / trials;
}

int main() {
    vector<int> sizes = {1000, 10000, 100000};

    cout << "n\tDLL(us)\tSLL_with_prev(us)\tSLL_no_prev(us)\n";

    for (int n : sizes) {
        double dllTime = timeIt([&]() {
            vector<DLLNode*> refs;
            DLLNode* head = buildDLL(n, refs);
            eraseDLL(refs[n/2]);
        });

        double sllWithPrevTime = timeIt([&]() {
            vector<SLLNode*> refs;
            SLLNode* head = buildSLL(n, refs);
            eraseSLLWithPrev(refs[n/2 - 1]);
        });

        double sllNoPrevTime = timeIt([&]() {
            vector<SLLNode*> refs;
            SLLNode* head = buildSLL(n, refs);
            eraseSLLNoPrev(head, refs[n/2]);
        });

        cout << n << "\t" << dllTime << "\t" << sllWithPrevTime << "\t\t" << sllNoPrevTime << "\n";
    }

    return 0;
}
