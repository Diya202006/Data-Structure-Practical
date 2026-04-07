// Various Operations on Singly Linked-List

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;     
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
 
void insertBeg(int value) {
    Node* temp = getNode();

    temp->data = value;
    temp->next = head;
    head = temp;

    cout << value << " inserted at beginning\n";
}
 
void insertEnd(int value) {
    Node* temp = getNode();
    temp->data = value;
    temp->next = NULL;

    if (head == NULL) {
        head = temp;
    } else {
        Node* ptr = head;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }

    cout << value << " inserted at end\n";
}
 
void deleteBeg() {
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }

    Node* temp = head;
    cout << "Deleted: " << temp->data << endl;

    head = head->next;

    freeNode(temp);
}
 
void deleteEnd() {
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }

    Node* temp = head;
    Node* prev = NULL;

    if (head->next == NULL) {
        cout << "Deleted: " << head->data << endl;
        freeNode(head);
        head = NULL;
        return;
    }

    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    cout << "Deleted: " << temp->data << endl;

    prev->next = NULL;

    freeNode(temp);
}
 
void display() {
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }

    Node* temp = head;
    cout << "Linked List: ";

    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL\n";
}
 
void displayAvail() {
    Node* temp = avail;

    cout << "AVAIL List: ";
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL\n";
}
  
int main() {
    int choice, value;

    do {
        cout << "\n--- LINKED LIST MENU ---\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Delete from Beginning\n";
        cout << "4. Delete from End\n";
        cout << "5. Display List\n";
        cout << "6. Display AVAIL List\n";
        cout << "7. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                insertBeg(value);
                break;

            case 2:
                cout << "Enter value: ";
                cin >> value;
                insertEnd(value);
                break;

            case 3:
                deleteBeg();
                break;

            case 4:
                deleteEnd();
                break;

            case 5:
                display();
                break;

            case 6:
                displayAvail();
                break;

            case 7:
                cout << "Program Ended\n";
                break;

            default:
                cout << "Invalid choice\n";
        }

    } while (choice != 7);

    return 0;
}