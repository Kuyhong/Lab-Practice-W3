#include <iostream>
#include <vector>
#include <string>
using namespace std;

class UndoHistoryArray {
private:
    vector<string> actions;

public:
    void addAction(const string& act) {
        actions.push_back(act);
        cout << "Action added: " << act << endl;
    }

    void undo() {
        if (actions.empty()) {
            cout << "No actions to undo.\n";
            return;
        }
        cout << "Undo: " << actions.back() << endl;
        actions.pop_back();
    }

    void showHistory() {
        cout << "Undo Stack: ";
        for (int i = actions.size() - 1; i >= 0; i--)
            cout << actions[i] << " -> ";
        cout << "NULL\n";
    }
};

int main() {
    UndoHistoryArray history;
    history.addAction("Type Hello");
    history.addAction("Bold Text");
    history.addAction("Delete Word");
    history.showHistory();
    history.undo();
    history.showHistory();
    return 0;
}
