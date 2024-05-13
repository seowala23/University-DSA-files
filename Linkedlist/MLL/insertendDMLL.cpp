#include <iostream>
#include <stdlib.h>
using namespace std;

struct StdNode {
    int RNO;
    StdNode *next1;
    StdNode *next2;
};

StdNode *head = NULL;

void insert(StdNode **head, int RNO) {
    StdNode *ptr = (StdNode *)malloc(sizeof(StdNode));
    ptr->RNO = RNO;
    ptr->next1 = *head;
    ptr->next2 = *head;
    *head = ptr;
}

void display(StdNode *head) {
    StdNode *curr = head;
    while (curr != NULL) {
        cout << "Roll NO : " << curr->RNO << endl;
        curr = curr->next1;
    }
}

void search(StdNode *head, int tosearch) {
    StdNode *curr = head;
    while (curr != NULL) {
        if (curr->RNO == tosearch) {
            cout << "Found! Roll NO : " << curr->RNO << endl;
            return;
        }
        curr = curr->next1;
    }
    cout << "Value Not found!" << endl;
}

void update(StdNode *head, int toupdate) {
    StdNode *curr = head;
    while (curr != NULL) {
        if (curr->RNO == toupdate) {
            int newvalue;
            cout << "New Value :";
            cin >> newvalue;
            curr->RNO = newvalue;
            return;
        }
        curr = curr->next1;
    }
    cout << "Value Not found!" << endl;
}

void del(StdNode **head, int todel) {
    StdNode *curr = *head;
    while (curr != NULL) {
        if (curr->RNO == todel) {
            if (curr->next2 != NULL) {
                curr->next2->next1 = curr->next1;
            } else {
                *head = curr->next1;
            }
            if (curr->next1 != NULL) {
                curr->next1->next2 = curr->next2;
            }
            free(curr);
            return;
        }
        curr = curr->next1;
    }
    cout << "Value Not found!" << endl;
}

void alldel(StdNode **head) {
    StdNode *curr = *head;
    while (curr != NULL) {
        StdNode *temp = curr;
        curr = curr->next1;
        free(temp);
    }
    *head = NULL;
}

void traverse(StdNode *head) {
    if (head == NULL)
        cout << "Linked list is empty!" << endl;
    StdNode *curr = head;
    while (curr != NULL) {
        cout << "" << curr->RNO;
        curr = curr->next1;
    }
}

int main() {
    bool result = true;
    while (result) {
        int operat;
        cout << "Enter 0 for check empty or not\nEnter 1 for insert\nEnter 2 for print\nEnter 3  for update\nEnter 4 for searching \nEnter 5 for delete\nEnter 6 for delete all\nEnter 7 for continue\nDefault is Break\n-----------\n Enter Operator :" << endl;
        cin >> operat;
        cout << "-----------" << endl;
        switch (operat) {
            case 1:
                int RNO;
                cout << "Roll NO : ";
                cin >> RNO;
                insert(&head, RNO);
                break;
            case 2:
                display(head);
                break;
            case 3:
                int toupdate;
                cout << "Enter update " << endl;
                cin >> toupdate;
                update(head, toupdate);
                break;
            case 4:
                int tosearch;
                cout << "Enter search " << endl;
                cin >> tosearch;
                search(head, tosearch);
                break;
            case 5:
                int todel;
                cout << "Enter todel " << endl;
                cin >> todel;
                del(&head, todel);
                break;
            case 6:
                alldel(&head);
                break;
            case 7:
                result = true;
                break;
            case 8:
                traverse(head);
                break;
            default:
                result = false;
                break;
        }
        cout << "-----------" << endl;
    }
    return 0;
}
