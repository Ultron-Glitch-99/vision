
#include <iostream>
#include <string>
#include <queue>
using namespace std;

class Node {
public:
    string word;
    string meaning;
    Node* left;
    Node* right;

    Node(string w, string m) {
        word = w;
        meaning = m;
        left = nullptr;
        right = nullptr;
    }
};

class Dictionary {
private:
    Node* root;

    Node* insertNode(Node* node, string word, string meaning) {
        if (node == nullptr) {
            return new Node(word, meaning);
        }

        if (word < node->word) {
            node->left = insertNode(node->left, word, meaning);
        } else if (word > node->word) {
            node->right = insertNode(node->right, word, meaning);
        } else {
            cout << "Duplicate word! Entry not inserted.\n";
        }

        return node;
    }

    Node* findMin(Node* node) {
        while (node != nullptr && node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    Node* deleteNode(Node* node, string word) {
        if (node == nullptr) {
            return nullptr;
        }

        if (word < node->word) {
            node->left = deleteNode(node->left, word);
        } else if (word > node->word) {
            node->right = deleteNode(node->right, word);
        } else {
            // Case 1: No left child
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            }

            // Case 2: No right child
            if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            // Case 3: Two children
            Node* successor = findMin(node->right);
            node->word = successor->word;
            node->meaning = successor->meaning;
            node->right = deleteNode(node->right, successor->word);
        }

        return node;
    }

    Node* searchNode(Node* node, string word) {
        if (node == nullptr || node->word == word) {
            return node;
        }

        if (word < node->word) {
            return searchNode(node->left, word);
        }

        return searchNode(node->right, word);
    }

    void inorder(Node* node) {
        if (node == nullptr) return;

        inorder(node->left);
        cout << node->word << " : " << node->meaning << endl;
        inorder(node->right);
    }

    // Mirror traversal: right, root, left
    void mirror(Node* node) {
        if (node == nullptr) return;

        mirror(node->right);
        cout << node->word << " : " << node->meaning << endl;
        mirror(node->left);
    }

    Node* copyTree(Node* node) {
        if (node == nullptr) return nullptr;

        Node* newNode = new Node(node->word, node->meaning);
        newNode->left = copyTree(node->left);
        newNode->right = copyTree(node->right);

        return newNode;
    }

    void destroyTree(Node* node) {
        if (node == nullptr) return;

        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }

public:
    Dictionary() {
        root = nullptr;
    }

    // Deep-copy constructor
    Dictionary(const Dictionary& other) {
        root = copyTree(other.root);
    }

    ~Dictionary() {
        destroyTree(root);
    }

    void insert(string word, string meaning) {
        Node* existing = searchNode(root, word);

        if (existing != nullptr) {
            cout << "Word already exists in dictionary.\n";
            return;
        }

        root = insertNode(root, word, meaning);
        cout << "Word inserted successfully.\n";
    }

    void remove(string word) {
        if (searchNode(root, word) == nullptr) {
            cout << "Word not found.\n";
            return;
        }

        root = deleteNode(root, word);
        cout << "Word deleted successfully.\n";
    }

    void search(string word) {
        Node* result = searchNode(root, word);

        if (result == nullptr) {
            cout << "Word not found.\n";
        } else {
            cout << "Word: " << result->word << endl;
            cout << "Meaning: " << result->meaning << endl;
        }
    }

    void display() {
        if (root == nullptr) {
            cout << "Dictionary is empty.\n";
            return;
        }

        cout << "\nDictionary (Alphabetical Order):\n";
        inorder(root);
    }

    void displayMirror() {
        if (root == nullptr) {
            cout << "Dictionary is empty.\n";
            return;
        }

        cout << "\nMirror Image of Dictionary:\n";
        mirror(root);
    }

    void displayLevelWise() {
        if (root == nullptr) {
            cout << "Dictionary is empty.\n";
            return;
        }

        queue<Node*> q;
        q.push(root);

        cout << "\nDictionary (Level-wise):\n";

        while (!q.empty()) {
            int levelSize = static_cast<int>(q.size());

            while (levelSize > 0) {
                Node* current = q.front();
                q.pop();

                cout << current->word << " : "
                     << current->meaning << "   ";

                if (current->left != nullptr) {
                    q.push(current->left);
                }

                if (current->right != nullptr) {
                    q.push(current->right);
                }

                levelSize--;
            }

            cout << endl;
        }
    }
};

int main() {
    Dictionary dict;
    Dictionary* copiedDict = nullptr;

    int choice;
    string word, meaning;

    do {
        cout << "\n===== BST DICTIONARY =====\n";
        cout << "1. Insert Word\n";
        cout << "2. Delete Word\n";
        cout << "3. Search Word\n";
        cout << "4. Display Dictionary\n";
        cout << "5. Display Mirror Image\n";
        cout << "6. Create and Display Copy\n";
        cout << "7. Display Level-wise\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter word: ";
            cin >> word;
            cout << "Enter meaning (use underscores for spaces): ";
            cin >> meaning;
            dict.insert(word, meaning);
            break;

        case 2:
            cout << "Enter word to delete: ";
            cin >> word;
            dict.remove(word);
            break;

        case 3:
            cout << "Enter word to search: ";
            cin >> word;
            dict.search(word);
            break;

        case 4:
            dict.display();
            break;

        case 5:
            dict.displayMirror();
            break;

        case 6:
            delete copiedDict;
            copiedDict = new Dictionary(dict);
            cout << "Dictionary copied successfully.\n";
            cout << "Copied dictionary:\n";
            copiedDict->display();
            break;

        case 7:
            dict.displayLevelWise();
            break;

        case 8:
            cout << "Exiting program.\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 8);

    delete copiedDict;
    return 0;
}
