// Challenge A3/sll.cpp
#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using namespace std::chrono;

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

class SLL {
private:
    Node* head;
    int size;

public:
    SLL() : head(nullptr), size(0) {}

    void append(int val) {
        Node* n = new Node(val);
        if (!head) head = n;
        else {
            Node* temp = head;
            while (temp->next)
                temp = temp->next;
            temp->next = n;
        }
        size++;
    }

    void rotateRight(int k) {
        if (!head || k == 0) return;
        int len = 1;
        Node* tail = head;
        while (tail->next) {
            tail = tail->next;
            len++;
        }

        k = k % len;
        if (k == 0) return;

        Node* newTail = head;
        for (int i = 1; i < len - k; ++i)
            newTail = newTail->next;

        Node* newHead = newTail->next;
        newTail->next = nullptr;
        tail->next = head;
        head = newHead;
    }

    void print() {
        Node* temp = head;
        while (temp) {
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    const int n = 10;
    vector<int> testKs = {1, n / 2, n - 1};

    SLL list;
    for (int i = 1; i <= n; ++i)
        list.append(i);

    cout << "Original SLL: ";
    list.print();

    for (int k : testKs) {
        SLL test = list; 
        auto start = high_resolution_clock::now();
        test.rotateRight(k);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<nanoseconds>(stop - start).count();

        cout << "\nRotate right by k = " << k << ":\n";
        test.print();
        cout << "Time: " << duration << " ns\n";
    }
    return 0;
}
