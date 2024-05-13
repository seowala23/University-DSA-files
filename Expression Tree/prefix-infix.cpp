#include <iostream>
#include <stack>
#include <cstring>
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

string prefixToInfix(const char* prefix) {
    stack<Node*> st;

    int length = strlen(prefix);

    for (int i = length - 1; i >= 0; i--) {
        if (!isOperator(prefix[i])) {
            Node* operand = createNode(prefix[i]);
            st.push(operand);
        } else {
            Node* op1 = st.top();
            st.pop();
            Node* op2 = st.top();
            st.pop();

            Node* temp = createNode(prefix[i]);
            temp->left = op2;
            temp->right = op1;

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

char* readPrefixExpression() {
    char* prefix = new char[100]; // assuming max length of prefix expression is 100 characters
    cout << "Enter the prefix expression: ";
    cin >> prefix;
    return prefix;
}

int main() {
    char* prefix = readPrefixExpression();

    string infix = prefixToInfix(prefix);
    cout << "Infix expression: " << infix << endl;

    delete[] prefix;

    return 0;
}
