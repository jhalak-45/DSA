#include <iostream>
using namespace std;

// Function to find the greatest common divisor (GCD) of two positive integers recursively
int gcd(int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int main() {
    int num1, num2;
    cout << "Enter two positive integers: ";
    cin >> num1 >> num2;

    if (num1 <= 0 || num2 <= 0) {
        cout << "Both numbers must be positive." << endl;
    } else {
        int result = gcd(num1, num2);
        cout << "Greatest Common Divisor (GCD) of " << num1 << " and " << num2 << " is: " << result << endl;
    }

    return 0;
}
