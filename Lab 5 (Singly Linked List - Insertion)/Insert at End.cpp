#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

int main()
{
    int n;

    cout << "Enter number of nodes: ";
    cin >> n;

    Node* head = NULL;
    Node* temp = NULL;

    // Create the Linked List
    for(int i = 0; i < n; i++)
    {
        Node* newNode = new Node;

        cout << "Enter value: ";
        cin >> newNode->data;

        newNode->next = NULL;

        if(head == NULL)
        {
            head = newNode;
        }
        else
        {
            temp = head;

            while(temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = newNode;
        }
    }

    // Display original list
    cout << "\nOriginal Linked List: ";

    temp = head;

    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    // Create new node
    Node* newNode = new Node;

    cout << "\n\nEnter value to insert at end: ";
    cin >> newNode->data;

    newNode->next = NULL;

    // Check if list is empty
    if(head == NULL)
    {
        head = newNode;
    }
    else
    {
        temp = head;

        // Move to last node
        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        // Attach new node at the end
        temp->next = newNode;
    }

    // Display updated list
    cout << "\nLinked List after insertion: ";

    temp = head;

    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}
