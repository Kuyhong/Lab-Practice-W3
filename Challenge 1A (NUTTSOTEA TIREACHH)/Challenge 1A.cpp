// Challenge 1A (Lab Practice W3)
// Here's what I can do (Delete Me once you finished intergrating)

#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node *CreateHeadNode(int input) {
    Node *pointer = new Node;
    pointer->data = input;
    pointer->next = nullptr;
    return pointer;
}

Node *CreateNode(Node* head, int input) {
    Node *pointer = new Node;  
    pointer->data = input;
    pointer->next = head;
    return pointer;
}

Node *LoopEndNode(Node* head) {
    Node *pointer = new Node;
    pointer = head;

    while (pointer->next != nullptr)
    {
        pointer = pointer->next;
    }
    
    pointer->next = head;
    return pointer;
}

int main(){
    Node *head = new Node;
    head = CreateHeadNode(6);
    head = CreateNode(head, 7);
    head = CreateNode(head, 8);
    head = CreateNode(head, 9);
    head = LoopEndNode(head);
    // Result should be 6, 9, 8, 7 (with end node loop) (However, we want to show that it's 9, 8, 7, 6)
    // So, we'll display it like it's 9, 8, 7, 6

    // Running the CSLL Cycle
    int cyclecount;
    cout << "How many times to cycle (CSLL Loop): ";
    cin >> cyclecount;

    for (int i = 0; i < cyclecount + 1; i++)
    {
        head = head->next;
    }

    cout << "Result is: " << head->data << endl;

    // Make SLL data (No Loop End Node)
    delete head;
    head = nullptr;
    head = CreateHeadNode(6);
    head = CreateNode(head, 7);
    head = CreateNode(head, 8);
    head = CreateNode(head, 9);
    // Result should be 9, 8, 7, 6 (with no end node loop)

    // Running the SLL Cycle
    cout << "How many times to cycle (SLL Loop)?" << endl;
    cout << "It's offset by one element compared to CSLL: "; // As a side effect of comparing it with CSLL
    cin >> cyclecount;

    Node *TempHead = new Node;
    TempHead = head;
    for (int i = 0; i < cyclecount; i++)
    {
        if (TempHead == nullptr)
        {
            TempHead = head;
        } else {
            TempHead = TempHead->next;
        }  
    }
    cout << "Result is: " << head->data << endl;
}