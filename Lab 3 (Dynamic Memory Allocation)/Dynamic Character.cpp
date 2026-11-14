#include <iostream>
using namespace std;

int main() {
    // Dynamically allocate memory for a single character
    char* ch = new char;

    cout << "Enter a character: ";
    cin >> *ch;

    cout << "Stored character: " << *ch << endl;

    // Deallocate memory
    delete ch;
    ch = NULL; //set pointer to null pointer

    return 0;
}
