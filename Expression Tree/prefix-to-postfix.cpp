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

char* prefixToPostfix(const char* prefix) {
    int length = 0;
    while (prefix[length] != '\0') {
        length++;
    }
    
    int op_count = 0;
    for (int i = 0; i < length; i++) {
        if (isOperator(prefix[i])) {
            op_count++;
        }
    }

    char* postfix = new char[length + op_count + 1]; // plus one for null terminator
    int postfixIndex = 0;

    for (int i = length - 1; i >= 0; i--) {
        if (isOperator(prefix[i])) {
            postfix[postfixIndex++] = prefix[i];
            op_count--;
        } else {
            postfix[postfixIndex++] = prefix[i];
            if (op_count > 0) {
                postfix[postfixIndex++] = ' ';
            }
        }
    }

    postfix[postfixIndex] = '\0'; // Null-terminate the string
    return postfix;
}

char* readPrefixExpression() {
    char* prefix = new char[100]; // assuming max length of prefix expression is 100 characters
    cout << "Enter the prefix expression: ";
    cin >> prefix;
    return prefix;
}

int main() {
    char* prefix = readPrefixExpression();

    char* postfix = prefixToPostfix(prefix);
    cout << "Postfix expression: " << postfix << endl;

    delete[] prefix;
    delete[] postfix;

    return 0;
}
