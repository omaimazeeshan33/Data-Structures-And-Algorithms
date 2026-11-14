#include <iostream>
using namespace std;

int main()
{
    float balance, deposit, withdrawal;
    float *ptr;

    cout << "Enter Initial Balance:";
    cin >> balance;
    ptr = &balance;

    cout << "Enter Deposit Amount:";
    cin >> deposit;
    *ptr = *ptr + deposit;
    cout << "Balance after Deposit: " << *ptr << endl;

    cout << "Enter Withdrawal Amount: ";
    cin >> withdrawal;
    if (withdrawal <= *ptr)
    {
        *ptr = *ptr - withdrawal;
        cout << "Balance after Withdrawal: " << *ptr << endl;
    }
    else
    {
        cout << "Insufficient Balance!" << endl;
    }

    return 0;
}
