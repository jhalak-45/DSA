#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int value) {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void insert(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        cout << "Inserted " << value << endl;
    }

    void remove(int value) {
        if (head == nullptr) {
            cout << "List is empty. Nothing to delete." << endl;
            return;
        }

        Node* curr = head;
        while (curr != nullptr && curr->data != value) {
            curr = curr->next;
        }

        if (curr == nullptr) {
            cout << "Value not found in the list." << endl;
            return;
        }

        if (curr == head && curr == tail) {
            head = nullptr;
            tail = nullptr;
        } else if (curr == head) {
            head = head->next;
            head->prev = nullptr;
        } else if (curr == tail) {
            tail = tail->prev;
            tail->next = nullptr;
        } else {
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
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
        cout << "Doubly Linked List: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList list;
    int choice, value;

    while (true) {
        cout << "1. Insert"<<endl;
        cout << "2. Delete"<<endl;
        cout << "3. Display"<<endl;
        cout << "4. Exit"<<endl;
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
