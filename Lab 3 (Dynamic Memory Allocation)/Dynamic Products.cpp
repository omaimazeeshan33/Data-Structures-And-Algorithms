#include <iostream>
using namespace std;

struct Product {
    string name;
    int code;
    float price;
};

int main() {
    int n;
    cout << "Enter number of products: ";
    cin >> n;

    // Dynamically allocate an array of Product objects
    Product* products = new Product[n];

    // Take input for each product
    for (int i = 0; i < n; i++) {
        cout << "\nEnter details for product " << i + 1 << ":\n";
        cout << "Name: ";
        cin >> products[i].name;
        cout << "Code: ";
        cin >> products[i].code;
        cout << "Price: ";
        cin >> products[i].price;
    }

    // Print all products
    cout << "\n--- Product List ---\n";
    for (int i = 0; i < n; i++) {
        cout << "Name: " << products[i].name
             << ", Code: " << products[i].code
             << ", Price: " << products[i].price << endl;
    }

    // Free the dynamically allocated memory
    delete[] products;
    return 0;
}
