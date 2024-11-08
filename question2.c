#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coefficient;
    int exponent;
    struct Node* next;
};

struct Node* createNode(int coefficient, int exponent) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coefficient = coefficient;
    newNode->exponent = exponent;
    newNode->next = NULL;
    return newNode;
}

void insertNode(struct Node* head, int coefficient, int exponent) {
    struct Node* newNode = createNode(coefficient, exponent);
    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        return head;
    }
}

void addTerm(struct Node* head, int coefficient, int exponent) {
    struct Node* temp = head;
    while (temp != NULL) {
        if (temp->exponent == exponent) {
            temp->coefficient += coefficient;
        }
        temp = temp->next;
    }
    insertNode(head, coefficient, exponent);
}

void printPolynomial(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%dx^%d", temp->coefficient, temp->exponent);
        temp = temp->next;
        if (temp != NULL) {
            printf(" + ");
        }
    }
    printf("\n");
}

int main() {
    struct Node* poly1 = NULL;
    int n, coefficient, exponent;

    printf("Enter the number of terms in the first polynomial: ");
    scanf("%d", &n);

    printf("Enter the terms of the first polynomial (coefficient and exponent):\n");
    for (int i = 0; i < n; i++) {
        printf("Term %d:\n", i + 1);
        printf("Coefficient: ");
        scanf("%d", &coefficient);
        printf("Exponent: ");
        scanf("%d", &exponent);
        insertNode(poly1, coefficient, exponent);
    }

    printf("Enter the number of terms in the second polynomial: ");
    scanf("%d", &n);

    printf("Enter the terms of the second polynomial (coefficient and exponent):\n");
    for (int i = 0; i < n; i++) {
        printf("Term %d:\n", i + 1);
        printf("Coefficient: ");
        scanf("%d", &coefficient);
        printf("Exponent: ");
        scanf("%d", &exponent);
        addTerm(poly1, coefficient, exponent);
    }

    printf("The resulting polynomial is: ");
    printPolynomial(poly1);

    return 0;
}
