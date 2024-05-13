#include <iostream>
using namespace std;

struct Point {
    char data;
    Point* next;
};

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

Point* createPoint(char data) {
    Point* newPoint = new Point;
    newPoint->data = data;
    newPoint->next = nullptr;
    return newPoint;
}

char* postfixToPrefix(const char* postfix) {
    int length = 0;
    while (postfix[length] != '\0') {
        length++;
    }
    
    int op_count = 0;
    for (int i = 0; i < length; i++) {
        if (isOperator(postfix[i])) {
            op_count++;
        }
    }

    char* prefix = new char[length + op_count + 1]; // plus one for null terminator
    int prefixIndex = 0;

    for (int i = length - 1; i >= 0; i--) {
        if (isOperator(postfix[i])) {
            prefix[prefixIndex++] = postfix[i];
            op_count--;
        } else {
            prefix[prefixIndex++] = postfix[i];
            if (op_count > 0) {
                prefix[prefixIndex++] = ' ';
            }
        }
    }

    prefix[prefixIndex] = '\0'; // Null-terminate the string
    return prefix;
}

char* readPostfixExpression() {
    char* postfix = new char[100]; // assuming max length of postfix expression is 100 characters
    cout << "Enter the postfix expression: ";
    cin >> postfix;
    return postfix;
}

int main() {
    char* postfix = readPostfixExpression();

    char* prefix = postfixToPrefix(postfix);
    cout << "Prefix expression: " << prefix << endl;

    delete[] postfix;
    delete[] prefix;

    return 0;
}
