#include <iostream>
using namespace std;

struct Employee
{
    int id;
    string name;
    float basicSalary;
    float allowance;
};

int main()
{
    Employee emp;
    float grossSalary, tax, finalSalary;

    cout << "Enter Employee ID: ";
    cin >> emp.id;

    cout << "Enter Employee Name: ";
    cin >> emp.name;

    cout << "Enter Basic Salary: ";
    cin >> emp.basicSalary;

    cout << "Enter Allowance: ";
    cin >> emp.allowance;

    grossSalary = emp.basicSalary + emp.allowance;

    if (grossSalary > 100000)
        tax = grossSalary * 0.05;
    else
        tax = grossSalary * 0.02;

    finalSalary = grossSalary - tax;

    cout << "\n------ Employee Salary Details ------\n";
    cout << "Employee ID: " << emp.id << endl;
    cout << "Employee Name: " << emp.name << endl;
    cout << "Basic Salary: " << emp.basicSalary << endl;
    cout << "Allowance: " << emp.allowance << endl;
    cout << "Gross Salary: " << grossSalary << endl;
    cout << "Tax: " << tax << endl;
    cout << "Final Salary: " << finalSalary << endl;

    return 0;
}
