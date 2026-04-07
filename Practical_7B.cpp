// Queue using linked list

#include <iostream>
using namespace std;

#define MAX 10    

struct Node {
    int data;
    int next;
};

Node nodes[MAX];

int front = -1;
int rear = -1;
int avail = 0;
 
void initialize() {
    for (int i = 0; i < MAX - 1; i++) {
        nodes[i].next = i + 1;
    }
    nodes[MAX - 1].next = -1;
}
 
int getNode() {
    if (avail == -1)
        return -1;

    int p = avail;
    avail = nodes[avail].next;
    return p;
}
 
void freeNode(int p) {
    nodes[p].next = avail;
    avail = p;
}
 
void enqueue(int x) {
    int p = getNode();

    if (p == -1) {
        cout << "Queue Overflow\n";
        return;
    }

    nodes[p].data = x;
    nodes[p].next = -1;

    if (front == -1) {
        front = rear = p;
    } else {
        nodes[rear].next = p;
        rear = p;
    }

    cout << x << " inserted\n";
}
 
void dequeue() {
    if (front == -1) {
        cout << "Queue Underflow\n";
        return;
    }

    int p = front;
    cout << nodes[p].data << " deleted\n";

    front = nodes[p].next;

    if (front == -1) {
        rear = -1;
    }

    freeNode(p);
}
 
void display() {
    if (front == -1) {
        cout << "Queue is empty\n";
        return;
    }

    int temp = front;
    cout << "Queue elements: ";

    while (temp != -1) {
        cout << nodes[temp].data << " ";
        temp = nodes[temp].next;
    }

    cout << endl;
}

int main() {
    int choice, value;

    initialize();  

    do {
        cout << "\n--- QUEUE MENU ---\n";
        cout << "1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice\n";
        }

    } while (choice != 4);

    return 0;
}