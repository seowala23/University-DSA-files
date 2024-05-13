#include <iostream>

using namespace std;

struct MaxHeap {
    int* heap;
    int size;
    static const int MAX_SIZE;

    MaxHeap(int max_size) : size(0) {
        heap = new int[max_size];
    }

    ~MaxHeap() {
        delete[] heap;
    }

    int parent(int i) {
        return (i - 1) / 2;
    }

    int leftChild(int i) {
        return 2 * i + 1;
    }

    int rightChild(int i) {
        return 2 * i + 2;
    }

    void swap(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }

    void heapifyUp(int i) {
        while (i > 0 && heap[parent(i)] < heap[i]) {
            swap(heap[parent(i)], heap[i]);
            i = parent(i);
        }
    }

    void heapifyDown(int i) {
        int maxIndex = i;
        int l = leftChild(i);
        int r = rightChild(i);

        if (l < size && heap[l] > heap[maxIndex])
            maxIndex = l;
        if (r < size && heap[r] > heap[maxIndex])
            maxIndex = r;

        if (i != maxIndex) {
            swap(heap[i], heap[maxIndex]);
            heapifyDown(maxIndex);
        }
    }

    void insert(int val) {
        if (size >= MAX_SIZE) {
            cout << "Heap overflow!" << endl;
            return;
        }

        heap[size++] = val;
        heapifyUp(size - 1);
    }

    int extractMax() {
        if (size <= 0) {
            cout << "Heap underflow!" << endl;
            return -1;
        }

        int maxVal = heap[0];
        heap[0] = heap[--size];
        heapifyDown(0);
        return maxVal;
    }

    void print() {
        for (int i = 0; i < size; ++i) {
            cout << heap[i] << " ";
        }
        cout << endl;
    }
};

const int MaxHeap::MAX_SIZE = 100;

int main() {
    MaxHeap heap(MaxHeap::MAX_SIZE);

    heap.insert(10);
    heap.insert(20);
    heap.insert(15);
    heap.insert(40);
    heap.insert(50);

    cout << "Max heap: ";
    heap.print();

    cout << "Extracted max element: " << heap.extractMax() << endl;

    cout << "Max heap after extraction: ";
    heap.print();

    return 0;
}

