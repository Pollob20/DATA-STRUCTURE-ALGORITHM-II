#include <stdio.h>
#include <stdlib.h>

// Node for Linked List (Data Structure)
struct Node {
    float x;
    float fx;
    struct Node* next;
};

// Function f(x) = x^3 + 2x
float function(float x) {
    return x*x*x + 2*x;
}

// Create a new node
struct Node* createNode(float x) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->x = x;
    newNode->fx = function(x);
    newNode->next = NULL;
    return newNode;
}

int main() {
    struct Node *head = NULL, *tail = NULL, *temp;
    int n = 6;
    float h = 1.0;

    // Create linked list of points
    for(int i = 0; i < n; i++) {
        temp = createNode(i * h);
        if(head == NULL) {
            head = tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }

    // Trapezoidal Rule for Numerical Integration (Calculus)
    float integral = 0.0;
    temp = head;

    while(temp->next != NULL) {
        integral += (temp->fx + temp->next->fx) * h / 2;
        temp = temp->next;
    }

    // Display points
    printf("x\tf(x)\n");
    temp = head;
    while(temp != NULL) {
        printf("%.2f\t%.2f\n", temp->x, temp->fx);
        temp = temp->next;
    }

    printf("\nApproximate Integral = %.2f\n", integral);

    return 0;
}
