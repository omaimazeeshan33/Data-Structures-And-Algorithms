#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

// Delete last node
void deleteAtEnd(Node*& head)
{
    Node* temp = head;

    // Move to the second-last node
    while (temp->next->next != nullptr)
    {
        temp = temp->next;
    }

    // Delete last node
    delete temp->next;
    temp->next = nullptr;
}

// Delete node at position 2
void deleteAtPosition2(Node*& head)
{
    Node* temp = head;

    // Move to position 2
    temp = temp->next;

    Node* deleteNode = temp;

    // Connect position 1 to position 3
    head->next = deleteNode->next;

    delete deleteNode;
}

// Display the list
void display(Node* head)
{
    Node* temp = head;

    while (temp != nullptr)
    {
        cout << temp->data;

        if (temp->next != nullptr)
            cout << " -> ";

        temp = temp->next;
    }

    cout << endl;
}

int main()
{
    // Create nodes
    Node* n1 = new Node;
    Node* n2 = new Node;
    Node* n3 = new Node;
    Node* n4 = new Node;
    Node* n5 = new Node;

    // Store data
    n1->data = 10;
    n2->data = 20;
    n3->data = 30;
    n4->data = 40;
    n5->data = 50;

    // Connect nodes
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = nullptr;

    Node* head = n1;

    cout << "Original list: ";
    display(head);

    // Delete last node
    deleteAtEnd(head);

    cout << "After deleting last node: ";
    display(head);

    // Delete node at position 2
    deleteAtPosition2(head);

    cout << "After deleting position 2: ";
    display(head);

    return 0;
}
