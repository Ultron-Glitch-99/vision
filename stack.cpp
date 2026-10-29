
#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string page;
    Node* next;

    Node(string p) {
        page = p;
        next = nullptr;
    }
};

class BrowserHistory {
    Node* top;

public:
    BrowserHistory() {
        top = nullptr;
    }

    void visitPage(string page) {
        Node* n = new Node(page);
        n->next = top;
        top = n;
        cout << "Page visited successfully\n";
    }

    void navigateBack() {
        if (top == nullptr) {
            cout << "History is empty\n";
            return;
        }

        Node* temp = top;
        top = top->next;
        delete temp;

        if (top != nullptr)
            cout << "Current page: " << top->page << endl;
        else
            cout << "No previous page\n";
    }

    void currentPage() {
        if (top == nullptr)
            cout << "History is empty\n";
        else
            cout << "Current page: " << top->page << endl;
    }

    void isEmpty() {
        if (top == nullptr)
            cout << "History is empty\n";
        else
            cout << "History is not empty\n";
    }

    ~BrowserHistory() {
        while (top != nullptr) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }
};

int main() {
    BrowserHistory browser;
    int choice;
    string page;

    do {
        cout << "\n1.Visit Page\n2.Navigate Back\n3.Current Page\n4.Check Empty\n5.Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter page name: ";
            cin >> page;
            browser.visitPage(page);
            break;

        case 2:
            browser.navigateBack();
            break;

        case 3:
            browser.currentPage();
            break;

        case 4:
            browser.isEmpty();
            break;
        }
    } while (choice != 5);

    return 0;
}
