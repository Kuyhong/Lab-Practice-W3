#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node* next;

    Node(int v) : value(v), next(nullptr) {}
};

class RecentItemsSLL {
private:
    Node* head;

public:
    RecentItemsSLL() : head(nullptr) {}

    void addItem(int val) {
        Node* n = new Node(val);
        n->next = head;
        head = n;
    }

    void removeItem() {
        if (head == nullptr) {
            cout << "Tray is empty.\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        cout << "Removed: " << temp->value << endl;
        delete temp;
    }

    void display() {
        Node* curr = head;
        cout << "Recent Tray: ";
        while (curr != nullptr) {
            cout << curr->value << " ";
            curr = curr->next;
        }
        cout << endl;
    }
};

int main() {
    cout << "=== Singly Linked List Recent Items Tray ===\n";
    RecentItemsSLL tray;
    tray.addItem(10);
    tray.addItem(20);
    tray.addItem(30);
    tray.display();
    tray.removeItem();
    tray.display();
    return 0;
}
