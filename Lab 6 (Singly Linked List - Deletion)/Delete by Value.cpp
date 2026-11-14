#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

// Delete node by value
void deleteByValue(Node*& head, int value)
{
    // If value is in the first node
    if (head->data == value)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* temp = head;

    // Search for the value
    while (temp->next != nullptr)
    {
        if (temp->next->data == value)
        {
            Node* deleteNode = temp->next;

            temp->next = deleteNode->next;

            delete deleteNode;

            return;
        }

        temp = temp->next;
    }

    // If value is not found
    cout << "Value not found" << endl;
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

    // Delete first node by value
    deleteByValue(head, 10);
    cout << "After deleting 10: ";
    display(head);

    // Delete middle node by value
    deleteByValue(head, 30);
    cout << "After deleting 30: ";
    display(head);

    // Delete last node by value
    deleteByValue(head, 50);
    cout << "After deleting 50: ";
    display(head);

    // Try to delete a value that does not exist
    cout << "Trying to delete 100: ";
    deleteByValue(head, 100);

    return 0;
}
