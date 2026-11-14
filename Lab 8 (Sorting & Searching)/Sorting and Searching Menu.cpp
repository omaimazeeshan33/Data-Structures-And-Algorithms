#include <iostream>
using namespace std;

int main()
{
    int arr[10];
    int choice;
    bool isSorted = false;   // Binary Search needs a sorted array

    // Taking input from the user
    cout << "Enter 10 integers:" << endl;

    for (int i = 0; i < 10; i++)
    {
        cin >> arr[i];
    }

    do
    {
        cout << "\n===== SEARCHING AND SORTING MENU =====" << endl;
        cout << "1. Selection Sort" << endl;
        cout << "2. Bubble Sort" << endl;
        cout << "3. Insertion Sort" << endl;
        cout << "4. Binary Search" << endl;
        cout << "5. Display Array" << endl;
        cout << "6. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        // Selection Sort
        if (choice == 1)
        {
            for (int i = 0; i < 9; i++)
            {
                int minIndex = i;

                for (int j = i + 1; j < 10; j++)
                {
                    if (arr[j] < arr[minIndex])
                    {
                        minIndex = j;
                    }
                }

                int temp = arr[i];
                arr[i] = arr[minIndex];
                arr[minIndex] = temp;
            }

            isSorted = true;
            cout << "Array sorted using Selection Sort:" << endl;

            for (int i = 0; i < 10; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }

        // Bubble Sort
        else if (choice == 2)
        {
            for (int i = 0; i < 9; i++)
            {
                for (int j = 0; j < 9 - i; j++)
                {
                    if (arr[j] > arr[j + 1])
                    {
                        int temp = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = temp;
                    }
                }
            }

            isSorted = true;
            cout << "Array sorted using Bubble Sort:" << endl;

            for (int i = 0; i < 10; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }

        // Insertion Sort
        else if (choice == 3)
        {
            for (int i = 1; i < 10; i++)
            {
                int key = arr[i];
                int j = i - 1;

                while (j >= 0 && arr[j] > key)
                {
                    arr[j + 1] = arr[j];
                    j--;
                }

                arr[j + 1] = key;
            }

            isSorted = true;
            cout << "Array sorted using Insertion Sort:" << endl;

            for (int i = 0; i < 10; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }

        // Binary Search
        else if (choice == 4)
        {
            if (isSorted == false)
            {
                cout << "Please sort the array first (option 1, 2 or 3)." << endl;
            }
            else
            {
                int key;
                int high = 9;
                int low = 0;
                int mid;
                int found = -1;

                cout << "Enter the value to search: ";
                cin >> key;

                while (low <= high)
                {
                    mid = (low + high) / 2;

                    if (arr[mid] == key)
                    {
                        found = mid;
                        break;
                    }
                    else if (key > arr[mid])
                    {
                        low = mid + 1;
                    }
                    else
                    {
                        high = mid - 1;
                    }
                }

                if (found != -1)
                {
                    cout << "Element found at index " << found << endl;
                }
                else
                {
                    cout << "Element not found!" << endl;
                }
            }
        }

        // Display Array
        else if (choice == 5)
        {
            cout << "Array elements: ";

            for (int i = 0; i < 10; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }

        // Exit
        else if (choice == 6)
        {
            cout << "Program ended." << endl;
        }

        else
        {
            cout << "Invalid choice! Try again." << endl;
        }

    } while (choice != 6);

    return 0;
}
