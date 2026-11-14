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

    int afterValue;
    int newValue;

    cout << "\n\nEnter value after which you want to insert: ";
    cin >> afterValue;

    cout << "Enter new value: ";
    cin >> newValue;

    // Create new node
    Node* newNode = new Node;
    newNode->data = newValue;

    // Search for the value
    temp = head;

    while(temp != NULL && temp->data != afterValue)
    {
        temp = temp->next;
    }

    // If value was not found
    if(temp == NULL)
    {
        cout << "\nValue not found in the list.";

        delete newNode;
    }
    else
    {
        // Insert new node
        newNode->next = temp->next;
        temp->next = newNode;

        // Display updated list
        cout << "\nLinked List after insertion: ";

        temp = head;

        while(temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }

    return 0;
}
