// Develop a menu driven program demonstrating the following operations on simple 
// Queues: enqueue(), dequeue(), isEmpty(), isFull(), display(), and peek(). 

#include <iostream>
using namespace std;

#define MAX 5

class Queue {
private:
    int arr[MAX];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return (front == -1);
    }

    bool isFull() {
        return (rear == MAX - 1);
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "\nQueue is FULL! Cannot enqueue.\n";
            return;
        }
        if (front == -1)
            front = 0;
        arr[++rear] = value;
        cout << "\nInserted " << value << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "\nQueue is EMPTY! Cannot dequeue.\n";
            return;
        }
        cout << "\nDeleted: " << arr[front] << endl;

        if (front == rear) {
            // queue becomes empty
            front = rear = -1;
        } else {
            front++;
        }
    }

    void peek() {
        if (isEmpty()) {
            cout << "\nQueue is EMPTY!\n";
            return;
        }
        cout << "\nFront element: " << arr[front] << endl;
    }

    void display() {
        if (isEmpty()) {
            cout << "\nQueue is EMPTY!\n";
            return;
        }
        cout << "\nQueue elements: ";
        for (int i = front; i <= rear; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    Queue q;
    int choice, value;

    do {
        cout << "\n\n--- QUEUE MENU ---\n";
        cout << "1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Check if Empty\n6. Check if Full\n7. Exit\n";
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
            q.display();
            break;

        case 5:
            cout << (q.isEmpty() ? "\nQueue is EMPTY\n" : "\nQueue is NOT empty\n");
            break;

        case 6:
            cout << (q.isFull() ? "\nQueue is FULL\n" : "\nQueue is NOT full\n");
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
