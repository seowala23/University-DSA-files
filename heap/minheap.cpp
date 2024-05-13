#include <iostream>

using namespace std;

struct MinHeap {
    int* heap;
    int size;
    static const int MAX_SIZE;

    MinHeap(int max_size) : size(0) {
        heap = new int[max_size];
    }

    ~MinHeap() {
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
        while (i > 0 && heap[parent(i)] > heap[i]) {
            swap(heap[parent(i)], heap[i]);
            i = parent(i);
        }
    }

    void heapifyDown(int i) {
        int minIndex = i;
        int l = leftChild(i);
        int r = rightChild(i);

        if (l < size && heap[l] < heap[minIndex])
            minIndex = l;
        if (r < size && heap[r] < heap[minIndex])
            minIndex = r;

        if (i != minIndex) {
            swap(heap[i], heap[minIndex]);
            heapifyDown(minIndex);
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

    int extractMin() {
        if (size <= 0) {
            cout << "Heap underflow!" << endl;
            return -1;
        }

        int minVal = heap[0];
        heap[0] = heap[--size];
        heapifyDown(0);
        return minVal;
    }

    void print() {
        for (int i = 0; i < size; ++i) {
            cout << heap[i] << " ";
        }
        cout << endl;
    }
};

const int MinHeap::MAX_SIZE = 100;

int main() {
    MinHeap heap(MinHeap::MAX_SIZE);

    heap.insert(10);
    heap.insert(20);
    heap.insert(15);
    heap.insert(40);
    heap.insert(50);

    cout << "Min heap: ";
    heap.print();

    cout << "Extracted min element: " << heap.extractMin() << endl;

    cout << "Min heap after extraction: ";
    heap.print();

    return 0;
}
