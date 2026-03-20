// Hashing

#include <iostream>
using namespace std;

#define SIZE 7   

int table[SIZE];   

int hashFunc(int key) {
    return key % SIZE;
}

void insert(int key) {
    int index = hashFunc(key);
    while (table[index] != -1 && table[index] != -2) {
        index = (index + 1) % SIZE; 
    }
    table[index] = key;
    cout << "Inserted " << key << " at index " << index << endl;
}

void search(int key) {
    int index = hashFunc(key);
    int start = index;
    while (table[index] != -1) {
        if (table[index] == key) {
            cout << key << " found at index " << index << endl;
            return;
        }
        index = (index + 1) % SIZE;
        if (index == start) 
        break;
    }
    cout << key << " not found\n";
}

void removeKey(int key) {
    int index = hashFunc(key);
    int start = index;
    while (table[index] != -1) {
        if (table[index] == key) {
            table[index] = -2; 
            cout << key << " deleted from index " << index << endl;
            return;
        }
        index = (index + 1) % SIZE;
        if (index == start) break;
    }
    cout << key << " not found, cannot delete\n";
}

void display() {
    cout << "\nHash Table:\n";
    for (int i = 0; i < SIZE; i++) {
        cout << i << " --> " << table[i] << endl;
    }
}

int main() {
    for (int i = 0; i < SIZE; i++) table[i] = -1;

    int n;
    cout << "How many numbers to insert? ";
    cin >> n;

    cout << "Enter " << n << " numbers: ";
    for (int i = 0; i < n; i++) {
        int key;
        cin >> key;
        insert(key);
    }

    display();

    int s;
    cout << "\nEnter a number to search: ";
    cin >> s;
    search(s);

    int d;
    cout << "\nEnter a number to delete: ";
    cin >> d;
    removeKey(d);

    display();

    return 0;
}