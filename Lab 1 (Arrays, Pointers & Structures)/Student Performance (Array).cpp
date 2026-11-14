#include <iostream>
using namespace std;

int main()
{
    //declaring variables
    int marks[10];
    int sum = 0;
    int highest, lowest;
    int pass = 0, fail = 0;

    //taking input from user
    cout << "Enter marks of 10 students:\n";
    for (int i = 0; i < 10; i++)
    {
        cout << "Student " << i + 1 << ": ";
        cin >> marks[i];

        //calculating sum
        sum += marks[i];
        if (i == 0)
        {
            highest = marks[i];
            lowest = marks[i];
        }
        else
        {
            if (marks[i] > highest)
                highest = marks[i];

            if (marks[i] < lowest)
                lowest = marks[i];
        }
        if (marks[i] >= 50)
            pass++;
        else
            fail++;
    }

    //calculating average
    float average = (float)sum / 10;

    cout << "\nMarks of Students:\n";
    for (int i = 0; i < 10; i++)
    {
        cout << marks[i] << " ";
    }

    cout << "\n\nAverage Marks: " << average << endl;
    cout << "Highest Marks: " << highest << endl;
    cout << "Lowest Marks: " << lowest << endl;
    cout << "Passed Students: " << pass << endl;
    cout << "Failed Students: " << fail << endl;

    return 0;
}
