#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Circular Linked List class
class CircularLinkedList {
private:
    Node* last;

public:
    CircularLinkedList() {
        last = nullptr;
    }

    // Insert a node at the beginning of the list
    void insertAtBeginning(int value) {
        Node* newNode = new Node();
        newNode->data = value;

        if (last == nullptr) {
            last = newNode;
            last->next = last;
        } else {
            newNode->next = last->next;
            last->next = newNode;
        }
    }

    // Insert a node at the end of the list
    void insertAtEnd(int value) {
        Node* newNode = new Node();
        newNode->data = value;

        if (last == nullptr) {
            last = newNode;
            last->next = last;
        } else {
            newNode->next = last->next;
            last->next = newNode;
            last = newNode;
        }
    }

    // Delete a node with the given value
    void deleteNode(int value) {
        if (last == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        Node* current = last->next;
        Node* previous = last;

        while (current->data != value) {
            if (current == last) {
                cout << "Node not found." << endl;
                return;
            }
            previous = current;
            current = current->next;
        }

        if (current == last && current->next == last) { // Only one node
            last = nullptr;
        } else if (current == last) { // Deleting last node
            previous->next = last->next;
            last = previous;
        } else if (current == last->next) { // Deleting first node
            last->next = current->next;
        } else { // Deleting any other node
            previous->next = current->next;
        }

        delete current;
    }

    // Display the list
    void display() {
        if (last == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        Node* temp = last->next;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != last->next);
        cout << endl;
    }
};

// Menu function
void menu() {
    cout << "Circular Linked List Operations Menu" << endl;
    cout << "1. Insert at Beginning" << endl;
    cout << "2. Insert at End" << endl;
    cout << "3. Delete Node" << endl;
    cout << "4. Display List" << endl;
    cout << "5. Exit" << endl;
}

int main() {
    CircularLinkedList cll;
    int choice, value;

    do {
        menu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert at beginning: ";
                cin >> value;
                cll.insertAtBeginning(value);
                break;
            case 2:
                cout << "Enter value to insert at end: ";
                cin >> value;
                cll.insertAtEnd(value);
                break;
            case 3:
                cout << "Enter value to delete: ";
                cin >> value;
                cll.deleteNode(value);
                break;
            case 4:
                cout << "List: ";
                cll.display();
                break;
            case 5:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice! Please choose again." << endl;
        }

        cout << endl;
    } while (choice != 5);

    return 0;
}
