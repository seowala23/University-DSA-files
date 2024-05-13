#include <iostream>

using namespace std;

namespace ClosedHashTable {
    const int SIZE = 10;

    int table[SIZE];
    bool filled[SIZE];

    int hashFunction(int key) {
        return key % SIZE;
    }

    void insert(int key, int value) {
        int index = hashFunction(key);
        if (filled[index]) {
            for (int i = 1; i < SIZE; ++i) {
                int newIndex = (index + i) % SIZE;
                if (!filled[newIndex]) {
                    table[newIndex] = value;
                    filled[newIndex] = true;
                    break;
                }
            }
        } else {
            table[index] = value;
            filled[index] = true;
        }
    }

    int search(int key) {
        int index = hashFunction(key);
        if (filled[index] && table[index] == key) {
            return table[index];
        } else {
            for (int i = 1; i < SIZE; ++i) {
                int newIndex = (index + i) % SIZE;
                if (filled[newIndex] && table[newIndex] == key) {
                    return table[newIndex];
                }
            }
            return -1; // Not found
        }
    }
}

int main() {
    using namespace ClosedHashTable;

    for (int i = 0; i < SIZE; ++i) {
        table[i] = -1;
        filled[i] = false;
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
