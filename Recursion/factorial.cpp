#include <iostream>
using namespace std;

// Function to find the factorial of a positive number recursively
int factorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    else
        return n * factorial(n - 1);
}

int main() {
    int num;
    cout << "Enter a positive number: ";
    cin >> num;

    // Check if the number is positive
    if (num < 0) {
        cout << "Factorial is not defined for negative numbers." << endl;
    } else {
        int fact = factorial(num);
        cout << "Factorial of " << num << " is: " << fact << endl;
    }

    return 0;
}
