#include <iostream>
#include <stdlib.h>

using namespace std;

struct StdNode {
    int RNO;
    StdNode* next;
};

StdNode* top = NULL;

void push(int RNO) {
    StdNode* ptr = (StdNode*)malloc(sizeof(StdNode));
    if (!ptr) {
        cout << " Stack Overflow." << endl;
        return;
    }
    ptr->RNO = RNO;
    ptr->next = top;
    top = ptr;
}

void pop() {
    if (top == NULL) {
        cout << "Stack Underflow" << endl;
        return;
    }
    StdNode* temp = top;
    top = top->next;
    delete temp;
    cout<<"Last one will remove"<<endl;
}

int peek() {
    if (top == NULL) {
        cout << "Stack is empty" << endl;
        return -1;
    }
    return top->RNO;
}

void display() {
    if (top == NULL) {
        cout << "Stack is empty" << endl;
        return;
    }
    StdNode* curr = top;
    cout << "Stack elements:" << endl;
    while (curr != NULL) {
        cout << "Roll NO : " << curr->RNO << endl;
        curr = curr->next;
    }
}

int main() {
    bool result = true;
    while (result) {
        int operat;
        cout << "Enter 1 for push\nEnter 2 for pop\nEnter 3 for peek\nEnter 4 for display\nEnter 5 for continue\nDefault is Break\n-----------\n Enter Operator :" << endl;
        cin >> operat;
        cout << "-----------" << endl;
        switch (operat) {
            case 1: {
                int RNO;
                cout << "Roll NO : ";
                cin >> RNO;
                push(RNO);
                break;
            }
            case 2: {
                pop();
                break;
            }
            case 3: {
                int topElement = peek();
                if (topElement != -1)
                    cout << "Top Element: " << topElement << endl;
                break;
            }
            case 4: {
                display();
                break;
            }
            case 5: {
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
