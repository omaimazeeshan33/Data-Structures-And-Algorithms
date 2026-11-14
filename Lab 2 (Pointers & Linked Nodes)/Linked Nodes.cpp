#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node(int value) {
        data = value;
        next = NULL;
    }
};

int main() {
    Node n1(10), n2(20), n3(30);
    n1.next = &n2;
    n2.next = &n3;
    Node *ptr = &n1;
    cout << "Linked list values: ";
    while (ptr != NULL) {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
    return 0;
}
