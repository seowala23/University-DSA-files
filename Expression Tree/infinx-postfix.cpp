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

char* infixToPostfix(const char* infix) {
    int length = 0;
    while (infix[length] != '\0') {
        length++;
    }

    char* postfix = new char[length * 2 + 1]; // max possible length
    int postfixIndex = 0;

    Point* stack = nullptr;

    for (int i = 0; i < length; i++) {
        if (isOperator(infix[i])) {
            while (stack && precedence(stack->data) >= precedence(infix[i])) {
                postfix[postfixIndex++] = stack->data;
                Point* temp = stack;
                stack = stack->next;
                delete temp;
            }
            stack = createPoint(infix[i]);
            stack->next = stack;
        } else if (infix[i] == '(') {
            stack = createPoint(infix[i]);
        } else if (infix[i] == ')') {
            while (stack && stack->data != '(') {
                postfix[postfixIndex++] = stack->data;
                Point* temp = stack;
                stack = stack->next;
                delete temp;
            }
            if (stack && stack->data == '(') {
                Point* temp = stack;
                stack = stack->next;
                delete temp;
            }
        } else {
            postfix[postfixIndex++] = infix[i];
        }
    }

    while (stack) {
        postfix[postfixIndex++] = stack->data;
        Point* temp = stack;
        stack = stack->next;
        delete temp;
    }

    postfix[postfixIndex] = '\0'; // Null-terminate the string
    return postfix;
}

char* readInfixExpression() {
    char* infix = new char[100]; // assuming max length of infix expression is 100 characters
    cout << "Enter the infix expression: ";
    cin >> infix;
    return infix;
}

int main() {
    char* infix = readInfixExpression();

    char* postfix = infixToPostfix(infix);
    cout << "Postfix expression: " << postfix << endl;

    delete[] infix;
    delete[] postfix;

    return 0;
}
