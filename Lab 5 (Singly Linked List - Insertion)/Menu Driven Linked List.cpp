#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

// Display the linked list
void display(Node* head)
{
    Node* temp = head;

    if(head == NULL)
    {
        cout << "List is empty.";
        return;
    }

    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

// Insert at beginning
void insertAtStart(Node*& head, int value)
{
    Node* newNode = new Node;

    newNode->data = value;
    newNode->next = head;

    head = newNode;
}

// Insert at end
void insertAtEnd(Node*& head, int value)
{
    Node* newNode = new Node;

    newNode->data = value;
    newNode->next = NULL;

    // If list is empty
    if(head == NULL)
    {
        head = newNode;
        return;
    }

    Node* temp = head;

    // Move to last node
    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    // Attach new node
    temp->next = newNode;
}

// Insert after a given value
void insertInMiddle(Node*& head, int afterValue, int newValue)
{
    Node* temp = head;

    // Search for the value
    while(temp != NULL && temp->data != afterValue)
    {
        temp = temp->next;
    }

    // Value not found
    if(temp == NULL)
    {
        cout << "Value not found in the list.";
        return;
    }

    Node* newNode = new Node;

    newNode->data = newValue;

    // Insert new node
    newNode->next = temp->next;
    temp->next = newNode;
}

int main()
{
    Node* head = NULL;

    int choice;
    int value;
    int afterValue;

    do
    {
        cout << "\n\n===== LINKED LIST MENU =====";
        cout << "\n1. Insert at Start";
        cout << "\n2. Insert at End";
        cout << "\n3. Insert in Middle";
        cout << "\n4. Display List";
        cout << "\n5. Exit";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:

                cout << "Enter value: ";
                cin >> value;

                insertAtStart(head, value);

                break;

            case 2:

                cout << "Enter value: ";
                cin >> value;

                insertAtEnd(head, value);

                break;

            case 3:

                cout << "Enter value after which you want to insert: ";
                cin >> afterValue;

                cout << "Enter new value: ";
                cin >> value;

                insertInMiddle(head, afterValue, value);

                break;

            case 4:

                cout << "Linked List: ";
                display(head);

                break;

            case 5:

                cout << "Program ended.";

                break;

            default:

                cout << "Invalid choice.";
        }

    } while(choice != 5);

    return 0;
}
