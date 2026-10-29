
#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    int bookID;
    string title;
    Node *left, *right;
    bool lthread, rthread;

    Node(int id, string t) {
        bookID = id;
        title = t;
        left = right = nullptr;
        lthread = rthread = true;
    }
};

class ThreadedBST {
    Node* root;

public:
    ThreadedBST() {
        root = nullptr;
    }

    void insert(int id, string title) {
        Node* ptr = root;
        Node* parent = nullptr;

        while (ptr != nullptr) {
            if (id == ptr->bookID) {
                cout << "Book ID already exists\n";
                return;
            }

            parent = ptr;

            if (id < ptr->bookID) {
                if (!ptr->lthread)
                    ptr = ptr->left;
                else
                    break;
            } else {
                if (!ptr->rthread)
                    ptr = ptr->right;
                else
                    break;
            }
        }

        Node* newNode = new Node(id, title);

        if (parent == nullptr) {
            root = newNode;
        } else if (id < parent->bookID) {
            newNode->left = parent->left;
            newNode->right = parent;
            parent->lthread = false;
            parent->left = newNode;
        } else {
            newNode->left = parent;
            newNode->right = parent->right;
            parent->rthread = false;
            parent->right = newNode;
        }

        cout << "Book inserted successfully\n";
    }

    Node* leftmost(Node* ptr) {
        if (ptr == nullptr)
            return nullptr;

        while (!ptr->lthread)
            ptr = ptr->left;

        return ptr;
    }

    void displayInorder() {
        if (root == nullptr) {
            cout << "Library index is empty\n";
            return;
        }

        Node* ptr = leftmost(root);

        while (ptr != nullptr) {
            cout << "Book ID: " << ptr->bookID
                 << ", Title: " << ptr->title << endl;

            if (ptr->rthread)
                ptr = ptr->right;
            else
                ptr = leftmost(ptr->right);
        }
    }

    void search(int id) {
        Node* ptr = root;

        while (ptr != nullptr) {
            if (id == ptr->bookID) {
                cout << "Book found\n";
                cout << "Book ID: " << ptr->bookID
                     << ", Title: " << ptr->title << endl;
                return;
            }

            if (id < ptr->bookID) {
                if (ptr->lthread)
                    break;
                ptr = ptr->left;
            } else {
                if (ptr->rthread)
                    break;
                ptr = ptr->right;
            }
        }

        cout << "Book not found\n";
    }
};

int main() {
    ThreadedBST library;
    int choice, id;
    string title;

    do {
        cout << "\n1. Insert Book\n";
        cout << "2. Display Books (Inorder)\n";
        cout << "3. Search Book\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter Book ID: ";
            cin >> id;
            cin.ignore(10000, '\n');
            cout << "Enter Book Title: ";
            getline(cin, title);
            library.insert(id, title);
            break;

        case 2:
            library.displayInorder();
            break;

        case 3:
            cout << "Enter Book ID to search: ";
            cin >> id;
            library.search(id);
            break;

        case 4:
            break;

        default:
            cout << "Invalid choice\n";
        }
    } while (choice != 4);

    return 0;
}
