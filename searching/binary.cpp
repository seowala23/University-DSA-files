#include <iostream>
using namespace std;
void isEmpty(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] ==NULL;
        cout<<"Empty"<<endl;
        return;
    }
    cout<<"Not Empty"<<endl;
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
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void search(int *arr, int size, int tosearch)
{
    int start = 0, end = size - 1, mid;
    for (int i = 0; i < size; i++)
    {
        mid = (arr[start] + arr[end]) / 2;
        if (tosearch > arr[mid])
        {
            end = mid - 1;
        }
        if (tosearch < arr[mid])
        {
            start = mid + 1;
        }
        if (tosearch = mid)
        {
            cout << "Searching value " << arr[mid] << endl;
            return;
        }
    }
    cout << "Not Found!" << endl;
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
    cout << "Enter how many elements You want :" << endl;
    cin >> size;
    int arr[size];
    bool result = true;
    while (result)
    {
        int operat;
        cout << "Enter 0 for check empty or not\nEnter 1 for insert\nEnter 2 for print\nEnter 3 for search\nEnter 4 for update\nEnter 5 for delete\nEnter 6 for reverse\nEnter 7 for continue\nDefault is Break\n-----------\n Enter Operator :" << endl;
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
            int tosearch;
            cout << "Enter search " << endl;
            cin >> tosearch;
            search(arr, size, tosearch);
            break;
        case 4:
            int value;
            cout << "Enter value " << endl;
            cin >> value;
            update(arr, size, value);
            break;
        case 5:
            int todel;
            cout << "Enter todel " << endl;
            cin >> todel;
            del(arr, size, todel);
            break;
        case 6:
            reverse(arr, size);
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