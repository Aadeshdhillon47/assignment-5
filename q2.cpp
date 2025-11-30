#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

void insertAtEnd(int val) {
    Node* temp = new Node();
    temp->data = val;
    temp->next = NULL;

    if (head == NULL) {
        head = temp;
        return;
    }

    Node* ptr = head;
    while (ptr->next != NULL)
        ptr = ptr->next;

    ptr->next = temp;
}

int deleteOccurrences(int key) {
    int count = 0;

    while (head != NULL && head->data == key) {
        Node* temp = head;
        head = head->next;
        delete temp;
        count++;
    }

    Node* ptr = head;

    while (ptr != NULL && ptr->next != NULL) {
        if (ptr->next->data == key) {
            Node* temp = ptr->next;
            ptr->next = temp->next;
            delete temp;
            count++;
        } else {
            ptr = ptr->next;
        }
    }

    return count;
}
