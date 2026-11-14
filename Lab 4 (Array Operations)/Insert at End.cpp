#include <iostream>
using namespace std;

int main() {
    int arr[100] = {10, 20, 30, 40, 50};
    int n = 5;          // number of elements right now
    int value = 60;     // the number we want to insert

    arr[n] = value;     // first empty spot is at index n, so put it there
    n++;                // size grows by one

    // print the array
    cout << "Array: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
