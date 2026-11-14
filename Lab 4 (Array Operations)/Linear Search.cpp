#include <iostream>
using namespace std;

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int n = 5;              // total elements
    int value = 40;         // the number we are looking for
    int position = -1;      // -1 means not found yet

    // check each element one by one from the start
    for(int i = 0; i < n; i++)
    {
        if(arr[i] == value)
        {
            position = i;   // save the index where we found it
            break;          // no need to keep searching
        }
    }

    // show the result
    if(position != -1)
        cout << "Value found at index " << position;
    else
        cout << "Value not found";
    return 0;
}
