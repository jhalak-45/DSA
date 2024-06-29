#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
    node* prev;
};

node* first_node = NULL;
node* new_node;
node* current_node;
node* temp_node;

void insertAtBegin(int value) {
    new_node = new node;
    new_node->data = value;
    new_node->next = first_node;
    new_node->prev = NULL;

    if (first_node != NULL) {
        first_node->prev = new_node;
    }
    first_node = new_node;
    cout << "Inserted data: " << value << " at beginning" << endl;
}

void insertAtEnd(int value) {
    new_node = new node;
    new_node->data = value;
    new_node->next = NULL;

    if (first_node == NULL) {
        new_node->prev = NULL;
        first_node = new_node;
    } else {
        current_node = first_node;
        while (current_node->next != NULL) {
            current_node = current_node->next;
        }
        current_node->next = new_node;
        new_node->prev = current_node;
    }
    cout << "Inserted data: " << value << " at end" << endl;
}

void insertAfter(int position, int value) {
    if (position < 1) {
        cout << "Invalid Position, Enter Valid position" << endl;
        return;
    }

    new_node = new node;
    new_node->data = value;

    current_node = first_node;
    for (int i = 1; i < position; i++) {
        if (current_node == NULL) {
            cout << "Invalid Position, Enter Valid position" << endl;
            return;
        }
        current_node = current_node->next;
    }

    if (current_node != NULL) {
        new_node->next = current_node->next;
        new_node->prev = current_node;
        if (current_node->next != NULL) {
            current_node->next->prev = new_node;
        }
        current_node->next = new_node;
        cout << "Inserted data: " << value << " after position " << position << endl;
    }
}

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
        if (current_node == NULL) {
            cout << "Invalid Position, Enter Valid position" << endl;
            return;
        }
        current_node = current_node->next;
    }

    if (current_node != NULL) {
        new_node->next = current_node->next;
        new_node->prev = current_node;
        if (current_node->next != NULL) {
            current_node->next->prev = new_node;
        }
        current_node->next = new_node;
        cout << "Inserted data: " << value << " before position " << position << endl;
    }
}

void deleteAtBegin() {
    if (first_node == NULL) {
        cout << "List is empty. Nothing to delete." << endl;
        return;
    }

    temp_node = first_node;
    first_node = first_node->next;

    if (first_node != NULL) {
        first_node->prev = NULL;
    }

    delete temp_node;
    cout << "Deleted node from beginning." << endl;
}

void deleteAtEnd() {
    if (first_node == NULL) {
        cout << "List is empty. Nothing to delete." << endl;
        return;
    }

    current_node = first_node;
    while (current_node->next != NULL) {
        current_node = current_node->next;
    }

    if (current_node->prev != NULL) {
        current_node->prev->next = NULL;
    } else {
        // Deleting the only node in the list
        first_node = NULL;
    }

    delete current_node;
    cout << "Deleted node from end." << endl;
}

void deleteAfter(int position) {
    if (position < 1 || first_node == NULL) {
        cout << "Invalid Position or List is empty. Enter Valid position." << endl;
        return;
    }

    current_node = first_node;
    for (int i = 1; i < position; i++) {
        if (current_node == NULL) {
            cout << "Invalid Position, Enter Valid position" << endl;
            return;
        }
        current_node = current_node->next;
    }

    if (current_node != NULL && current_node->next != NULL) {
        temp_node = current_node->next;
        current_node->next = temp_node->next;
        if (temp_node->next != NULL) {
            temp_node->next->prev = current_node;
        }
        delete temp_node;
        cout << "Deleted node after position " << position << endl;
    } else {
        cout << "No node found after position " << position << " to delete." << endl;
    }
}

void deleteBefore(int position) {
    if (position <= 1 || first_node == NULL) {
        cout << "Invalid Position or List is empty. Enter Valid position." << endl;
        return;
    }

    current_node = first_node;
    for (int i = 1; i < position - 1; i++) {
        if (current_node == NULL) {
            cout << "Invalid Position, Enter Valid position" << endl;
            return;
        }
        current_node = current_node->next;
    }

    if (current_node != NULL && current_node->prev != NULL) {
        temp_node = current_node->prev;
        current_node->prev = temp_node->prev;
        if (temp_node->prev != NULL) {
            temp_node->prev->next = current_node;
        } else {
            // Deleting the first node
            first_node = current_node;
        }
        delete temp_node;
        cout << "Deleted node before position " << position << endl;
    } else {
        cout << "No node found before position " << position << " to delete." << endl;
    }
}

void display() {
    node* ptr = first_node;
    if (first_node == NULL) {
        cout << "Empty List" << endl;
    } else {
        while (ptr != NULL) {
            cout << ptr->data << " <-> ";
            ptr = ptr->next;
        }
        cout << "NULL" << endl;
    }
}

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