#include <iostream>
using namespace std;

int main() {
    int arr[] = {10, 20, 30, 40, 50};   // must be sorted for binary search
    int n = 5;
    int value = 40;         // the number we are looking for
    int low = 0;            // start of the search area
    int high = n - 1;       // end of the search area
    int position = -1;      // -1 means not found yet

    while(low <= high)
    {
        int mid = (low + high) / 2;     // find the middle index

        if(arr[mid] == value)
        {
            position = mid;             // found it
            break;
        }
        else if(value < arr[mid])
        {
            high = mid - 1;             // value is smaller, search the left half
        }
        else
        {
            low = mid + 1;              // value is bigger, search the right half
        }
    }

    // show the result
    if(position != -1)
        cout << "Value found at index " << position;
    else
        cout << "Value not found";
    return 0;
}
