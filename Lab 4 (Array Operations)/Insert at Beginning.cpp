#include <iostream>
using namespace std;

int main() {
    int arr[100] = {20, 30, 40, 50};
    int n = 4;          // number of elements right now
    int value = 15;     // the number we want to insert

    // move everything one step right to make space at index 0
    for(int i = n; i > 0; i--)
        arr[i] = arr[i - 1];

    arr[0] = value;     // put the new value at the start
    n++;                // array has one more element now

    // printing the array
    cout << "Array: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
