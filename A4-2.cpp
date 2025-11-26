// Develop a menu driven program demonstrating the following operations on Circular Queues: 
// enqueue(), dequeue(), isEmpty(), isFull(), display(), and peek(). 

#include <iostream>
using namespace std;

#define SIZE 5  

class CircularQueue {
private:
    int arr[SIZE];
    int front, rear;

public:
    CircularQueue() {
        front = rear = -1;
    }

    bool isEmpty() {
        return (front == -1);
    }

    bool isFull() {
        return ((front == 0 && rear == SIZE - 1) || (rear + 1 == front));
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is FULL! Cannot enqueue.\n";
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % SIZE;
        }
        arr[rear] = value;
        cout << "Enqueued: " << value << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is EMPTY! Cannot dequeue.\n";
            return;
        }

        int removed = arr[front];
        if (front == rear) { // Only one element
            front = rear = -1;
        } else {
            front = (front + 1) % SIZE;
        }
        cout << "Dequeued: " << removed << endl;
    }

    void peek() {
        if (isEmpty()) {
            cout << "Queue is EMPTY! Nothing to peek.\n";
            return;
        }
        cout << "Front Element: " << arr[front] << endl;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is EMPTY!\n";
            return;
        }
        cout << "Queue elements: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % SIZE;
        }
        cout << endl;
    }
};

int main() {
    CircularQueue q;
    int choice, value;

    do {
        cout << "\n--- Circular Queue Menu ---\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek\n";
        cout << "4. Check if Empty\n";
        cout << "5. Check if Full\n";
        cout << "6. Display Queue\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to enqueue: ";
            cin >> value;
            q.enqueue(value);
            break;

        case 2:
            q.dequeue();
            break;

        case 3:
            q.peek();
            break;

        case 4:
            cout << (q.isEmpty() ? "Queue is EMPTY\n" : "Queue is NOT empty\n");
            break;

        case 5:
            cout << (q.isFull() ? "Queue is FULL\n" : "Queue is NOT full\n");
            break;

        case 6:
            q.display();
            break;

        case 7:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 7);

    return 0;
}
