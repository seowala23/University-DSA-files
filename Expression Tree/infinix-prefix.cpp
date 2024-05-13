#include <iostream>
using namespace std;

struct Point {
    char data;
    Point* next;
};

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int precedence(char op) {
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

Point* createPoint(char data) {
    Point* newPoint = new Point;
    newPoint->data = data;
    newPoint->next = nullptr;
    return newPoint;
}

char* infixToPrefix(const char* infix) {
    int length = 0;
    while (infix[length] != '\0') {
        length++;
    }

    char* prefix = new char[length * 2 + 1]; // max possible length
    int prefixIndex = 0;

    Point* stack = nullptr;

    for (int i = length - 1; i >= 0; i--) {
        if (isOperator(infix[i])) {
            while (stack && precedence(stack->data) > precedence(infix[i])) {
                prefix[prefixIndex++] = stack->data;
                Point* temp = stack;
                stack = stack->next;
                delete temp;
            }
            stack = createPoint(infix[i]);
            stack->next = stack;
        } else if (infix[i] == ')') {
            stack = createPoint(infix[i]);
        } else if (infix[i] == '(') {
            while (stack && stack->data != ')') {
                prefix[prefixIndex++] = stack->data;
                Point* temp = stack;
                stack = stack->next;
                delete temp;
            }
            if (stack && stack->data == ')') {
                Point* temp = stack;
                stack = stack->next;
                delete temp;
            }
        } else {
            prefix[prefixIndex++] = infix[i];
        }
    }

    while (stack) {
        prefix[prefixIndex++] = stack->data;
        Point* temp = stack;
        stack = stack->next;
        delete temp;
    }

    prefix[prefixIndex] = '\0'; // Null-terminate the string
    return prefix;
}

char* readInfixExpression() {
    char* infix = new char[100]; // assuming max length of infix expression is 100 characters
    cout << "Enter the infix expression: ";
    cin >> infix;
    return infix;
}

int main() {
    char* infix = readInfixExpression();

    char* prefix = infixToPrefix(infix);
    cout << "Prefix expression: " << prefix << endl;

    delete[] infix;
    delete[] prefix;

    return 0;
}
