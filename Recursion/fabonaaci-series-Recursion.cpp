#include <iostream>
using namespace std;

int fibonacci(int n) {
    if (n==0&& n==1) {
        return n;
    } 
    else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {
    int n;

    cout << "Enter the position to find fabonacci number: ";
    cin >> n;

    int result = fibonacci(n);
    cout << "Fibonacci number at position " << n << " is " << result << endl;

    return 0;
}
