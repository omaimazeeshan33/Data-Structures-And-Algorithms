#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

// Delete first node
void deleteAtStart(Node*& head)
{
    Node* temp = head;
    head = head->next;
    delete temp;
}

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

    // Delete at start - first time
    deleteAtStart(head);

    cout << "After first deletion: ";
    display(head);

    // Delete at start - second time
    deleteAtStart(head);

    cout << "After second deletion: ";
    display(head);
    return 0;
}
