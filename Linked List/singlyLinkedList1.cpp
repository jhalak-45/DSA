#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
};

node* first_node = nullptr;
node* new_node;
node* current_node;
node* temp_node;

// Function to insert a node at the beginning of the list
void insertAtBegin(int value) {
    new_node = new node;
    new_node->data = value;
    new_node->next = first_node;
    first_node = new_node;
    cout << "Inserted data: " << value << " at beginning" << endl;
}

// Function to insert a node at the end of the list
void insertAtEnd(int value) {
    new_node = new node;
    new_node->data = value;
    new_node->next = nullptr;

    if (first_node == nullptr) {
        first_node = new_node;
    } else {
        current_node = first_node;
        while (current_node->next != nullptr) {
            current_node = current_node->next;
        }
        current_node->next = new_node;
    }
    cout << "Inserted data: " << value << " at end" << endl;
}

// Function to insert a node after a given position
void insertAfter(int position, int value) {
    if (position < 1) {
        cout << "Invalid Position, Enter Valid position" << endl;
        return;
    }

    new_node = new node;
    new_node->data = value;

    current_node = first_node;
    for (int i = 1; i < position; i++) {
        if (current_node == nullptr) {
            cout << "Invalid Position, Enter Valid position" << endl;
            return;
        }
        current_node = current_node->next;
    }

    if (current_node != nullptr) {
        new_node->next = current_node->next;
        current_node->next = new_node;
        cout << "Inserted data: " << value << " after position " << position << endl;
    }
}

// Function to insert a node before a given position
void insertBefore(int position, int value) {
    if (position < 1) {
        cout << "Invalid Position, Enter Valid position" << endl;
        return;
    }

    if (position == 1) {
        insertAtBegin(value);
        return;
    }

    new_node = new node;
    new_node->data = value;

    current_node = first_node;
    for (int i = 1; i < position - 1; i++) {
        if (current_node == nullptr) {
            cout << "Invalid Position, Enter Valid position" << endl;
            return;
        }
        current_node = current_node->next;
    }

    if (current_node != nullptr) {
        new_node->next = current_node->next;
        current_node->next = new_node;
        cout << "Inserted data: " << value << " before position " << position << endl;
    }
}

// Function to delete the node at the beginning of the list
void deleteAtBegin() {
    if (first_node == nullptr) {
        cout << "List is empty. Nothing to delete." << endl;
        return;
    }

    temp_node = first_node;
    first_node = first_node->next;
    delete temp_node;
    cout << "Deleted node from the beginning." << endl;
}

// Function to delete the node at the end of the list
void deleteAtEnd() {
    if (first_node == nullptr) {
        cout << "List is empty. Nothing to delete." << endl;
        return;
    }

    if (first_node->next == nullptr) {
        delete first_node;
        first_node = nullptr;
        cout << "Deleted node from the end." << endl;
        return;
    }

    current_node = first_node;
    while (current_node->next->next != nullptr) {
        current_node = current_node->next;
    }

    temp_node = current_node->next;
    current_node->next = nullptr;
    delete temp_node;
    cout << "Deleted node from the end." << endl;
}

// Function to delete the node after a given position
void deleteAfter(int position) {
    if (position < 1 || first_node == nullptr) {
        cout << "Invalid position or list is empty. Deletion failed." << endl;
        return;
    }

    current_node = first_node;
    for (int i = 1; i < position && current_node != nullptr; ++i) {
        current_node = current_node->next;
    }

    if (current_node == nullptr || current_node->next == nullptr) {
        cout << "No node found after position " << position << ". Deletion failed." << endl;
        return;
    }

    temp_node = current_node->next;
    current_node->next = temp_node->next;
    delete temp_node;
    cout << "Deleted node after position " << position << "." << endl;
}

// Function to delete the node before a given position
void deleteBefore(int position) {
    if (position <= 1 || first_node == nullptr || first_node->next == nullptr) {
        cout << "Invalid position or list is empty. Deletion failed." << endl;
        return;
    }

    if (position == 2) {
        deleteAtBegin();
        return;
    }

    current_node = first_node;
    for (int i = 1; i < position - 1 && current_node != nullptr; ++i) {
        current_node = current_node->next;
    }

    if (current_node == nullptr || current_node->next == nullptr || current_node->next->next == nullptr) {
        cout << "No node found before position " << position << ". Deletion failed." << endl;
        return;
    }

    temp_node = current_node->next;
    current_node->next = temp_node->next;
    delete temp_node;
    cout << "Deleted node before position " << position << "." << endl;
}

// Function to display the singly linked list
void display() {
    current_node = first_node;
    if (current_node == nullptr) {
        cout << "Empty List" << endl;
        return;
    }

    cout << "List: ";
    while (current_node != nullptr) {
        cout << current_node->data << " -> ";
        current_node = current_node->next;
    }
    cout << "NULL" << endl;
}

// Main function to test the singly linked list operations
int main() {
    insertAtBegin(6);
    insertAtBegin(5);
    insertAtEnd(7);
    display();

    insertAfter(1, 8);
    insertBefore(2, 9);
    insertAtEnd(70);
    display();

    deleteAtBegin();
    deleteAtEnd();
    display();

    deleteAfter(2);
    deleteBefore(3);
    display();

    return 0;
}
