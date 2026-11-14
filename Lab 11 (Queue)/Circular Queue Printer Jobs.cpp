#include <iostream>
using namespace std;

#define SIZE 4

int items[SIZE];
int front = 0;
int rear = -1;
int itemCount = 0;

bool isEmpty() { return itemCount == 0; }
bool isFull()  { return itemCount == SIZE; }

void enqueue(int value) {
    if (isFull()) {
        cout << "Queue is FULL! Cannot add " << value << endl;
        return;
    }
    rear = (rear + 1) % SIZE;
    items[rear] = value;
    itemCount++;
    cout << "enqueue(" << value << ")";
}

void dequeue() {
    if (isEmpty()) {
        cout << "Queue is EMPTY! Nothing to remove." << endl;
        return;
    }
    cout << "dequeue() removed " << items[front];
    front = (front + 1) % SIZE;
    itemCount--;
}

void state() {
    cout << "  -> front = " << front << ", rear = " << rear
         << ", count = " << itemCount << endl;
}

int main() {
    enqueue(101); state();  // 1
    enqueue(102); state();  // 2
    enqueue(103); state();  // 3
    enqueue(104); state();  // 4
    enqueue(105); state();  // 5 (full)
    dequeue();    state();  // 6
    dequeue();    state();  // 7
    enqueue(105); state();  // 8
    enqueue(106); state();  // 9
    return 0;
}
