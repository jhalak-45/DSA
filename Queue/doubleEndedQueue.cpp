#include <iostream>
using namespace std;

#define SIZE 5  // Define the size of the deque

class Dequeue{
private:
    int front, rear;
    int items[SIZE];

public:
    Dequeue() {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        if ((front == 0 && rear == SIZE - 1) || (front == rear + 1)) {
            return true;
        }
        return false;
    }

    bool isEmpty() {
        if (front == -1) return true;
        return false;
    }

    void enqueueFront(int element) {
        if (isFull()) {
            cout << "Dequeueis full"<<endl;
            return;
        }
        if (front == -1) {
            front = 0;
            rear = 0;
        } else if (front == 0) {
            front = SIZE - 1;
        } else {
            front = front - 1;
        }
        items[front] = element;
        cout << "Inserted " << element << " at front"<<endl;
    }

    void enqueueRear(int element) {
        if (isFull()) {
            cout << "Dequeueis full"<<endl;
            return;
        }
        if (front == -1) {
            front = 0;
            rear = 0;
        } else if (rear == SIZE - 1) {
            rear = 0;
        } else {
            rear = rear + 1;
        }
        items[rear] = element;
        cout << "Inserted " << element << " at rear"<<endl;
    }

    void dequeueFront() {
        if (isEmpty()) {
            cout << "Dequeueis empty"<<endl;
            return;
        }
        cout << "Deleted " << items[front] << " from front"<<endl;
        if (front == rear) {
            front = -1;
            rear = -1;
        } else if (front == SIZE - 1) {
            front = 0;
        } else {
            front = front + 1;
        }
    }

    void dequeueRear() {
        if (isEmpty()) {
            cout << "Dequeueis empty"<<endl;
            return;
        }
        cout << "Deleted " << items[rear] << " from rear"<<endl;
        if (front == rear) {
            front = -1;
            rear = -1;
        } else if (rear == 0) {
            rear = SIZE - 1;
        } else {
            rear = rear - 1;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Dequeueis empty"<<endl;
            return;
        }
        cout << "Front -> " << front << endl;
        cout << "Items -> "<<endl;
        int i = front;
        while (true) {
            cout << items[i] << " "<<endl;
            if (i == rear) break;
            i = (i + 1) % SIZE;
        }
        cout << endl;
        cout << "Rear -> " << rear << endl;
    }
};

int main() {
    Dequeue dq;
    int choice, value;
    while (true) {
        cout << "Menu:"<<endl;
        cout << "1. Enqueue Front"<<endl;
        cout << "2. Enqueue Rear"<<endl;
        cout << "3. Dequeue Front"<<endl;
        cout << "4. Dequeue Rear"<<endl;
        cout << "5. Display"<<endl;
        cout << "6. Exit"<<endl;
        cout << "Enter your choice: "<<endl;
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value to enqueue at front: "<<endl;
                cin >> value;
                dq.enqueueFront(value);
                break;
            case 2:
                cout << "Enter the value to enqueue at rear: "<<endl;
                cin >> value;
                dq.enqueueRear(value);
                break;
            case 3:
                dq.dequeueFront();
                break;
            case 4:
                dq.dequeueRear();
                break;
            case 5:
                dq.display();
                break;
            case 6:
                exit(0);
            default:
                cout << "Invalid choice"<<endl;
        }
    }
    return 0;
}
