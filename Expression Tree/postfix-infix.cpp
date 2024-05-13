#include <iostream>
#include <stack>
using namespace std;

struct Node {
    char data;
    Node* left;
    Node* right;
};

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

Node* createNode(char data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

string postfixToInfix(const char* postfix) {
    stack<Node*> st;

    int length = 0;
    while (postfix[length] != '\0') {
        length++;
    }

    for (int i = 0; i < length; i++) {
        if (!isOperator(postfix[i])) {
            Node* operand = createNode(postfix[i]);
            st.push(operand);
        } else {
            Node* op1 = st.top();
            st.pop();
            Node* op2 = st.top();
            st.pop();

            Node* temp = createNode(postfix[i]);
            temp->right = op1;
            temp->left = op2;

            st.push(temp);
        }
    }

    Node* root = st.top();
    st.pop();

    string infix = "";

    // Traverse the tree in-order to construct infix expression
    stack<Node*> s;
    Node* current = root;
    bool done = false;

    while (!done) {
        if (current != nullptr) {
            s.push(current);
            current = current->left;
        } else {
            if (!s.empty()) {
                current = s.top();
                s.pop();
                infix += current->data;
                current = current->right;
            } else {
                done = true;
            }
        }
    }

    return infix;
}

char* readPostfixExpression() {
    char* postfix = new char[100]; // assuming max length of postfix expression is 100 characters
    cout << "Enter the postfix expression: ";
    cin >> postfix;
    return postfix;
}

int main() {
    char* postfix = readPostfixExpression();

    string infix = postfixToInfix(postfix);
    cout << "Infix expression: " << infix << endl;

    delete[] postfix;

    return 0;
}
