#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int d, Node* p, Node* n) : data(d), prev(p), next(n) {}
};

int main() {
    // Create list
    Node* n1 = new Node(101, NULL, NULL);
    Node* n2 = new Node(102, n1, NULL);
    Node* n3 = new Node(103, n2, NULL);
    Node* n4 = new Node(104, n3, NULL);
    Node* n5 = new Node(105, n4, NULL);

    // Link forward
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;

    // Insert start
    Node* n0 = new Node(100, NULL, n1);
    n1->prev = n0;

    // Insert middle
    Node* n6 = new Node(1035, n3, n4);
    n3->next = n6;
    n4->prev = n6;

    // Insert end
    Node* n7 = new Node(106, n5, NULL);
    n5->next = n7;

    // Delete first
    n0 = n0->next;
    n0->prev = NULL;

    // Delete 104
    n6->next = n5;
    n5->prev = n6;

    // Delete last
    n5->next = NULL;

    // Display
    cout << "Final List: ";
    cout << n1->data << " <-> ";
    cout << n2->data << " <-> ";
    cout << n3->data << " <-> ";
    cout << n6->data << " <-> ";
    cout << n5->data;

    return 0;
}
