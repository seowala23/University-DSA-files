#include <iostream>
#include <stdlib.h>
using namespace std;
struct BSTNode
{
    int data;
    BSTNode *left;
    BSTNode *right;
};
BSTNode *root = NULL;
BSTNode *createNode(int data)
{
    BSTNode *newNode = new BSTNode();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

BSTNode *insert(BSTNode *root, int data)
{
    if (root == NULL)
    {
        root = createNode(data);
    }
    else if (data <= root->data)
    {
        root->left = insert(root->left, data);
    }
    else
    {
        root->right = insert(root->right, data);
    }
    return root;
}

void display(BSTNode *root)
{
    if (root == NULL)
        return;

    display(root->left);
    cout << "Roll NO : " << root->data << endl;
    display(root->right);
}

BSTNode *search(BSTNode *root, int key)
{
    if (root == NULL || root->data == key)
        return root;

    if (key < root->data)
        return search(root->left, key);

    return search(root->right, key);
}

BSTNode *findMin(BSTNode *root)
{
    if (root == NULL)
        return NULL;

    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}
BSTNode *remove(BSTNode *root, int data)
{
    if (root == NULL)
        return root;

    if (data < root->data)
        root->left = remove(root->left, data);
    else if (data > root->data)
        root->right = remove(root->right, data);
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            root = NULL;
        }
        else if (root->left == NULL)
        {
            BSTNode *temp = root;
            root = root->right;
            free(temp);
        }
        else if (root->right == NULL)
        {
            BSTNode *temp = root;
            root = root->left;
            free(temp);
        }
        else
        {
            BSTNode *temp = findMin(root->right);
            root->data = temp->data;
            root->right = remove(root->right, temp->data);
        }
    }
    return root;
}

void alldel(BSTNode *root)
{
    if (root == NULL)
        return;

    alldel(root->left);
    alldel(root->right);
    free(root);
}

int main()
{
    bool result = true;
    while (result)
    {
        int operat;
        cout << "Enter 0 for check empty or not\nEnter 1 for insert\nEnter 2 for print\nEnter 3 for search\nEnter 4 for  find min \nEnter 5 for  free(\nEnter 6  for  free( all\nEnter 7 for  continue\nDefault is Break\n-----------\n Enter Operator :" << endl;
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
        case 3:
            int tosearch;
            cout << "Enter search " << endl;
            cin >> tosearch;
            if (search(root, tosearch) != NULL)
                cout << "Found ! Roll NO : " << tosearch << endl;
            else
                cout << "Value Not found!" << endl;
            break;
        case 4:
            findMin(root);
            root = NULL;
            break;
        case 5:
            int todel;
            cout << "Enter todel " << endl;
            cin >> todel;
            root = remove(root, todel);
            break;
        case 6:
            alldel(root);
            root = NULL;
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