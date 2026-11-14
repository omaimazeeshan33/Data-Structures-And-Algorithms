#include <iostream>
using namespace std;

int main() {
    int arr[100] = {10, 20, 30, 40};
    int n = 4;          // number of elements right now
    int value = 25;     // the number we want to insert
    int position = 2;   // the index where it should go

    // shift elements from the end back to the position, one step right
    for(int i = n; i > position; i--)
        arr[i] = arr[i - 1];

    arr[position] = value;  // now the gap is free, put the value in
    n++;                    // size grows by one

    // print the array
    cout << "Array: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
