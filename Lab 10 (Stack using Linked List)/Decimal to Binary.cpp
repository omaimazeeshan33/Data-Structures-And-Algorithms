#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* top = NULL;

// Push function
void push(int value) {
    Node* newNode = new Node;

    newNode->data = value;
    newNode->next = top;

    top = newNode;
}

// Pop function
int pop() {
    if (top == NULL) {
        return -1;
    }

    Node* temp = top;

    int value = temp->data;

    top = top->next;

    delete temp;

    return value;
}

// Binary conversion
void convertToBinary(int number) {
    if (number == 0) {
        cout << "Binary: 0" << endl;
        return;
    }

    while (number > 0) {

        int remainder = number % 2;

        push(remainder);

        number = number / 2;
    }

    cout << "Binary: ";

    while (top != NULL) {
        cout << pop();
    }

    cout << endl;
}

int main() {

    int number;

    cout << "Enter decimal number: ";
    cin >> number;

    if (number < 0) {
        cout << "Please enter a non-negative number." << endl;
    }
    else {
        convertToBinary(number);
    }

    return 0;
}
