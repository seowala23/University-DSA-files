#include <iostream>
#include <stdlib.h>
using namespace std;
struct StdStack
{
    int *array;
    int top;
    int size;
};
StdStack *createStack(int size)
{
    StdStack *stack = (StdStack *)malloc(sizeof(StdStack));
    stack->size = size;
    stack->top = -1;
    stack->array = (int *)malloc(stack->size * sizeof(int));
    return stack;
}
bool isFull(StdStack* stack) {
    bool full = stack->top == stack->size - 1;
    if (full)
        cout << "Array is full." << endl;
    else
        cout << "Array is not full." << endl;
    return full;
}

bool isEmpty(StdStack* stack) {
    bool empty = stack->top == -1;
    if (empty)
        cout << "Array is empty." << endl;
    else
        cout << "Array is not empty." << endl;
    return empty;
}

void push(StdStack *stack, int RNO)
{
    if (isFull(stack))
    {
        cout << "Stack Overflow." << endl;
        return;
    }
    stack->array[++stack->top] = RNO;
}

void pop(StdStack *stack)
{
    if (isEmpty(stack))
    {
        cout << "Stack Underflow" << endl;
        return;
    }
    cout << "Last one will remove" << endl;
    stack->top--;
}

int peek(StdStack *stack)
{
    if (isEmpty(stack))
    {
        cout << "Stack is empty" << endl;
        return -1;
    }
    return stack->array[stack->top];
}

void display(StdStack *stack)
{
    if (isEmpty(stack))
    {
        cout << "Stack is empty" << endl;
        return;
    }
    cout << "Stack elements:" << endl;
    for (int i = 0; i <= stack->top; i++)
    {
        cout << "Roll NO : " << stack->array[i] << endl;
    }
}

int main()
{
    int size;
    cout << "Enter the size of the stack: ";
    cin >> size;
    StdStack *stack = createStack(size);

    bool result = true;
    while (result)
    {
        int operat;
        cout << "Enter 1 for push\nEnter 2 for pop\nEnter 3 for peek\nEnter 4 for display\nEnter 5 for checking Full or not \nEnter 6 for checking Empty or not\nEnter 7 for continue\nDefault is Break\n-----------\n Enter Operator :" << endl;
        cin >> operat;
        cout << "-----------" << endl;
        switch (operat)
        {
        case 1:
        {
            int RNO;
            cout << "Roll NO : ";
            cin >> RNO;
            push(stack, RNO);
            break;
        }
        case 2:
        {
            pop(stack);
            break;
        }
        case 3:
        {
            int topElement = peek(stack);
            if (topElement != -1)
                cout << "Top Element: " << topElement << endl;
            break;
        }
        case 4:
        {
            display(stack);
            break;
        }
        case 5:
            isFull(stack);
            break;
        case 6:
            isEmpty(stack);
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
