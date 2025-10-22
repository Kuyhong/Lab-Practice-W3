#include <iostream>
using namespace std;

class DNode {
public:
    int value;
    DNode* next;
    DNode* prev;

    DNode(int v) : value(v), next(nullptr), prev(nullptr) {}
};

class RecentItemsDLL {
private:
    DNode* head;

public:
    RecentItemsDLL() : head(nullptr) {}

    void addItem(int val) {
        DNode* n = new DNode(val);
        n->next = head;
        if (head != nullptr)
            head->prev = n;
        head = n;
    }

    void removeItem() {
        if (head == nullptr) {
            cout << "Tray is empty.\n";
            return;
        }
        DNode* temp = head;
        head = head->next;
        if (head != nullptr)
            head->prev = nullptr;
        cout << "Removed: " << temp->value << endl;
        delete temp;
    }

    void display() {
        DNode* curr = head;
        cout << "Recent Tray: ";
        while (curr != nullptr) {
            cout << curr->value << " ";
            curr = curr->next;
        }
        cout << endl;
    }
};

int main() {
    cout << "=== Doubly Linked List Recent Items Tray ===\n";
    RecentItemsDLL tray;
    tray.addItem(100);
    tray.addItem(200);
    tray.addItem(300);
    tray.display();
    tray.removeItem();
    tray.display();
    return 0;
}
