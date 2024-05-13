#include <iostream>
using namespace std;

struct StdNode {
    int RNO;
    StdNode* prev;
    StdNode* next;
};

StdNode* head = NULL;

void insert(int RNO) {
    StdNode* newNode = new StdNode();
    newNode->RNO = RNO;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        StdNode* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void display() {
    if (head == NULL) {
        cout << "Linked list is empty!" << endl;
        return;
    }
    StdNode* curr = head;
    cout << "Linked list elements: ";
    while (curr != NULL) {
        cout << curr->RNO << " ";
        curr = curr->next;
    }
    cout << endl;
}

void update(int toupdate) {
    StdNode* curr = head;
    while (curr != NULL) {
        if (curr->RNO == toupdate) {
            int newvalue;
            cout << "Enter new value: ";
            cin >> newvalue;
            curr->RNO = newvalue;
            return;
        }
        curr = curr->next;
    }
    cout << "Value Not found!" << endl;
}

void search(int tosearch) {
    StdNode* curr = head;
    while (curr != NULL) {
        if (curr->RNO == tosearch) {
            cout << "Found! Roll NO: " << curr->RNO << endl;
            return;
        }
        curr = curr->next;
    }
    cout << "Value Not found!" << endl;
}

void del(int todel) {
    if (head == NULL) {
        cout << "Linked list is empty!" << endl;
        return;
    }
    if (head->RNO == todel) {
        StdNode* temp = head;
        head = head->next;
        delete temp;
        if (head != NULL) {
            head->prev = NULL;
        }
        cout << "Value deleted successfully." << endl;
        return;
    }
    StdNode* curr = head;
    while (curr != NULL) {
        if (curr->RNO == todel) {
            curr->prev->next = curr->next;
            if (curr->next != NULL) {
                curr->next->prev = curr->prev;
            }
            delete curr;
            cout << "Value deleted successfully." << endl;
            return;
        }
        curr = curr->next;
    }
    cout << "Value Not found!" << endl;
}

void alldel() {
    if (head == NULL) {
        cout << "Linked list is empty!" << endl;
        return;
    }
    while (head != NULL) {
        StdNode* temp = head;
        head = head->next;
        delete temp;
    }
    cout << "All values deleted successfully." << endl;
}

int main() {
    bool result = true;
    while (result) {
        int operat; cout << "Enter 1 for insert\nEnter 2 for display\nEnter 3 for update\nEnter 4 for searching\nEnter 5 for delete\nEnter 6 for delete all\nEnter 7 for continue\nDefault is to exit\n-----------\nEnter Operator: ";
        cin >> operat;
        cout << "-----------" << endl;
        switch (operat) {
            case 1: {
                int RNO;
                cout << "Roll NO: ";
                cin >> RNO;
                insert(RNO);
                break;
            }
            case 2:
                display();
                break;
            case 3: {
                int toupdate;
                cout << "Enter value to update: ";
                cin >> toupdate;
                update(toupdate);
                break;
            }
            case 4: {
                int tosearch;
                cout << "Enter value to search: ";
                cin >> tosearch;
                search(tosearch);
                break;
            }
            case 5: {
                int todel;
                cout << "Enter value to delete: ";
                cin >> todel;
                del(todel);
                break;
            }
            case 6:
                alldel();
                break;
            case 7:
                result = true;
                break;
            default:
                result = false;
                break;
        }
        cout << "-----------" << endl;
    }
    return 0;
}