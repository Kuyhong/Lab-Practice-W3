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
