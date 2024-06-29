#include <iostream>
#include <cmath>
using namespace std;

void towerOfHanoi(int n, char from_S, char D_rod, char aux_rod, int &count)
{
    if (n == 0) {
        return;
    }

    towerOfHanoi(n - 1, from_S, aux_rod, D_rod, count);
    count++;
    cout << "Step  [" << count << "] : Move disk " << n << " from rod " << from_S << " to rod " << D_rod << endl;

    towerOfHanoi(n - 1, aux_rod, D_rod, from_S, count);
}

int main()
{
    int N;
    int count = 0;
    
    cout << "Enter Number of Discs in Tower of Hanoi:" << endl;
    cin >> N;
    cout << "Total Steps: " << pow(2, N) - 1 << endl << endl;

    // S=source, A=auxiliary, and D=Destination are names of rods
    towerOfHanoi(N, 'S', 'D', 'A', count);
    return 0;
}