// Various Operations on Doubly Linked-List

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* head = NULL;    
Node* tail = NULL;    
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
    temp->prev = NULL;
    temp->next = head;

    if (head != NULL)
        head->prev = temp;
    else
        tail = temp;

    head = temp;

    cout << value << " inserted at beginning\n";
}
 
void insertEnd(int value) {
    Node* temp = getNode();

    temp->data = value;
    temp->next = NULL;
    temp->prev = tail;

    if (tail != NULL)
        tail->next = temp;
    else
        head = temp;

    tail = temp;

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

    if (head != NULL)
        head->prev = NULL;
    else
        tail = NULL;

    freeNode(temp);
}
 
void deleteEnd() {
    if (tail == NULL) {
        cout << "List is empty\n";
        return;
    }

    Node* temp = tail;
    cout << "Deleted: " << temp->data << endl;

    tail = tail->prev;

    if (tail != NULL)
        tail->next = NULL;
    else
        head = NULL;

    freeNode(temp);
}
 
void displayForward() {
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }

    Node* temp = head;
    cout << "Forward: ";

    while (temp != NULL) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }

    cout << "NULL\n";
}
 
void displayBackward() {
    if (tail == NULL) {
        cout << "List is empty\n";
        return;
    }

    Node* temp = tail;
    cout << "Backward: ";

    while (temp != NULL) {
        cout << temp->data << " <-> ";
        temp = temp->prev;
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
        cout << "\n--- DOUBLY LINKED LIST MENU ---\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Delete from Beginning\n";
        cout << "4. Delete from End\n";
        cout << "5. Display Forward\n";
        cout << "6. Display Backward\n";
        cout << "7. Display AVAIL List\n";
        cout << "8. Exit\n";

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
                displayForward();
                break;

            case 6:
                displayBackward();
                break;

            case 7:
                displayAvail();
                break;

            case 8:
                cout << "Program Ended\n";
                break;

            default:
                cout << "Invalid choice\n";
        }

    } while (choice != 8);

    return 0;
}