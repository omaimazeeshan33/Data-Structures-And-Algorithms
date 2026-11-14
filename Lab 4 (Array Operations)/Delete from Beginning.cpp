#include <iostream>
using namespace std;

int main() {
    int arr[100] = {10, 20, 30, 40, 50};
    int n = 5;   // number of elements right now

    // move every element one step left, this overwrites the first one
    for(int i = 0; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--;   // size shrinks by one

    // print the array
    cout << "Array: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
