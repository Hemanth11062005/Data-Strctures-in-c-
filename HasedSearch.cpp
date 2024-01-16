#include <iostream>
using namespace std;
// Node structure for singly linked list
struct Node {
    int data;
    Node* link;
};

// Function to create a new node
Node* createNode(int key) {
    Node* newNode = new Node;
    newNode->data = key;
    newNode->link = nullptr;
    return newNode;
}

// Function to insert a key into the hash table
void insertToHash(Node* hashTable[], int size, int key) {
    int hashIndex = key % size;
    Node* newNode = createNode(key);
    newNode->link = hashTable[hashIndex];
    hashTable[hashIndex] = newNode;
}

// Function to delete a key from the hash table
void deleteFromHash(Node* hashTable[], int size, int dltKey) {
    int hashIndex = dltKey % size;
    Node* delNode = hashTable[hashIndex];
    Node* temp = nullptr;

    while (delNode != nullptr) {
        if (delNode->data == dltKey) {
            if (temp == nullptr) {
                hashTable[hashIndex] = delNode->link;
            } else {
                temp->link = delNode->link;
            }
            delete delNode;
            return;
        }
        temp = delNode;
        delNode = delNode->link;
    }

    cout << "Given key is not present in hash table" << endl;
}

// Function to search for a key in the hash table
void searchInHash(Node* hashTable[], int size, int key) {
    int hashIndex = key % size;
    Node* searchNode = hashTable[hashIndex];

    while (searchNode != nullptr) {
        if (searchNode->data == key) {
            std::cout << "Key found: " << searchNode->data << std::endl;
            return;
        }
        searchNode = searchNode->link;
    }

    cout << "Search element unavailable in hash table" <<endl;
}

// Function to display the elements in the hash table
void display(Node* hashTable[], int size) {
    for (int i = 0; i < size; ++i) {
        Node* temp = hashTable[i];
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->link;
        }
    }
    cout << endl;
}

int main() {
    const int size = 10; // Set the size of the hash table
    Node* hashTable[size] = {nullptr}; // Initialize the hash table

    // Test the functions
    insertToHash(hashTable, size, 5);
    insertToHash(hashTable, size, 15);
    insertToHash(hashTable, size, 25);

    display(hashTable, size);

    searchInHash(hashTable, size, 15);

    deleteFromHash(hashTable, size, 15);

    display(hashTable, size);

    return 0;
}
