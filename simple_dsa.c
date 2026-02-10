#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* insert(struct Node *head, int value) {
    struct Node *n = (struct Node*)malloc(sizeof(struct Node));
    n->data = value;
    n->next = NULL;

    if(head == NULL) return n;

    struct Node *temp = head;
    while(temp->next != NULL)
        temp = temp->next;

    temp->next = n;
    return head;
}

void display(struct Node *head) {
    struct Node *temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node *head = NULL;

    head = insert(head, 10);
    head = insert(head, 20);
    head = insert(head, 30);
    head = insert(head, 40);

    display(head);

    return 0;
}
