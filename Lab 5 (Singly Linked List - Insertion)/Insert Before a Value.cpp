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

    int beforeValue;
    int newValue;

    cout << "\n\nEnter value BEFORE which you want to insert: ";
    cin >> beforeValue;

    cout << "Enter new value: ";
    cin >> newValue;

    Node* newNode = new Node;
    newNode->data = newValue;

    // Special case:
    // Insert before the first node
    if(head != NULL && head->data == beforeValue)
    {
        newNode->next = head;
        head = newNode;
    }
    else
    {
        Node* previous = NULL;
        temp = head;

        // Search for the target value
        while(temp != NULL && temp->data != beforeValue)
        {
            previous = temp;
            temp = temp->next;
        }

        // Value not found
        if(temp == NULL)
        {
            cout << "\nValue not found in the list.";

            delete newNode;
        }
        else
        {
            // Insert before temp
            newNode->next = temp;
            previous->next = newNode;
        }
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
