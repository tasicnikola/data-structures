#include <string>
#include <iostream>
using namespace std;

struct node {
    int data;
    struct node* next;
};
struct node* head = NULL;
struct node* current = NULL;

void printList() {
    struct node* p = head;
    cout << "\n[";

    while (p != NULL) {
        cout << " " << p->data << " ";
        p = p->next;
    }
    cout << "]";
}

void insertatbegin(int data) {
    struct node* lk = (struct node*)malloc(sizeof(struct node));
    if (lk == NULL) {
        return;
    }

    lk->data = data;
    lk->next = head;
    head = lk;
}

void insertatend(int data) {
    struct node* lk = (struct node*)malloc(sizeof(struct node));
    if (lk == NULL) {
        return;
    }

    lk->data = data;
    lk->next = NULL;

    struct node* linkedlist = head;

    while (linkedlist->next != NULL)
        linkedlist = linkedlist->next;

    linkedlist->next = lk;
}

void insertafternode(struct node* list, int data) {
    struct node* lk = (struct node*)malloc(sizeof(struct node));
    if (lk == NULL) {
        return;
    }

    lk->data = data;
    lk->next = list->next;
    list->next = lk;
}

void deleteatbegin() {
    head = head->next;
}

void deleteatend() {
    struct node* linkedlist = head;
    while (linkedlist->next->next != NULL)
        linkedlist = linkedlist->next;
    linkedlist->next = NULL;
}

void deletenode(int key) {
    struct node* temp = head, *prev = NULL;
    if (temp != NULL && temp->data == key) {
        head = temp->next;
        return;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;

    prev->next = temp->next;
}

int searchlist(int key) {
    struct node* temp = head;
    while (temp != NULL) {
        if (temp->data == key) {
            temp = temp->next;
            return 1;
        }
        else
            return 0;
    }
    return key;
}

int main() {
    int k = 0;
    insertatbegin(12);
    insertatbegin(22);
    insertatend(30);
    insertatend(44);
    insertatbegin(50);
    insertafternode(head->next->next, 33);
    cout << "Linked List: ";

    printList();
    deleteatbegin();
    deleteatend();
    deletenode(12);
    cout << "\nLinked List after deletion: ";

    printList();
    insertatbegin(4);
    insertatbegin(16);
    cout << "\nUpdated Linked List: ";
    printList();
    k = searchlist(16);
    if (k == 1)
        cout << "\nElement is found";
    else
        cout << "\nElement is not present in the list";
    return 0;
}
