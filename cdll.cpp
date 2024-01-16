#include <iostream>

// Define a struct for the linked list node
struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class CircularLinkedList {
private:
    Node* head;

public:
    CircularLinkedList() : head(nullptr) {}

    // Function to insert a node in sorted order
    void sortedInsert(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            newNode->next = newNode;
            head = newNode;
        } else if (value < head->data) {
            newNode->next = head;
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            head = newNode;
        } else {
            Node* prev = nullptr;
            Node* current = head;
            while (current->next != head && current->data < value) {
                prev = current;
                current = current->next;
            }
            if (current->data < value) {
                prev = current;
            }
            newNode->next = prev->next;
            prev->next = newNode;
        }
    }

    // Function to display the circular linked list
    void display() {
        if (!head) {
            std::cout << "List is empty." << std::endl;
            return;
        }
        Node* temp = head;
        do {
            std::cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        std::cout << std::endl;
    }

    // Function to search for a value in the list
    bool search(int value) {
        if (!head) {
            return false;
        }
        Node* temp = head;
        do {
            if (temp->data == value) {
                return true;
            }
            temp = temp->next;
        } while (temp != head);
        return false;
    }

    // Function to delete a node with a given value
    void deleteNode(int value) {
        if (!head) {
            std::cout << "List is empty." << std::endl;
            return;
        }
        Node* current = head;
        Node* prev = nullptr;

        // Find the node to delete and its previous node
        while (current->data != value) {
            if (current->next == head) {
                std::cout << "Value not found in the list." << std::endl;
                return;
            }
            prev = current;
            current = current->next;
        }

        // If the node to be deleted is the head node
        if (current == head) {
            if (current->next == head) {
                head = nullptr;
            } else {
                prev = head;
                while (prev->next != head) {
                    prev = prev->next;
                }
                head = head->next;
                prev->next = head;
            }
        }

        // Delete the node
        prev->next = current->next;
        delete current;
        std::cout << "Node with value " << value << " deleted." << std::endl;
    }
};

int main() {
    CircularLinkedList myList;

    myList.sortedInsert(5);
    myList.sortedInsert(2);
    myList.sortedInsert(8);
    myList.sortedInsert(1);

    std::cout << "Circular Linked List: ";
    myList.display();

    if (myList.search(2)) {
        std::cout << "Value 2 is in the list." << std::endl;
    } else {
        std::cout << "Value 2 is not in the list." << std::endl;
    }

    myList.deleteNode(5);

    std::cout << "Updated Circular Linked List: ";
    myList.display();

    return 0;
}
