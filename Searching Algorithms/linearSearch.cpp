#include <iostream>
using namespace std;

// Define the structure for a linear array
struct LinearArray {
    int* data;    // Pointer to the array of integers
    int size;     // Number of elements in the array

    // Constructor to initialize the array with a given size
    LinearArray(int n) : size(n) {
        data = new int[size];
    }

    // Destructor to free the allocated memory
    ~LinearArray() {
        delete[] data;
    }

    // Method to populate the array with user inputs
    void populateArray() {
        cout << "Enter " << size << " elements:" << endl;
        for (int i = 0; i < size; ++i) {
            cin >> data[i];
        }
    }

    // Method for linear search
    int linearSearch(int target) {
        for (int i = 0; i < size; ++i) {
            if (data[i] == target) {
                return i;  // Target found at index i
            }
        }
        return -1;  // Target not found
    }

    // Method to display the elements of the array
    void display() {
        cout << "Array elements: ";
        for (int i = 0; i < size; ++i) {
            cout << data[i] << " ";
        }
        cout << endl;
    }

    // Method to find the minimum element
    int findMin() {
        int min = data[0];
        for (int i = 1; i < size; ++i) {
            if (data[i] < min) {
                min = data[i];
            }
        }
        return min;
    }

    // Method to find the maximum element
    int findMax() {
        int max = data[0];
        for (int i = 1; i < size; ++i) {
            if (data[i] > max) {
                max = data[i];
            }
        }
        return max;
    }

    // Method to find the index of the first occurrence of a value
    int findFirstOccurrence(int target) {
        for (int i = 0; i < size; ++i) {
            if (data[i] == target) {
                return i;  // Target found at index i
            }
        }
        return -1;  // Target not found
    }

    // Method to find the index of the last occurrence of a value
    int findLastOccurrence(int target) {
        int lastIndex = -1;
        for (int i = 0; i < size; ++i) {
            if (data[i] == target) {
                lastIndex = i;  // Update lastIndex
            }
        }
        return lastIndex;  // Return last occurrence index, or -1 if not found
    }
};

// Menu for Linear Search Operations
void menu() {
    cout << "Linear Search Operations Menu" << endl;
    cout << "1. Linear Search" << endl;
    cout << "2. Display Array" << endl;
    cout << "3. Find Minimum Element" << endl;
    cout << "4. Find Maximum Element" << endl;
    cout << "5. Find First Occurrence of a Value" << endl;
    cout << "6. Find Last Occurrence of a Value" << endl;
    cout << "7. Exit" << endl;
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    LinearArray array(n);
    array.populateArray();  // Populate the array with user input

    int choice, target;

    do {
        menu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value to search: ";
                cin >> target;
                {
                    int index = array.linearSearch(target);
                    if (index != -1) {
                        cout << "Element found at index: " << index << endl;
                    } else {
                        cout << "Element not found" << endl;
                    }
                }
                break;

            case 2:
                array.display();
                break;

            case 3:
                cout << "Minimum element in the array: " << array.findMin() << endl;
                break;

            case 4:
                cout << "Maximum element in the array: " << array.findMax() << endl;
                break;

            case 5:
                cout << "Enter the value to find the first occurrence: ";
                cin >> target;
                {
                    int index = array.findFirstOccurrence(target);
                    if (index != -1) {
                        cout << "First occurrence of " << target << " is at index: " << index << endl;
                    } else {
                        cout << "Value not found in the array" << endl;
                    }
                }
                break;

            case 6:
                cout << "Enter the value to find the last occurrence: ";
                cin >> target;
                {
                    int index = array.findLastOccurrence(target);
                    if (index != -1) {
                        cout << "Last occurrence of " << target << " is at index: " << index << endl;
                    } else {
                        cout << "Value not found in the array" << endl;
                    }
                }
                break;

            case 7:
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "Invalid choice! Please choose again." << endl;
        }

        cout << endl;
    } while (choice != 7);

    return 0;
}
