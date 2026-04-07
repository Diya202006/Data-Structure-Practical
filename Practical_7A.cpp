// Stack using linked list

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* top = NULL;      
Node* avail = NULL;   
 
Node* getNode() {
    Node* temp;
    if (avail != NULL) {
        temp = avail;
        avail = avail->next;
    } else {
        temp = new Node();
    }
    return temp;
}
 
void freeNode(Node* temp) {
    temp->next = avail;
    avail = temp;
}
 
void push(int x) {
    Node* temp = getNode();

    temp->data = x;
    temp->next = top;
    top = temp;

    cout << x << " pushed into stack\n";
}

void pop() {
    if (top == NULL) {
        cout << "Stack Underflow\n";
        return;
    }

    Node* temp = top;
    cout << "Popped element: " << temp->data << endl;

    top = top->next;

    freeNode(temp);    
}
 
void display() {
    if (top == NULL) {
        cout << "Stack is empty\n";
        return;
    }

    Node* temp = top;
    cout << "Stack elements: ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
 
int main() {
    int choice, value;

    do {
        cout << "\n--- STACK MENU ---\n";
        cout << "1. Push\n2. Pop\n3. Display\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter number to push: ";
                cin >> value;
                push(value);
                break;

            case 2:
                pop();
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