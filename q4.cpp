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

void reverseList() {
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

void display() {
    Node* ptr = head;
    while (ptr != NULL) {
        cout << ptr->data;
        if (ptr->next != NULL) cout << "->";
        ptr = ptr->next;
    }
    cout << "->NULL\n";
}

int main() {
    int arr[] = {1,2,3,4};
    for (int i = 0; i < 4; i++) insertAtEnd(arr[i]);

    reverseList();
    display();
}
