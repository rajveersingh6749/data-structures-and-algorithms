// Implement a hash table data structure in C++

#include <bits/stdc++.h>
using namespace std;

struct Hash {
    int BUCKET;

    // vector of vectors to store the chains
    vector<vector<int>> table;

    // constructor to initialize bucket count and table
    Hash(int b) {
        this->BUCKET = b;
        table.resize(BUCKET);
    }

    // hash function to return the index of the key
    int hashFunction(int x) {
        return (x % BUCKET);
    }

    // insert the key into the hash table
    void insertItem(int key) {
        int index = hashFunction(key);
        table[index].push_back(key);
    }

    void displayHash();
    void deleteItem(int key);
};

void Hash::displayHash() {
    for(int i = 0; i < BUCKET; i++) {
        cout<<i;
        for(auto x : table[i]) {
            cout<<"-->"<<x;
        }
        cout<<endl;
    }
}

void Hash::deleteItem(int key) {
    int index = hashFunction(key);
    auto it = find(table[index].begin(), table[index].end(), key);
    if(it != table[index].end()) {
        table[index].erase(it);
    }
    else {
        cout<<"Element not found"<<endl;
    }
}


int main() {

    // vector that contains keys to be mapped
    vector<int> a = {15, 11, 27, 8, 12};

    Hash h(7); // here 7 is the no. of buckets

    // insert the keys into the hash table
    for(int key : a) {
        h.insertItem(key);
    }

    h.displayHash();

    h.deleteItem(12);
    h.displayHash();

    return 0;
}