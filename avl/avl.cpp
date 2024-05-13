#include <iostream>
#include <stdlib.h>
using namespace std;

struct AVLNode
{
    int data;
    AVLNode *left;
    AVLNode *right;
    int height;
};

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int height(AVLNode *node)
{
    if (node == NULL)
        return 0;
    return node->height;
}

int getBalance(AVLNode *node)
{
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

AVLNode *createNode(int data)
{
    AVLNode *newNode = new AVLNode();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;
    return newNode;
}

AVLNode *rightRotate(AVLNode *y)
{
    AVLNode *x = y->left;
    AVLNode *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

AVLNode *leftRotate(AVLNode *x)
{
    AVLNode *y = x->right;
    AVLNode *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

AVLNode *insert(AVLNode *root, int data)
{
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    else
        return root;

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);

    if (balance > 1 && data < root->left->data)
        return rightRotate(root);

    if (balance < -1 && data > root->right->data)
        return leftRotate(root);

    if (balance > 1 && data > root->left->data)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && data < root->right->data)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void display(AVLNode *root)
{
    if (root == NULL)
        return;

    display(root->left);
    cout << "Roll NO : " << root->data << endl;
    display(root->right);
}

AVLNode *search(AVLNode *root, int key)
{
    if (root == NULL || root->data == key)
        return root;

    if (key < root->data)
        return search(root->left, key);

    return search(root->right, key);
}

AVLNode *minValueNode(AVLNode *node)
{
    AVLNode *current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}

AVLNode *deleteNode(AVLNode *root, int data)
{
    if (root == NULL)
        return root;

    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else
    {
        if ((root->left == NULL) || (root->right == NULL))
        {
            AVLNode *temp = root->left ? root->left : root->right;

            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else
                *root = *temp;
            free(temp);
        }
        else
        {
            AVLNode *temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }

    if (root == NULL)
        return root;

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    if (balance > 1 && getBalance(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    if (balance < -1 && getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void alldel(AVLNode *root)
{
    if (root == NULL)
        return;

    alldel(root->left);
    alldel(root->right);
    delete root;
}
void operateAVL()
{
    AVLNode *root = NULL;
    bool result = true;
    while (result)
    {
        int operat;
        cout << "Enter 0 for check empty or not\nEnter 1 for insert\nEnter 2 for print\nEnter 3 for search\nEnter 4 for find min\nEnter 5 for delete\nEnter 6 for delete all\nEnter 7 for continue\nDefault is Break\n-----------\n Enter Operator :" << endl;
        cin >> operat;
        cout << "-----------" << endl;
        switch (operat)
        {
        case 1:
            int RNO;
            cout << "Roll NO : ";
            cin >> RNO;
            root = insert(root, RNO);
            break;
        case 2:
            display(root);
            break;
        }
        return 0;
    }