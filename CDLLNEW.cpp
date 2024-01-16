#include<iostream>
using namespace std;

struct node {
    int data;
    node* left;
    node* right;
};

class CDLL {
private:
    node* head;

public:
    CDLL() : head(nullptr) {}

    void insert() {
        cout << "Enter data to be inserted:" << endl;
        int value;
        cin >> value;

        node* newItem = new node{value, nullptr, nullptr};

        if (head == nullptr) {
            head = newItem;
            head->left = head;
            head->right = head;
        } else {
            node* current = head;

            // Find the position to insert the new node
            while (current->right != head && value > current->data) {
                current = current->right;
            }

            // Insert the new node
            newItem->left = current->left;
            newItem->right = current;
            current->left->right = newItem;
            current->left = newItem;

            // Update head if needed
            if (value <= head->data) {
                head = newItem;
            }
        }
    }

    void displayFromFront() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        node* current = head;

        do {
            cout << current->data << " ";
            current = current->right;
        } while (current != head);

        cout << endl;
    }

    void displayFromRear() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        node* current = head->left; // Start from the last node

        do {
            cout << current->data << " ";
            current = current->left;
        } while (current != head->left);

        cout << endl;
    }

    void deleteKey() {
        if (head == nullptr) {
            cout << "List is empty. Cannot delete." << endl;
            return;
        }

        int key;
        cout << "Enter the key to delete:" << endl;
        cin >> key;

        node* current = head;

        do {
            if (current->data == key) {
                // Node with the key found, delete it
                if (current->right == current) {
                    // If there is only one node in the list
                    delete current;
                    head = nullptr;
                } else {
                    current->left->right = current->right;
                    current->right->left = current->left;

                    if (current == head) {
                        head = current->right;
                    }

                    delete current;
                }

                cout << "Node with key " << key << " deleted." << endl;
                return;
            }

            current = current->right;
        } while (current != head);

        cout << "Node with key " << key << " not found." << endl;
    }
};

int main() {
    CDLL circularList;

    int x;
    do {
        cout << "Enter 1. Insert 2. Display (Front) 3. Display (Rear) 4. Delete 0. Exit: ";
        cin >> x;
        switch (x) {
            case 1:
                circularList.insert();
                break;
            case 2:
                circularList.displayFromFront();
                break;
            case 3:
                circularList.displayFromRear();
                break;
            case 4:
                circularList.deleteKey();
                break;
        }
    } while (x != 0);

    return 0;
}
