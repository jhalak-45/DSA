#include <iostream>
using namespace std;

// Define the structure for a BST node
struct TreeNode {
    int key;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : key(value), left(nullptr), right(nullptr) {}
};

// BST class with methods for various operations
class BinarySearchTree {
private:
    TreeNode* root;

    // Helper method for inserting a new node
    TreeNode* insert(TreeNode* node, int key) {
        if (node == nullptr) {
            return new TreeNode(key);
        }
        if (key < node->key) {
            node->left = insert(node->left, key);
        } else if (key > node->key) {
            node->right = insert(node->right, key);
        }
        return node;
    }

    // Helper method for searching a node by key
    TreeNode* search(TreeNode* node, int key) {
        if (node == nullptr || node->key == key) {
            return node;
        }
        if (key < node->key) {
            return search(node->left, key);
        } else {
            return search(node->right, key);
        }
    }

    // Helper method for inorder traversal
    void inorder(TreeNode* node) {
        if (node != nullptr) {
            inorder(node->left);
            cout << node->key << " ";
            inorder(node->right);
        }
    }

    // Helper method for finding the minimum value
    TreeNode* findMin(TreeNode* node) {
        while (node && node->left) {
            node = node->left;
        }
        return node;
    }

    // Helper method for finding the maximum value
    TreeNode* findMax(TreeNode* node) {
        while (node && node->right) {
            node = node->right;
        }
        return node;
    }

    // Helper method for deleting a node
    TreeNode* deleteNode(TreeNode* node, int key) {
        if (node == nullptr) return node;

        if (key < node->key) {
            node->left = deleteNode(node->left, key);
        } else if (key > node->key) {
            node->right = deleteNode(node->right, key);
        } else {
            if (node->left == nullptr) {
                TreeNode* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                TreeNode* temp = node->left;
                delete node;
                return temp;
            }

            TreeNode* temp = findMin(node->right);
            node->key = temp->key;
            node->right = deleteNode(node->right, temp->key);
        }
        return node;
    }

public:
    BinarySearchTree() : root(nullptr) {}

    // Public method to insert a new node
    void insert(int key) {
        root = insert(root, key);
    }

    // Public method to search for a key
    bool search(int key) {
        return search(root, key) != nullptr;
    }

    // Public method to perform inorder traversal
    void inorder() {
        inorder(root);
        cout << endl;
    }

    // Public method to find the minimum value
    int findMin() {
        TreeNode* node = findMin(root);
        if (node) return node->key;
        throw runtime_error("Tree is empty");
    }

    // Public method to find the maximum value
    int findMax() {
        TreeNode* node = findMax(root);
        if (node) return node->key;
        throw runtime_error("Tree is empty");
    }

    // Public method to delete a node
    void deleteNode(int key) {
        root = deleteNode(root, key);
    }
};

// Menu for Binary Search Tree operations
void menu() {
    cout << "Binary Search Tree Operations Menu" << endl;
    cout << "1. Insert a Key" << endl;
    cout << "2. Search for a Key" << endl;
    cout << "3. Inorder Traversal" << endl;
    cout << "4. Find Minimum Value" << endl;
    cout << "5. Find Maximum Value" << endl;
    cout << "6. Delete a Key" << endl;
    cout << "7. Exit" << endl;
}

int main() {
    BinarySearchTree bst;
    int choice, key;

    do {
        menu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter key to insert: ";
                cin >> key;
                bst.insert(key);
                cout << "Key inserted!" << endl;
                break;

            case 2:
                cout << "Enter key to search: ";
                cin >> key;
                if (bst.search(key)) {
                    cout << "Key found in the tree." << endl;
                } else {
                    cout << "Key not found in the tree." << endl;
                }
                break;

            case 3:
                cout << "Inorder Traversal of the BST: ";
                bst.inorder();
                break;

            case 4:
                try {
                    cout << "Minimum value in the BST: " << bst.findMin() << endl;
                } catch (const runtime_error& e) {
                    cout << e.what() << endl;
                }
                break;

            case 5:
                try {
                    cout << "Maximum value in the BST: " << bst.findMax() << endl;
                } catch (const runtime_error& e) {
                    cout << e.what() << endl;
                }
                break;

            case 6:
                cout << "Enter key to delete: ";
                cin >> key;
                bst.deleteNode(key);
                cout << "Key deleted (if it existed)!" << endl;
                break;

            case 7:
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "Invalid choice! Please choose again." << endl;
        }

        cout << endl;
    } while (choice != 7);

    return 0;
}
