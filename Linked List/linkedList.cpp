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

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    // Insertion at the beginning of the list
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    // Insertion at the end of the list
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Insertion at a specific position in the list
    void insertAtPosition(int value, int position) {
        if (position <= 0) {
            cout << "Invalid position\n";
            return;
        }
        if (position == 1) {
            insertAtBeginning(value);
            return;
        }
        Node* newNode = new Node(value);
        Node* temp = head;
        for (int i = 1; i < position - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }
        if (temp == nullptr) {
            cout << "Invalid position\n";
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Display the elements of the list
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Delete from the beginning of the list
    void deleteFromBeginning() {
        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // Delete from the end of the list
    void deleteFromEnd() {
        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }

    // Delete from a specific position in the list
    void deleteFromPosition(int position) {
        if (position <= 0 || head == nullptr) {
            cout << "Invalid position or List is empty\n";
            return;
        }
        if (position == 1) {
            deleteFromBeginning();
            return;
        }
        Node* temp = head;
        for (int i = 1; i < position - 1 && temp->next != nullptr; i++) {
            temp = temp->next;
        }
        if (temp->next == nullptr) {
            cout << "Invalid position\n";
            return;
        }
        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }

    // Delete by value
    void deleteByValue(int value) {
        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }
        if (head->data == value) {
            deleteFromBeginning();
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr && temp->next->data != value) {
            temp = temp->next;
        }
        if (temp->next == nullptr) {
            cout << "Value not found in the list\n";
            return;
        }
        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }

    // Iterative Traversal
    void iterativeTraversal() {
        Node* temp = head;
        cout << "Iterative Traversal: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Recursive Traversal
    void recursiveTraversal(Node* node) {
        if (node == nullptr) {
            return;
        }
        cout << node->data << " ";
        recursiveTraversal(node->next);
    }

    // Linear Search
    bool linearSearch(int value) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == value) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    // Update value at a specific position
    void update(int value, int position) {
        if (position <= 0 || head == nullptr) {
            cout << "Invalid position or List is empty\n";
            return;
        }
        Node* temp = head;
        for (int i = 1; i < position && temp != nullptr; i++) {
            temp = temp->next;
        }
        if (temp == nullptr) {
            cout << "Invalid position\n";
            return;
        }
        temp->data = value;
    }

    // Calculate Length
    int calculateLength() {
        int length = 0;
        Node* temp = head;
        while (temp != nullptr) {
            length++;
            temp = temp->next;
        }
        return length;
    }

    // Merge Two Lists
void merge(LinkedList& list2) {
    if (head == nullptr) {
        head = list2.head;
        list2.head = nullptr;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = list2.head;
    list2.head = nullptr;
}

// Reverse the List
void reverse() {
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;
    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}
// Recursive Traversal
void recursiveTraversal(Node* node) {
    if (node == nullptr) {
        return;
    }
    cout << node->data << " ";
    recursiveTraversal(node->next);
}

};
int main() {
    LinkedList list1, list2;
    int choice, value, position;

    while (true) {
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert at Specific Position\n";
        cout << "4. Delete from Beginning\n";
        cout << "5. Delete from End\n";
        cout << "6. Delete from Specific Position\n";
        cout << "7. Delete by Value\n";
        cout << "8. Iterative Traversal\n";
        cout << "9. Recursive Traversal\n";
        cout << "10. Linear Search\n";
        cout << "11. Update\n";
        cout << "12. Calculate Length\n";
        cout << "13. Merge Two Lists\n";
        cout << "14. Reverse\n";
        cout << "15. Display\n";
        cout << "16. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert at beginning: ";
                cin >> value;
                list1.insertAtBeginning(value);
                break;
            case 2:
                cout << "Enter value to insert at end: ";
                cin >> value;
                list1.insertAtEnd(value);
                break;
            case 3:
                cout << "Enter value to insert: ";
                cin >> value;
                cout << "Enter position: ";
                cin >> position;
                list1.insertAtPosition(value, position);
                break;
            case 4:
                list1.deleteFromBeginning();
                break;
            case 5:
                list1.deleteFromEnd();
                break;
            case 6:
                cout << "Enter position to delete: ";
                cin >> position;
                list1.deleteFromPosition(position);
                break;
            case 7:
                cout << "Enter value to delete: ";
                cin >> value;
                list1.deleteByValue(value);
                break;
            case 8:
                list1.iterativeTraversal();
                break;
            case 9:
                cout << "Recursive Traversal: ";
                list1.recursiveTraversal();
                cout << endl;
                break;
            case 10:
                cout << "Enter value to search: ";
                cin >> value;
                if (list1.linearSearch(value))
                    cout << "Value found in the list\n";
                else
                    cout << "Value not found in the list\n";
                break;
            case 11:
                cout << "Enter value to update: ";
                cin >> value;
                cout << "Enter position: ";
                cin >> position;
                list1.update(value, position);
                break;
            case 12:
            
                cout << "Length of the list: " << list1.calculateLength() << endl;
                break;
            case 13:
                cout << "Creating a second list for merging\n";
                cout << "Enter number of elements for the second list: ";
                int n;
                cin >> n;
                cout << "Enter elements for the second list:\n";
                for (int i = 0; i < n; ++i) {
                    cin >> value;
                    list2.insertAtEnd(value);
                }
                list1.merge(list2);
                cout << "Lists merged successfully\n";
                break;
            case 14:
                list1.reverse();
                cout << "List reversed successfully\n";
                break;
            case 15:
                cout << "List: ";
                list1.display();
                break;
            case 16:
                exit(0);
            default:
                cout << "Invalid choice\n";
        }
    }

    return 0;
}
