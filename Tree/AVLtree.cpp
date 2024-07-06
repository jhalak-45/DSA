#include <iostream>
using namespace std;

struct node {
    int data;
    node* left;
    node* right;
    int height;
};
node* current_node;
node* root = NULL;

int height(node* N) {
    if (N == NULL)
        return 0;
    return N->height;
}

node* newNode(int value) {
    node* temp = new node();
    temp->data = value;
    temp->left = NULL;
    temp->right = NULL;
    temp->height = 1; // New node is initially added at leaf
    return temp;
}

node* rightRotate(node* y) {
    node* x = y->left;
    node* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    // Return new root
    return x;
}

node* leftRotate(node* x) {
    node* y = x->right;
    node* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    // Return new root
    return y;
}

int getBalance(node* N) {
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

node* insert(node* node, int value) {
    // 1. Perform the normal BST insertion
    if (node == NULL)
        return newNode(value);

    if (value < node->data)
        node->left = insert(node->left, value);
    else if (value > node->data)
        node->right = insert(node->right, value);
    else { // Duplicate values are not allowed in BST
        cout << "Value " << value << " already exists in the tree." << endl;
        return node;
    }

    // 2. Update height of this ancestor node
    node->height = 1 + max(height(node->left), height(node->right));

    // 3. Get the balance factor of this ancestor node to check whether
    // this node became unbalanced
    int balance = getBalance(node);

    // If this node becomes unbalanced, then there are 4 cases

    // Left Left Case
    if (balance > 1 && value < node->left->data)
        return rightRotate(node);

    // Right Right Case
    if (balance < -1 && value > node->right->data)
        return leftRotate(node);

    // Left Right Case
    if (balance > 1 && value > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && value < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    // Return the (unchanged) node pointer
    return node;
}

void displayInOrder(node* root) {
    if (root != NULL) {
        displayInOrder(root->left);
        cout << root->data << " ";
        displayInOrder(root->right);
    }
}

void displayPreOrder(node* root) {
    if (root != NULL) {
        cout << root->data << " ";
        displayPreOrder(root->left);
        displayPreOrder(root->right);
    }
}

void displayPostOrder(node* root) {
    if (root != NULL) {
        displayPostOrder(root->left);
        displayPostOrder(root->right);
        cout << root->data << " ";
    }
}

node* search(node* root, int key) {
    if (root == NULL || root->data == key) {
        return root;
    }
    if (key < root->data) {
        return search(root->left, key);
    } else {
        return search(root->right, key);
    }
}

node* findMin(node* n) {
     current_node = n;

    // loop down to find the leftmost leaf
    while (current_node->left != NULL)
        current_node = current_node->left;

    return current_node;
}

node* deleteNode(node* root, int key) {
    // STEP 1: PERFORM STANDARD BST DELETE

    if (root == NULL)
        return root;

    // If the key to be deleted is smaller than the root's key,
    // then it lies in the left subtree
    if (key < root->data)
        root->left = deleteNode(root->left, key);

    // If the key to be deleted is greater than the root's key,
    // then it lies in the right subtree
    else if (key > root->data)
        root->right = deleteNode(root->right, key);

    // if key is same as root's key, then this is the node
    // to be deleted
    else {
        // node with only one child or no child
        if ((root->left == NULL) || (root->right == NULL)) {
            node* temp = root->left ? root->left : root->right;

            // No child case
            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else // One child case
                *root = *temp; // Copy the contents of the non-empty child
            delete temp;
        } else {
            // node with two children: Get the inorder successor (smallest
            // in the right subtree)
            node* temp = findMin(root->right);

            // Copy the inorder successor's data to this node
            root->data = temp->data;

            // Delete the inorder successor
            root->right = deleteNode(root->right, temp->data);
        }
    }

    // If the tree had only one node then return
    if (root == NULL)
        return root;

    // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE
    root->height = 1 + max(height(root->left), height(root->right));

    // STEP 3: GET THE BALANCE FACTOR OF THIS NODE (to check whether
    // this node became unbalanced)
    int balance = getBalance(root);

    // If this node becomes unbalanced, then there are 4 cases

    // Left Left Case
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    // Left Right Case
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Right Case
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    // Right Left Case
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void menu() {
    cout << "AVL Tree Operations Menu" << endl;
    cout << "1. Insert" << endl;
    cout << "2. Search" << endl;
    cout << "3. Delete" << endl;
    cout << "4. Display In-Order" << endl;
    cout << "5. Display Pre-Order" << endl;
    cout << "6. Display Post-Order" << endl;
    cout << "7. Exit" << endl;
}

int main() {
    int choice, value;
    do {
        menu();
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                root = insert(root, value);
                break;
            case 2:
                cout << "Enter value to search: ";
                cin >> value;
                if (search(root, value) != NULL) {
                    cout << "Value found in the tree." << endl;
                } else {
                    cout << "Value not found in the tree." << endl;
                }
                break;
            case 3:
                cout << "Enter value to delete: ";
                cin >> value;
                root = deleteNode(root, value);
                break;
            case 4:
                cout << "In-Order Traversal: ";
                displayInOrder(root);
                cout << endl;
                break;
            case 5:
                cout << "Pre-Order Traversal: ";
                displayPreOrder(root);
                cout << endl;
                break;
            case 6:
                cout << "Post-Order Traversal: ";
                displayPostOrder(root);
                cout << endl;
                break;
            case 7:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice! Please choose again." << endl;
        }
    } while (choice != 7);

    return 0;
}
