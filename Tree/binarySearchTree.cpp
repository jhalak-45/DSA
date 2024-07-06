#include <iostream>
using namespace std;

struct node {
    int data;
    node* left;
    node* right;
};

// Root node 
node* root = NULL;
int rHeight = 0;
int lHeight = 0;

node* newNode(int value) {
    node *temp = new node();
    temp->data = value;
    temp->right = NULL;
    temp->left = NULL;
    return temp;
}

node* insert(node* root, int value) {
    if (root == NULL) {
        root = newNode(value);
    } else if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    return root;
}

void display(node* root) {
    if (root != NULL) {
        display(root->left);
        cout << root->data << " ";
        display(root->right);
    }
}

int leftHeight(node* root) {
    if (root == NULL) {
        return 0;
    } else {
        return max(leftHeight(root->left), leftHeight(root->right)) + 1;
    }
}

int rightHeight(node* root) {
    if (root == NULL) {
        return 0;
    } else {
        return max(rightHeight(root->left), rightHeight(root->right)) + 1;
    }
}

int main() {
    int n, item;
    cout << "How many elements are you going to insert? ";
    cin >> n;
    cout << "Enter elements: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> item;
        root = insert(root, item);
    }
    cout << "The Binary Search Tree is: " << endl;
    display(root);
    
    cout << endl << endl;
    lHeight = leftHeight(root->left);
    cout << "The height of the left sub-tree is: " << lHeight << endl;
    rHeight = rightHeight(root->right);
    cout << "The height of the right sub-tree is: " << rHeight << endl;

    return 0;
}
