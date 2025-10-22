#include <iostream>
#include <string>
using namespace std;

class ActionNode {
public:
    string action;
    ActionNode* next;
    ActionNode(string act) : action(act), next(nullptr) {}
};

class UndoHistorySLL {
private:
    ActionNode* top;

public:
    UndoHistorySLL() : top(nullptr) {}

    void addAction(const string& act) {
        ActionNode* n = new ActionNode(act);
        n->next = top;
        top = n;
        cout << "Action added: " << act << endl;
    }

    void undo() {
        if (top == nullptr) {
            cout << "No actions to undo.\n";
            return;
        }
        cout << "Undo: " << top->action << endl;
        ActionNode* temp = top;
        top = top->next;
        delete temp;
    }

    void showHistory() {
        cout << "Undo Stack: ";
        for (ActionNode* p = top; p != nullptr; p = p->next)
            cout << p->action << " -> ";
        cout << "NULL\n";
    }
};

int main() {
    UndoHistorySLL history;
    history.addAction("Type A");
    history.addAction("Type B");
    history.addAction("Delete C");
    history.showHistory();
    history.undo();
    history.showHistory();
    return 0;
}
