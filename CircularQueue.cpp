
#include <iostream>
#include <string>
using namespace std;

class CircularQueue {
private:
    string customers[5];
    int front;
    int rear;
    int capacity;
    bool isOpen;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
        capacity = 5;
        isOpen = true;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return !isEmpty() && (rear + 1) % capacity == front;
    }

    void customerArrival(string name) {
        if (!isOpen) {
            cout << "Checkout counter is closed.\n";
            return;
        }

        if (isFull()) {
            cout << "Queue is full. Please wait for space.\n";
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % capacity;
        }

        customers[rear] = name;
        cout << name << " added to the queue.\n";
    }

    void customerCheckout() {
        if (!isOpen) {
            cout << "Checkout counter is closed.\n";
            return;
        }

        if (isEmpty()) {
            cout << "No customers waiting.\n";
            return;
        }

        cout << "Checking out customer: "
             << customers[front] << endl;

        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % capacity;
        }
    }

    void closeCounter() {
        if (!isOpen) {
            cout << "Checkout counter is already closed.\n";
            return;
        }

        front = rear = -1;
        isOpen = false;

        cout << "Checkout counter closed.\n";
        cout << "Waiting queue cleared.\n";
    }

    void viewCustomers() {
        if (isEmpty()) {
            cout << "No customers in the queue.\n";
            return;
        }

        cout << "\nCustomers waiting:\n";

        int i = front;

        while (true) {
            cout << customers[i] << endl;

            if (i == rear) {
                break;
            }

            i = (i + 1) % capacity;
        }
    }
};

int main() {
    CircularQueue q;
    int choice;
    string name;

    do {
        cout << "\n--- SUPERMARKET CHECKOUT ---\n";
        cout << "1. Customer Arrival\n";
        cout << "2. Customer Checkout\n";
        cout << "3. Close Checkout Counter\n";
        cout << "4. View Customers\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter customer name: ";
            cin >> name;
            q.customerArrival(name);
            break;

        case 2:
            q.customerCheckout();
            break;

        case 3:
            q.closeCounter();
            break;

        case 4:
            q.viewCustomers();
            break;

        case 5:
            cout << "Program terminated.\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 5);

    return 0;
}
