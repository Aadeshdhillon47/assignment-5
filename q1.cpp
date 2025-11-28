#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

void insertAtBeginning(int val) {
    Node* temp = new Node();
    temp->data = val;
    temp->next = head;
    head = temp;
}

void insertAtEnd(int val) {
    Node* temp = new Node();
    temp->data = val;
    temp->next = NULL;

    if (head == NULL) {
        head = temp;
        return;
    }

    Node* ptr = head;
    while (ptr->next != NULL) ptr = ptr->next;

    ptr->next = temp;
}

void insertBefore(int val, int before) {
    if (head == NULL) return;

    if (head->data == before) {
        insertAtBeginning(val);
        return;
    }

    Node* ptr = head;
    while (ptr->next != NULL && ptr->next->data != before)
        ptr = ptr->next;

    if (ptr->next == NULL) return;

    Node* temp = new Node();
    temp->data = val;
    temp->next = ptr->next;
    ptr->next = temp;
}

void insertAfter(int val, int after) {
    Node* ptr = head;
    while (ptr != NULL && ptr->data != after)
        ptr = ptr->next;

    if (ptr == NULL) return;

    Node* temp = new Node();
    temp->data = val;
    temp->next = ptr->next;
    ptr->next = temp;
}

void deleteFromBeginning() {
    if (head == NULL) return;
    Node* temp = head;
    head = head->next;
    delete temp;
}

void deleteFromEnd() {
    if (head == NULL) return;

    if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }

    Node* ptr = head;
    while (ptr->next->next != NULL)
        ptr = ptr->next;

    delete ptr->next;
    ptr->next = NULL;
}

void deleteNode(int val) {
    if (head == NULL) return;

    if (head->data == val) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* ptr = head;
    while (ptr->next != NULL && ptr->next->data != val)
        ptr = ptr->next;

    if (ptr->next == NULL) return;

    Node* temp = ptr->next;
    ptr->next = temp->next;
    delete temp;
}

void search(int val) {
    Node* ptr = head;
    int pos = 1;

    while (ptr != NULL) {
        if (ptr->data == val) {
            cout << "Found at position " << pos << endl;
            return;
        }
        ptr = ptr->next;
        pos++;
    }
    cout << "Not found\n";
}

void display() {
    Node* ptr = head;
    while (ptr != NULL) {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}
