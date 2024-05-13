#include <iostream>

using namespace std;

namespace OpenHashTable {
    const int SIZE = 10;

    struct Node {
        int key;
        int value;
        Node* next;
    };

    Node* table[SIZE];

    int hashFunction(int key) {
        return key % SIZE;
    }

    void insert(int key, int value) {
        int index = hashFunction(key);
        Node* newNode = new Node;
        newNode->key = key;
        newNode->value = value;
        newNode->next = nullptr;

        if (table[index] == nullptr) {
            table[index] = newNode;
        } else {
            Node* current = table[index];
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    int search(int key) {
        int index = hashFunction(key);
        Node* current = table[index];
        while (current != nullptr) {
            if (current->key == key) {
                return current->value;
            }
            current = current->next;
        }
        return -1; // Not found
    }
}

int main() {
    using namespace OpenHashTable;

    for (int i = 0; i < SIZE; ++i) {
        table[i] = nullptr;
    }

    insert(10, 100);
    insert(20, 200);
    insert(30, 300);

    cout << "Value for key 10: " << search(10) << endl;
    cout << "Value for key 20: " << search(20) << endl;
    cout << "Value for key 30: " << search(30) << endl;
    cout << "Value for key 40: " << search(40) << endl;

    return 0;
}
