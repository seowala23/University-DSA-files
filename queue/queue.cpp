#include <iostream>
using namespace std;

struct StdNode {
    int RNO;
    StdNode* next;
};

StdNode* front = nullptr;
StdNode* rear = nullptr;

void enqueue(int RNO) {
    StdNode* newNode = new StdNode();
    if (!newNode) {
        cout << "Queue Overflow." << endl;
        return;
    }
    newNode->RNO = RNO;
    newNode->next = nullptr;
    if (rear == nullptr) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

void dequeue() {
    if (front == nullptr) {
        cout << "Queue Underflow" << endl;
        return;
    }
    StdNode* temp = front;
    front = front->next;
    delete temp;
    if (front == nullptr) {
        rear = nullptr;
    }
    cout << "Dequeued successfully." << endl;
}

void display() {
    if (front == nullptr) {
        cout << "Queue is empty" << endl;
        return;
    }
    cout << "Queue elements:" << endl;
    cout << "Front Element: " << front->RNO << endl; // Peek functionality
    StdNode* curr = front;
    while (curr != nullptr) {
        cout << "Roll NO : " << curr->RNO << endl;
        curr = curr->next;
    }
}

int main() {
    bool result = true;
    while (result) {
        int operat;
        cout << "Enter 1 for enqueue\nEnter 2 for dequeue\nEnter 3 for display\nEnter 4 for continue\nDefault is Break\n-----------\nEnter Operator: ";
        cin >> operat;
        cout << "-----------" << endl;
        switch (operat) {
            case 1: {
                int RNO;
                cout << "Roll NO : ";
                cin >> RNO;
                enqueue(RNO);
                break;
            }
            case 2: {
                dequeue();
                break;
            }
            case 3: {
                display();
                break;
            }
            case 4: {
                result = true;
                break;
            }
            default: {
                result = false;
                break;
            }
        }
        cout << "-----------" << endl;
    }
    return 0;
}
