#include <iostream>
using namespace std;

struct node {
    int data;
    node* left;
    node* right;
};

// Root node 
node* root = NULL;

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
    }else {
        cout << "Value " << value << " already exists in the tree."<<endl;
    }
    return root;
    
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
        cout << root->data << "->";
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

node* findMin(node* root) {
    while (root->left != NULL) root = root->left;
    return root;
}

node* deleteNode(node* root, int key) {
    if (root == NULL) return root;
    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        if (root->left == NULL) {
            node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            node* temp = root->left;
            delete root;
            return temp;
        }
        node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
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

void menu() {
    cout << "Binary Search Tree Operations Menu"<<endl;
    cout << "1. Insert node "<<endl;
    cout << "2. Search Element"<<endl;
    cout << "3. Delete Node"<<endl;
    cout << "4. Display In-Order"<<endl;
    cout << "5. Display Pre-Order"<<endl;
    cout << "6. Display Post-Order"<<endl;
    cout << "7. Height of Left Sub-tree"<<endl;
    cout << "8. Height of Right Sub-tree"<<endl;
    cout << "9. Exit"<<endl;
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
                    cout << "Value found in the tree."<<endl;
                } else {
                    cout << "Value not found in the tree."<<endl;
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
                cout << "Height of Left Sub-tree: " << leftHeight(root->left) << endl;
                break;
            case 8:
                cout << "Height of Right Sub-tree: " << rightHeight(root->right) << endl;
                break;
            case 9:
                cout << "Exiting..."<<endl;
                return 0;
            default:
                cout << "Invalid choice! Please choose again."<<endl;;
        }
    } while (choice != 9);

    return 0;
}
