
/* using normal function */
#include <iostream>
using namespace std;

void fibonacci(int n) {
    int a = 0, b = 1, nextTerm;

    if (n <= 0) {
        cout << "Number of terms must be positive." << endl;
        return;
    }

    cout << "Fibonacci Series:" << endl;

    for (int i = 1; i <= n; ++i) {
        cout << a<<" ";  // Use endl for new line after each number
        nextTerm = a + b;
        a = b;
        b = nextTerm;
    }
}

int main() {
    int n;

    cout << "Enter the number of terms: ";
    cin >> n;

    fibonacci(n);

    return 0;
}
