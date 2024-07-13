#include <iostream>
#include <list>
#include <vector>

using namespace std;

class HashTable {
    int BUCKET;    // Number of buckets
    vector<list<int>> table; // Vector of lists to store keys

public:
    HashTable(int V); // Constructor

    // Insert a key into the hash table
    void insertItem(int x);

    // Delete a key from the hash table
    void deleteItem(int key);

    // Hash function to map values to key
    int hashFunction(int x) {
        return (x % BUCKET);
    }

    // Display the hash table
    void displayHash();
};

HashTable::HashTable(int b) {
    BUCKET = b;
    table.resize(BUCKET);
}

void HashTable::insertItem(int key) {
    int index = hashFunction(key);
    table[index].push_back(key);
}

void HashTable::deleteItem(int key) {
    int index = hashFunction(key);

    // Find the key in the list
    list<int>::iterator i;
    for (i = table[index].begin(); i != table[index].end(); i++) {
        if (*i == key)
            break;
    }

    // If key is found, remove it
    if (i != table[index].end())
        table[index].erase(i);
}

void HashTable::displayHash() {
    for (int i = 0; i < BUCKET; i++) {
        cout << i;
        for (auto x : table[i])
            cout << " --> " << x;
        cout << endl;
    }
}

int main() {
    // Create a hash table with 7 buckets
    int keys[] = {15, 11, 27, 8, 12};
    int n = sizeof(keys) / sizeof(keys[0]);

    HashTable h(7);

    // Insert keys into the hash table
    for (int i = 0; i < n; i++)
        h.insertItem(keys[i]);

    // Display the hash table
    h.displayHash();

    // Delete a key from the hash table
    h.deleteItem(12);

    // Display the hash table after deletion
    cout << "After deleting 12:\n";
    h.displayHash();

    return 0;
}
