#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* link;
};

class HashTable {
    const int size = 10;
    Node* hashtable[10];
    int key, hashindex;
public:
    HashTable() {
        for (int i = 0; i < size; i++) {
            hashtable[i] = NULL;
        }
    }

    void insert() {
        Node* newnode = new Node;
        cout << "Enter data to be inserted:" << endl;
        cin >> key;
        hashindex = key % size;
        newnode->link = hashtable[hashindex];
        newnode->data = key;
        hashtable[hashindex] = newnode;
    }

    void del() {
        cout << "Enter key to be deleted:" << endl;
        cin >> key;
        hashindex = key % size;
        Node* delNode = hashtable[hashindex];
        Node* temp = NULL;
        while (delNode != NULL) {
            if (delNode->data == key) {
                if (temp == NULL)
                    hashtable[hashindex] = delNode->link;
                else
                    temp->link = delNode->link;
                delete delNode; // Don't forget to free the memory
                break; // Exit the loop once the key is found and deleted
            }
            temp = delNode;
            delNode = delNode->link;
        }
    }

    void display() {
        Node* temp;
        for (int i = 0; i < size; i++) {
            temp = hashtable[i];
            while (temp != NULL) {
                cout << temp->data << " ";
                temp = temp->link;
            }
        }
        cout << endl;
    }
};

int main() {
    HashTable h;
    int x;
    do {
        cout << "\n1.insert 2.delete 3.display" << endl;
        cin >> x;
        switch (x) {
        case 1: h.insert(); break;
        case 2: h.del(); break;
        case 3: h.display(); break;
        }
    } while (x >= 1);

    return 0;
}
