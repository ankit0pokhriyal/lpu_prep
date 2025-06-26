#include <iostream>
using namespace std;

class SinglyLinkedList {
    struct Node {
        int data;
        Node* next;
        Node(int val) : data(val), next(nullptr) {}
    };

    Node* start;

public:
    SinglyLinkedList() : start(nullptr) {}

    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        newNode->next = start;
        start = newNode;
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (!start) {
            start = newNode;
            return;
        }
        Node* ptr = start;
        while (ptr->next)
            ptr = ptr->next;
        ptr->next = newNode;
    }

    void display() {
        if (!start) {
            cout << "List is empty.\n";
            return;
        }
        Node* ptr = start;
        while (ptr) {
            cout << ptr->data << (ptr->next ? " -> " : "\n");
            ptr = ptr->next;
        }
    }

    void deleteByData(int data) {
        if (!start) return;

        if (start->data == data) {
            Node* ptr = start;
            start = start->next;
            delete ptr;
            return;
        }

        Node* prepreptr = nullptr;
        Node* preptr = start;
        Node* ptr = start->next;

        while (ptr && ptr->data != data) {
            prepreptr = preptr;
            preptr = ptr;
            ptr = ptr->next;
        }

        if (!ptr) return; 

        preptr->next = ptr->next;
        delete ptr;
    }

    void reverse() {
        Node* preptr = nullptr;
        Node* ptr = start;
        Node* prepreptr = nullptr;

        while (ptr) {
            prepreptr = ptr->next;
            ptr->next = preptr;
            preptr = ptr;
            ptr = prepreptr;
        }
        start = preptr;
    }

    void clear() {
        Node* ptr = start;
        while (ptr) {
            Node* prepreptr = ptr->next;
            delete ptr;
            ptr = prepreptr;
        }
        start = nullptr;
    }

    ~SinglyLinkedList() {
        clear();
    }
};
