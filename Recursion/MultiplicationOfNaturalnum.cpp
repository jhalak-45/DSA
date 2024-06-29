#include <iostream>
using namespace std;

int multiplyOfNaturalNumbers(int n) {
    if (n == 1)
        return 1;
    else
        return n * multiplyOfNaturalNumbers(n - 1);
}

int main() {
    int n;
    cout << "Enter the value of N: ";
    cin >> n;
    int result = multiplyOfNaturalNumbers(n);

    cout << "Multiplication of first " << n << " natural numbers is: " << result << endl;

    return 0;
}
