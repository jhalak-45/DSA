#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class CircularLinkedList {
private:
    Node* head;

public:
    CircularLinkedList() {
        head = nullptr;
    }

    // Function to insert a new node at the end of the circular linked list
    void insert(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            head->next = head;  // Point to itself to form a circular structure
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
        cout << "Inserted " << value << endl;
    }

    // Function to delete a node with a given value from the circular linked list
    void remove(int value) {
        if (head == nullptr) {
            cout << "List is empty. Nothing to delete." << endl;
            return;
        }

        Node* curr = head;
        Node* prev = nullptr;
        bool found = false;

        do {
            if (curr->data == value) {
                found = true;
                break;
            }
            prev = curr;
            curr = curr->next;
        } while (curr != head);

        if (!found) {
            cout << "Value not found in the list." << endl;
            return;
        }

        if (curr == head) {
            if (head->next == head) {
                delete head;
                head = nullptr;
            } else {
                Node* temp = head;
                while (temp->next != head) {
                    temp = temp->next;
                }
                temp->next = head->next;
                Node* delNode = head;
                head = head->next;
                delete delNode;
            }
        } else {
            prev->next = curr->next;
            delete curr;
        }

        cout << "Deleted :" << value << endl;
    }

    // Function to display the elements of the circular linked list
    void display() {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }

        Node* temp = head;
        cout << "Circular Linked List: ";
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};

int main() {
    CircularLinkedList list;
    int choice, value;

    while (true) {
        cout << "1. Insert" << endl;
        cout << "2. Delete" << endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value to insert: ";
                cin >> value;
                list.insert(value);
                break;
            case 2:
                cout << "Enter the value to delete: ";
                cin >> value;
                list.remove(value);
                break;
            case 3:
                list.display();
                break;
            case 4:
                exit(0);
            default:
                cout << "Invalid choice" << endl;
        }
    }

    return 0;
}
