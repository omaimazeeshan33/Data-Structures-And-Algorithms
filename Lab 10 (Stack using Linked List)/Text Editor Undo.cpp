#include <iostream>
#include <string>
using namespace std;

struct Node {
    string data;
    Node* next;
};

Node* top = NULL;

// Push function
void push(string word) {
    Node* newNode = new Node;

    newNode->data = word;
    newNode->next = top;

    top = newNode;

    cout << "Word added: " << word << endl;
}

// Pop function
void pop() {
    if (top == NULL) {
        cout << "Nothing to undo" << endl;
    }
    else {
        Node* temp = top;

        cout << "Undone: " << temp->data << endl;

        top = top->next;

        delete temp;
    }
}

// Peek function
void peek() {
    if (top == NULL) {
        cout << "Editor is empty" << endl;
    }
    else {
        cout << "Last word: " << top->data << endl;
    }
}

// Size function
int size() {
    int count = 0;

    Node* current = top;

    while (current != NULL) {
        count++;

        current = current->next;
    }

    return count;
}

// Display function
void display() {
    if (top == NULL) {
        cout << "Editor is empty" << endl;
        return;
    }

    Node* current = top;

    cout << "Words in editor (last typed first):" << endl;

    while (current != NULL) {
        cout << current->data << " ";

        current = current->next;
    }

    cout << endl;
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
    string word;

    do {
        cout << "\n1. Type Word";
        cout << "\n2. Undo";
        cout << "\n3. Last Word";
        cout << "\n4. Word Count";
        cout << "\n5. Display Words";
        cout << "\n0. Exit";

        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter word: ";
                cin >> word;
                push(word);
                break;

            case 2:
                pop();
                break;

            case 3:
                peek();
                break;

            case 4:
                cout << "Word Count: " << size() << endl;
                break;

            case 5:
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
