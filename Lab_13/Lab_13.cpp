#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    char value;
    Node* next;

    Node() : value('\0'), next(nullptr) {}
    Node(char val, Node* nxt = nullptr) : value(val), next(nxt) {}
    Node(const Node& other) : value(other.value), next(other.next) {}
    ~Node() = default;
};

class CList {
private:
    Node* head;
    int length;

public:
    CList() : head(nullptr), length(0) {}

    CList(const CList& other) : head(nullptr), length(0) {
        Node* current = other.head;
        while (current) {
            AddToTail(current->value);
            current = current->next;
        }
    }

    ~CList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void AddToFront(char val) {
        Node* newNode = new Node(val, head);
        head = newNode;
        length++;
    }

    void AddToTail(char val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = newNode;
        }
        length++;
    }

    void InsertAt(int index, char val) {
        if (index < 0 || index > length) {
            cout << "Index out of bounds\n";
            return;
        }
        if (index == 0) {
            AddToFront(val);
            return;
        }
        Node* current = head;
        for (int i = 0; i < index - 1; ++i) {
            current = current->next;
        }
        Node* newNode = new Node(val, current->next);
        current->next = newNode;
        length++;
    }

    bool Remove(char val) {
        Node* current = head;
        Node* prev = nullptr;

        while (current) {
            if (current->value == val) {
                if (prev) {
                    prev->next = current->next;
                } else {
                    head = current->next;
                }
                delete current;
                length--;
                return true;
            }
            prev = current;
            current = current->next;
        }
        return false;
    }

    void Clear() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        length = 0;
    }

    void Print() {
        Node* current = head;
        while (current) {
            cout << current->value;
            current = current->next;
        }
        cout << endl;
    }

    int Length() {
        return length;
    }
};

class Text {
private:
    CList* lines;
    int lineCount;

public:
    Text() : lines(nullptr), lineCount(0) {}

    ~Text() {
        Clear();
    }

    void AddLine() {
        CList* newLines = new CList[lineCount + 1];
        for (int i = 0; i < lineCount; ++i) {
            newLines[i] = lines[i];
        }
        delete[] lines;
        lines = newLines;
        lineCount++;
    }

    void RemoveLine(int index) {
        if (index < 0 || index >= lineCount) {
            cout << "Invalid line index\n";
            return;
        }
        CList* newLines = new CList[lineCount - 1];
        for (int i = 0, j = 0; i < lineCount; ++i) {
            if (i != index) {
                newLines[j++] = lines[i];
            }
        }
        delete[] lines;
        lines = newLines;
        lineCount--;
    }

    void AddCharToLine(int lineIndex, char val) {
        if (lineIndex < 0 || lineIndex >= lineCount) {
            cout << "Invalid line index\n";
            return;
        }
        lines[lineIndex].AddToTail(val);
    }

    void PrintLine(int lineIndex) {
        if (lineIndex < 0 || lineIndex >= lineCount) {
            cout << "Invalid line index\n";
            return;
        }
        cout << "Line " << lineIndex + 1 << ": ";
        lines[lineIndex].Print();
    }

    void PrintAllLines() {
        for (int i = 0; i < lineCount; ++i) {
            cout << "Line " << i + 1 << ": ";
            lines[i].Print();
        }
    }

    void Clear() {
        delete[] lines;
        lines = nullptr;
        lineCount = 0;
    }
};

void Menu() {
    Text text;
    int choice;
    do {
        cout << "\n1. Dodaty ryadok\n"
             << "2. Vydalyty ryadok\n"
             << "3. Dodaty symvol v ryadok\n"
             << "4. Vyvesty ryadok\n"
             << "5. Vyvesty usi ryadky\n"
             << "6. Vydalyty usi ryadky\n"
             << "7. Vyjty\n"
             << "Vash vybir: ";
        cin >> choice;

        switch (choice) {
            case 1:
                text.AddLine();
                cout << "Ryadok dodano.\n";
                break;
            case 2: {
                int lineIndex;
                cout << "Vvedit indeks ryadka dlya vydalennya: ";
                cin >> lineIndex;
                text.RemoveLine(lineIndex - 1);
                break;
            }
            case 3: {
                int lineIndex;
                char val;
                cout << "Vvedit indeks ryadka: ";
                cin >> lineIndex;
                cout << "Vvedit symvol: ";
                cin >> val;
                text.AddCharToLine(lineIndex - 1, val);
                break;
            }
            case 4: {
                int lineIndex;
                cout << "Vvedit indeks ryadka: ";
                cin >> lineIndex;
                text.PrintLine(lineIndex - 1);
                break;
            }
            case 5:
                text.PrintAllLines();
                break;
            case 6:
                text.Clear();
                cout << "Usi ryadky vydaleno.\n";
                break;
            case 7:
                cout << "Vyhid z programy.\n";
                break;
            default:
                cout << "Nevirny vybir. Sprobuyte shche raz.\n";
        }
    } while (choice != 7);
}

int Lab_13() {
    Menu();
    return 0;
}
