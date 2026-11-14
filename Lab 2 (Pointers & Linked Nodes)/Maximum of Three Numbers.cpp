#include <iostream>
using namespace std;

int main() {
    int a = 15, b = 42, c = 27;
    int *p1 = &a, *p2 = &b, *p3 = &c;

    int max = *p1;
    if (*p2 > max) max = *p2;
    if (*p3 > max) max = *p3;

    cout << "a = " << *p1 << ", b = " << *p2 << ", c = " << *p3 << endl;
    cout << "Maximum value: " << max << endl;
    return 0;
}
