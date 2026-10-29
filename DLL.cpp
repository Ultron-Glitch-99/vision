
#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string text;
    Node *prev, *next;

    Node(string s) {
        text = s;
        prev = next = nullptr;
    }
};

class TextEditor {
    Node *head, *tail;

public:
    TextEditor() {
        head = tail = nullptr;
    }

    void insertText(string s) {
        Node* n = new Node(s);

        if (head == nullptr) {
            head = tail = n;
        } else {
            tail->next = n;
            n->prev = tail;
            tail = n;
        }
    }

    void deleteText(string s) {
        Node* p = head;

        while (p != nullptr && p->text != s)
            p = p->next;

        if (p == nullptr) {
            cout << "Text not found\n";
            return;
        }

        if (p->prev != nullptr)
            p->prev->next = p->next;
        else
            head = p->next;

        if (p->next != nullptr)
            p->next->prev = p->prev;
        else
            tail = p->prev;

        delete p;
        cout << "Text deleted\n";
    }

    void display() {
        for (Node* p = head; p != nullptr; p = p->next)
            cout << p->text << " ";
        cout << endl;
    }

    void searchText(string s) {
        int pos = 1;

        for (Node* p = head; p != nullptr; p = p->next, pos++) {
            if (p->text == s) {
                cout << "Text found at position " << pos << endl;
                return;
            }
        }

        cout << "Text not found\n";
    }

    void reverseDisplay() {
        for (Node* p = tail; p != nullptr; p = p->prev)
            cout << p->text << " ";
        cout << endl;
    }

    ~TextEditor() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    TextEditor editor;
    int choice;
    string text;

    do {
        cout << "\n1.Insert Text\n2.Delete Text\n3.Display Text\n4.Search Text\n5.Print Reverse\n6.Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter text: ";
            cin >> text;
            editor.insertText(text);
            break;

        case 2:
            cout << "Enter text to delete: ";
            cin >> text;
            editor.deleteText(text);
            break;

        case 3:
            editor.display();
            break;

        case 4:
            cout << "Enter text to search: ";
            cin >> text;
            editor.searchText(text);
            break;

        case 5:
            editor.reverseDisplay();
            break;
        }
    } while (choice != 6);

    return 0;
}
