#include <iostream>
#include <string>
using namespace std;

struct Node {
    string data;
    Node* next;
};

Node* top = NULL;

// Push function
void push(string page) {
    Node* newNode = new Node;
    newNode->data = page;
    newNode->next = top;
    top = newNode;

    cout << "Page visited: " << page << endl;
}

// Pop function
void pop() {
    if (top == NULL || top->next == NULL) {
        cout << "Cannot go back" << endl;
    }
    else {
        Node* temp = top;
        top = top->next;
        delete temp;

        cout << "Current page: " << top->data << endl;
    }
}

// Peek function
void peek() {
    if (top == NULL) {
        cout << "No page visited" << endl;
    }
    else {
        cout << "Current page: " << top->data << endl;
    }
}

// Display function
void display() {
    if (top == NULL) {
        cout << "History is empty" << endl;
        return;
    }

    Node* current = top;

    cout << "Browser History:" << endl;

    while (current != NULL) {
        cout << current->data << endl;
        current = current->next;
    }
}

// Free all nodes before the program ends
void clearStack() {
    while (top != NULL) {
        Node* temp = top;
        top = top->next;
        delete temp;
    }
}

// Main function
int main() {
    int choice;
    string page;

    do {
        cout << "\n1. Visit Page";
        cout << "\n2. Back";
        cout << "\n3. Current Page";
        cout << "\n4. History";
        cout << "\n0. Exit";

        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter page name: ";
                cin >> page;
                push(page);
                break;

            case 2:
                pop();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 0:
                clearStack();
                cout << "Goodbye!" << endl;
                break;

            default:
                cout << "Invalid choice" << endl;
        }

    } while (choice != 0);

    return 0;
}
