#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int d, Node* p, Node* n) : data(d), prev(p), next(n) {}
};

int main() {
    Node* head = nullptr;
    Node* tail = nullptr;

    int values[] = {10, 20, 30, 40, 50};

    // Build the starting list by adding each value at the end
    for (int value : values) {
        Node* newNode = new Node(value, tail, nullptr);

        if (head == nullptr)
            head = newNode;        // first node becomes head
        else
            tail->next = newNode;  // linking old tail forward to new node

        tail = newNode;
    }

    // Insert 5 at the start: new node points to old head, old head points back
    Node* newNode = new Node(5, nullptr, head);
    head->prev = newNode;
    head = newNode;

    // Find node 20, then insert 25 right after it
    Node* current = head;
    while (current != nullptr && current->data != 20)
        current = current->next;

    if (current != nullptr) {
        Node* node25 = new Node(25, current, current->next);
        current->next->prev = node25;  // 30 points back to 25
        current->next = node25;        // 20 points forward to 25
    }

    // Insert 60 at the end and move tail
    Node* node60 = new Node(60, tail, nullptr);
    tail->next = node60;
    tail = node60;

    // Display the list from head to tail
    current = head;
    while (current != nullptr) {
        cout << current->data;
        if (current->next != nullptr)
            cout << " <-> ";
        current = current->next;
    }

    cout << endl;
    return 0;
}
