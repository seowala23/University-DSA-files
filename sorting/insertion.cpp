#include <iostream>
using namespace std;

void isEmpty(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] != 0)
        {
            cout << "Not Empty" << endl;
            return;
        }
    }
    cout << "Empty" << endl;
}

void insert(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
}

void display(int *arr, int size)
{
    for (int i = 0; i < size ; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void swap(int *arr, int a, int b)
{
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

void ascendingInsertionSort(int *arr, int size)
{
    for (int i = 1; i < size; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    display(arr, size);
}

void descendingInsertionSort(int *arr, int size)
{
    for (int i = 1; i < size; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] < key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    display(arr, size);
}

void search(int *arr, int size, int tosearch)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == tosearch)
        {
            cout << "found " << endl;
            return;
        }
    }
    cout << "Not found " << endl;
}

void reverse(int *arr, int size)
{
    for (int start = 0, end = size - 1; start < end; start++, end--)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
    }
    cout << endl;
}

void update(int *arr, int size, int value)
{
    int newvalue;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == value)
        {
            cout << "found " << endl;
            cout << "Enter new value ";
            cin >> newvalue;
            arr[i] = newvalue;
            return;
        }
    }
    cout << "not found " << endl;
}

void del(int *arr, int &size, int todel)
{
    bool found = false;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == todel)
        {
            found = true;
            for (int j = i; j < size; j++)
            {
                arr[j] = arr[j + 1];
            }
        }
    }
    size--;
    if (found)
    {
        cout << "Element deleted successfully." << endl;
    }
    else
    {
        cout << "Element not found." << endl;
    }
}

int main()
{
    int size;
    cout << "Enter how many elements you want: " << endl;
    cin >> size;
    int arr[size];
    bool result = true;
    while (result)
    {
        int operat;
        cout << "Enter 0 for check empty or not\nEnter 1 for insert\nEnter 2 for print\nEnter 3 for sorting search\nEnter 4 for update\nEnter 5 for searching \nEnter 6 for delete\nEnter 7 for reverse\nEnter 8 for continue\nDefault is Break\n-----------\n Enter Operator :" << endl;
        cin >> operat;
        cout << "-----------" << endl;
        switch (operat)
        {
            case 0:
                isEmpty(arr, size);
                break;
            case 1:
                insert(arr, size);
                break;
            case 2:
                display(arr, size);
                break;
            case 3:
                int cond;
                cout << "Enter cond: 1 for ascending & 2 for descending" << endl;
                cin >> cond;
                if (cond == 1)
                {
                    ascendingInsertionSort(arr, size);
                }
                else if (cond == 2)
                {
                    descendingInsertionSort(arr, size);
                }
                else
                {
                    cout << "Condition not found." << endl;
                }
                break;
            case 4:
                int value;
                cout << "Enter value: " << endl;
                cin >> value;
                update(arr, size, value);
                break;
            case 5:
                int tosearch;
                cout << "Enter search: " << endl;
                cin >> tosearch;
                search(arr, size, tosearch);
                break;
            case 6:
                int todel;
                cout << "Enter to delete: " << endl;
                cin >> todel;
                del(arr, size, todel);
                break;
            case 7:
                reverse(arr, size);
                break;
            case 8:
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
