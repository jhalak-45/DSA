#include <iostream>
using namespace std;
int main() {

    int size;

    // Accept the size of the array
    cout << "Enter the number of people: ";
    cin >> size;

    int people[size], boys[size], girls[size];
    int bCount = 0, gCount = 0;

    // Accept the elements of the array
    cout << "Enter The Boys (even) and Girls (odd): "<<endl;
    for (int i = 0; i < size; ++i) {
        cin >> people[i];
    }

    // Separate boys and girls into different arrays
    for (int i = 0; i < size; ++i) {
        if (people[i] % 2 == 0) {
            boys[bCount++] = people[i];
        } else {
            girls[gCount++] = people[i];
        }
    }

    // Print couples
    cout << "Couples:" <<endl;
    int coupleCount = (bCount < gCount) ? bCount : gCount;
    for (int i = 0; i < coupleCount; ++i) {
        cout << "Couple {" << i + 1 << "} : Boy [" << boys[i] << "] and Girl [" << girls[i]<<"]" <<endl;
    }

    return 0;
}
