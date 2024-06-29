#include <iostream>
#include <limits.h> // For INT_MAX
using namespace std;
int main() {
    int n;
    
   cout << "Enter the size of the array: ";
   cin >> n;
    
    // Check if the size is valid
    if (n <= 0) {
       cout << "Invalid size. The size of the array should be a positive integer." <<endl;
        return 1;
    }
    
    int arr[n];
    
    // Input array elements
   cout << "Enter " << n << " elements of the array:" <<endl;
    for (int i = 0; i < n; ++i) {
       cin >> arr[i];
    }
    
    // Find the smallest positive element in the array
    int smallest = INT_MAX;
    
    for(int i = 0; i < n; ++i) {
        if (arr[i] > 0 && arr[i] < smallest) {
            smallest = arr[i];
        }
    }
    

       cout << "The smallest positive number in the array is: " << smallest <<endl;
    
    return 0;
}
