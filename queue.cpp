
#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string name;
    int size;
    Node* next;

    Node(string n, int s) {
        name = n;
        size = s;
        next = nullptr;
    }
};

class Queue {
    Node *front, *rear;

public:
    Queue() {
        front = rear = nullptr;
    }

    void addParty(string name, int size) {
        Node* n = new Node(name, size);

        if (rear == nullptr)
            front = rear = n;
        else {
            rear->next = n;
            rear = n;
        }

        cout << "Party added to waitlist\n";
    }

    void seatParty() {
        if (front == nullptr) {
            cout << "Waitlist is empty\n";
            return;
        }

        Node* temp = front;
        cout << "Seating party: " << temp->name
             << " (" << temp->size << " people)\n";

        front = front->next;

        if (front == nullptr)
            rear = nullptr;

        delete temp;
    }

    void displayWaitlist() {
        if (front == nullptr) {
            cout << "Waitlist is empty\n";
            return;
        }

        Node* temp = front;

        while (temp != nullptr) {
            cout << "Party: " << temp->name
                 << ", Size: " << temp->size << endl;
            temp = temp->next;
        }
    }

    ~Queue() {
        while (front != nullptr) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }
};

int main() {
    Queue q;
    int choice, size;
    string name;

    do {
        cout << "\n1.Add Party\n2.Seat Party\n3.Display Waitlist\n4.Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter party name: ";
            cin >> name;
            cout << "Enter party size: ";
            cin >> size;

            if (size > 0)
                q.addParty(name, size);
            else
                cout << "Invalid party size\n";
            break;

        case 2:
            q.seatParty();
            break;

        case 3:
            q.displayWaitlist();
            break;
        }
    } while (choice != 4);

    return 0;
}
