#include <iostream>
using namespace std;

#define SIZE 6

int tokens[SIZE];
int front = 0;
int rear = -1;
int nextToken = 1;   // next token number to give

bool isEmpty() { return front > rear; }
bool isFull()  { return rear == SIZE - 1; }

void issueToken() {
    if (isFull()) {
        cout << "Waiting room is FULL! Cannot issue more tokens." << endl;
        return;
    }
    rear++;
    tokens[rear] = nextToken;
    cout << "Token " << nextToken << " issued. Please wait." << endl;
    nextToken++;
}

void serveCustomer() {
    if (isEmpty()) {
        cout << "Nobody is waiting." << endl;
        return;
    }
    cout << "Now serving token " << tokens[front] << endl;
    front++;
    if (front > rear) {      // queue empty again: start over
        front = 0;
        rear = -1;
    }
}

void showWaiting() {
    if (isEmpty()) {
        cout << "Nobody is waiting." << endl;
        return;
    }
    cout << "Waiting customers (FRONT -> REAR): ";
    for (int i = front; i <= rear; i++)
        cout << tokens[i] << " ";
    cout << endl;
}

int main() {
    int choice;
    do {
        cout << "\n*** Bank Token System ***" << endl;
        cout << "1. Issue token  2. Serve customer  3. Show waiting  4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: issueToken();   break;
            case 2: serveCustomer(); break;
            case 3: showWaiting();  break;
            case 4: cout << "Exiting..." << endl; break;
            default: cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 4);
    return 0;
}
