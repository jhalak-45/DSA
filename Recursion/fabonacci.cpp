#include <iostream>
using namespace std;

void fibonacci(int n, int a = 0, int b = 1) {
    if (n > 0) {
        cout << a << " ";
        fibonacci(n - 1, b, a + b);
    }
}

int main() {
    int n;

    cout << "Enter the number of terms: ";
    cin >> n;

    cout << "Fibonacci Series: ";
    fibonacci(n);

    return 0;
}
