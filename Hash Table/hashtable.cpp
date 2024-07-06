#include <iostream>
#include <vector>
using namespace std;

class HashTable {
private:
    vector<int> table;
    vector<bool> occupied;
    int capacity;
    int size;
    float loadFactorThreshold;

    int hashFunction(int key);
    int findNextIndex(int index);

public:
    HashTable(int initialCapacity, float loadFactorThreshold = 0.7);
    void insert(int key);
    bool search(int key);
    void remove(int key);
    void display();
    void rehash();
};

HashTable::HashTable(int initialCapacity, float loadFactorThreshold) {
    capacity = initialCapacity;
    this->loadFactorThreshold = loadFactorThreshold;
    size = 0;
    table.resize(capacity, -1);
    occupied.resize(capacity, false);
}

int HashTable::hashFunction(int key) {
    return key % capacity;
}

int HashTable::findNextIndex(int index) {
    return (index + 1) % capacity;
}

void HashTable::insert(int key) {
    if ((float)size / capacity >= loadFactorThreshold) {
        rehash();
    }

    int index = hashFunction(key);
    while (occupied[index] && table[index] != key) {
        index = findNextIndex(index);
    }

    if (!occupied[index]) {
        size++;
    }
    table[index] = key;
    occupied[index] = true;
}

bool HashTable::search(int key) {
    int index = hashFunction(key);
    while (occupied[index]) {
        if (table[index] == key) {
            return true;
        }
        index = findNextIndex(index);
    }
    return false;
}

void HashTable::remove(int key) {
    int index = hashFunction(key);
    while (occupied[index]) {
        if (table[index] == key) {
            occupied[index] = false;
            size--;
            return;
        }
        index = findNextIndex(index);
    }
}

void HashTable::rehash() {
    vector<int> oldTable = table;
    vector<bool> oldOccupied = occupied;

    capacity *= 2;
    table.resize(capacity, -1);
    occupied.resize(capacity, false);
    size = 0;

    for (int i = 0; i < oldTable.size(); ++i) {
        if (oldOccupied[i]) {
            insert(oldTable[i]);
        }
    }
}

void HashTable::display() {
    for (int i = 0; i < capacity; ++i) {
        if (occupied[i]) {
            cout << "Index " << i << ": " << table[i] << endl;
        }
    }
}

int main() {
    HashTable ht(5);

    ht.insert(1);
    ht.insert(2);
    ht.insert(3);
    ht.insert(4);
    ht.insert(5);
    ht.insert(6); // Trigger rehashing

    cout << "Hash Table Contents:" << endl;
    ht.display();

    cout << "\nSearching for key 3: " << (ht.search(3) ? "Found" : "Not Found") << endl;
    cout << "Searching for key 7: " << (ht.search(7) ? "Found" : "Not Found") << endl;

    ht.remove(3);
    cout << "\nHash Table Contents after removing key 3:" << endl;
    ht.display();

    return 0;
}
