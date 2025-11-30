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

void findMiddle() {
    if (head == NULL) return;

    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    cout << slow->data << endl;
}

int main() {
    int arr[] = {1,2,3,4,5};
    for (int i = 0; i < 5; i++) insertAtEnd(arr[i]);

    findMiddle();
}
