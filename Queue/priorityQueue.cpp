#include <iostream>
using namespace std;

#define SIZE 5  // Define the size of the priority queue

class PriorityQueue {
private:
    int items[SIZE];
    int front, rear;

public:
    PriorityQueue() {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return rear == SIZE - 1;
    }

    bool isEmpty() {
        return front == -1 || front > rear;
    }

    void enqueue(int element) {
        if (isFull()) {
            cout << "Queue is full"<<endl;
            return;
        }
        if (isEmpty()) {
            front = 0;
        }
        int i;
        for (i = rear; i >= front && items[i] > element; i--) {
            items[i + 1] = items[i];
        }
        items[i + 1] = element;
        rear++;
        cout << "Inserted " << element << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty"<<endl;
            return;
        }
        cout << "Deleted " << items[front] << endl;
        front++;
        if (front > rear) {
            front = rear = -1;  // Reset the queue if it's empty
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty"<<endl;
            return;
        }
        cout << "Front -> " << front << endl;
        cout << "Items -> "<<endl;
        for (int i = front; i <= rear; i++) {
            cout << items[i] << " "<<endl;
        }
        cout << endl;
        cout << "Rear -> " << rear << endl;
    }
};

int main() {
    PriorityQueue pq;
    int choice, value;
    while (true) {
        cout << "1. Enqueue"<<endl;
        cout << "2. Dequeue"<<endl;
        cout << "3. Display"<<endl;
        cout << "4. Exit"<<endl;
        cout << "Enter your choice: "<<endl;
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value to enqueue: "<<endl;
                cin >> value;
                pq.enqueue(value);
                break;
            case 2:
                pq.dequeue();
                break;
            case 3:
                pq.display();
                break;
            case 4:
                exit(0);
            default:
                cout << "Invalid choice"<<endl;
        }
    }
    return 0;
}
