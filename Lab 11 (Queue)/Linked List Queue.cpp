#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* front = NULL;
Node* rear = NULL;

bool isEmpty() { return front == NULL; }

void enqueue(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;
    if (isEmpty()) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    cout << value << " added to the queue." << endl;
}

void dequeue() {
    if (isEmpty()) {
        cout << "Queue is EMPTY! Nothing to remove." << endl;
        return;
    }
    Node* temp = front;
    cout << temp->data << " removed from the queue." << endl;
    front = front->next;
    if (front == NULL) rear = NULL;
    delete temp;
}

void peek() {
    if (isEmpty()) { cout << "Queue is EMPTY!" << endl; return; }
    cout << "Front element: " << front->data << endl;
}

void display() {
    if (isEmpty()) { cout << "Queue is EMPTY!" << endl; return; }
    cout << "FRONT -> ";
    Node* temp = front;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
    cout << "(REAR points to " << rear->data << ")" << endl;
}

//  New functions

int countNodes() {
    int count = 0;
    Node* temp = front;
    while (temp != NULL) {      // walk from front to the end
        count++;
        temp = temp->next;
    }
    return count;
}

void displayRear() {
    if (isEmpty()) {
        cout << "Queue is EMPTY! No rear element." << endl;
        return;
    }
    cout << "Rear element: " << rear->data << endl;
}

void clearQueue() {
    if (isEmpty()) {
        cout << "Queue is already EMPTY." << endl;
        return;
    }
    while (front != NULL) {
        Node* temp = front;     // remember the node
        front = front->next;    // move on
        delete temp;            // free it
    }
    rear = NULL;                // queue is empty now
    cout << "Queue cleared. All memory freed." << endl;
}

int main() {
    int choice, value;
    do {
        cout << "\n*** Queue Using Linked List ***" << endl;
        cout << "1. Enqueue  2. Dequeue  3. Peek  4. Display\n";
        cout << "5. Count nodes  6. Display rear  7. Clear queue  8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: cout << "Enter value to enqueue: "; cin >> value; enqueue(value); break;
            case 2: dequeue(); break;
            case 3: peek(); break;
            case 4: display(); break;
            case 5: cout << "Number of nodes: " << countNodes() << endl; break;
            case 6: displayRear(); break;
            case 7: clearQueue(); break;
            case 8: cout << "Exiting..." << endl; break;
            default: cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 8);
    return 0;
}
