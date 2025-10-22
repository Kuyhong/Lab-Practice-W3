// Challenge A3/csll.cpp

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

class CSLL {
private:
    Node* head;
    int size;

public:
    CSLL() : head(nullptr), size(0) {}

    void append(int val) {
        Node* n = new Node(val);
        if (!head) {
            head = n;
            n->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head)
                temp = temp->next;
            temp->next = n;
            n->next = head;
        }
        size++;
    }

    void rotateRight(int k) {
        if (!head || k == 0 || size == 0) return;
        k = k % size;
        if (k == 0) return;

        int moveSteps = size - k;
        Node* tail = head;
        for (int i = 0; i < moveSteps - 1; i++)
            tail = tail->next;

        head = tail->next;
    }

    void print() {
        if (!head) return;
        Node* temp = head;
        do {
            cout << temp->value << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};

int main() {
    const int n = 10;
    vector<int> testKs = {1, n / 2, n - 1};

    CSLL list;
    for (int i = 1; i <= n; ++i)
        list.append(i);

    cout << "Original CSLL: ";
    list.print();

    for (int k : testKs) {
        CSLL test = list; 
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
