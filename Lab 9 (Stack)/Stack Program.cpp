#include <iostream>
using namespace std;

const int MAX = 5;
int stk[MAX];
int top = -1;

// Check if stack is empty
bool isEmpty() {
    return top == -1;
}

// Check if stack is full
bool isFull() {
    return top == MAX - 1;
}

// Push an element into the stack
void push(int x) {
    if (isFull()) {
        cout << "Stack overflow" << endl;
    } else {
        top++;
        stk[top] = x;
        cout << x << " pushed into stack." << endl;
    }
}

// Pop an element from the stack
void pop() {
    if (isEmpty()) {
        cout << "Stack underflow" << endl;
    } else {
        cout << "Popped: " << stk[top] << endl;
        top--;
    }
}

// Search for an element from the top
int search(int x) {
    int steps = 1;

    for (int i = top; i >= 0; i--) {
        if (stk[i] == x) {
            return steps;
        }
        steps++;
    }

    return -1;
}

int main() {
    int value;

    cout << "Enter 5 integers:" << endl;

    for (int i = 0; i < MAX; i++) {
        cin >> value;
        push(value);
    }

    // Try to push a sixth element
    cout << "\nTrying to push a sixth element:" << endl;
    push(100);

    // Search for a present value
    cout << "\nEnter a value to search (present value): ";
    cin >> value;

    int result = search(value);

    if (result != -1) {
        cout << "Value found " << result
             << " step(s) from the top." << endl;
    } else {
        cout << "Value not found." << endl;
    }

    // Search for an absent value
    cout << "\nSearching for an absent value (999):" << endl;

    result = search(999);

    if (result != -1) {
        cout << "Value found " << result
             << " step(s) from the top." << endl;
    } else {
        cout << "Value not found." << endl;
    }

    // Pop all elements
    cout << "\nPopping all elements:" << endl;

    while (!isEmpty()) {
        pop();
    }

    // Try to pop one more time
    cout << "\nTrying to pop from an empty stack:" << endl;
    pop();

    return 0;
}
