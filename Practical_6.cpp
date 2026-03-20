// Queue

#include <iostream>
using namespace std;

int queue[5];
int front = -1, rear = -1;

void enqueue()
{
    int x;
    cout << "Enter element: ";
    cin >> x;

    if(rear == 4)
        cout << "Queue Overflow\n";
    else
    {
        if(front == -1)
            front = 0;
        rear++;
        queue[rear] = x;
    }
}

void dequeue()
{
    if(front == -1 || front > rear)
        cout << "Queue Underflow\n";
    else
    {
        cout << "Deleted element: " << queue[front] << endl;
        front++;
    }
}

void display()
{
    if(front == -1 || front > rear)
        cout << "Queue is empty\n";
    else
    {
        cout << "Queue elements are: ";
        for(int i = front; i <= rear; i++)
            cout << queue[i] << " ";
    }
}

int main()
{
    int choice;

    do
    {
        cout << "\n1. Enqueue\n2. Dequeue\n3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if(choice == 1)
            enqueue();
        else if(choice == 2)
            dequeue();

    } while(choice != 3);

    display();

    return 0;
}