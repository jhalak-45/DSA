#include <iostream>
using namespace std;
// node class

class Node {
public:
    int data;
    Node* next;
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

//singlylinkedlist class
class SinglyLinkedList {
private:
    Node* head;

public:
    SinglyLinkedList() {
        head = nullptr;
    }

    void insert(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        cout << "Inserted " << value << endl;
    }

    void remove(int value) {
        if (head == nullptr) {
            cout << "List is empty. Nothing to delete." << endl;
            return;
        }

        Node* prev = nullptr;
        Node* curr = head;

        while (curr != nullptr && curr->data != value) {
            prev = curr;
            curr = curr->next;
        }

        if (curr == nullptr) {
            cout << "Value not found in the list." << endl;
            return;
        }

        if (prev == nullptr) {
            head = head->next;
        } else {
            prev->next = curr->next;
        }
        delete curr;
        cout << "Deleted " << value << endl;
    }

    void display() {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }

        Node* temp = head;
        cout << "Linked List: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    SinglyLinkedList list;
    int choice, value;

    while (true) {
        cout << "1. Insert"<<endl;;
        cout << "2. Delete"<<endl;;
        cout << "3. Display"<<endl;;
        cout << "4. Exit"<<endl;;
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
