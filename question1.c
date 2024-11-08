#include<stdio.h>
#include<stdlib.h>
struct node{
    int coef;
    int exp;
    struct node* next;
};
struct node* newnode(int coef, int exp) {
    struct node* new_node = malloc(sizeof(struct node));
    new_node->coef = coef;
    new_node->exp = exp;
    new_node->next = NULL;
    return new_node;
}
struct node* add(struct node* head, int coef, int exp) {
    struct node* new_node = newnode(coef, exp);
    if (head == NULL) {
        return new_node;
    } else {
        struct node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
        return head;
    }
}
void display(struct node* head) {
    struct node* temp = head;
    while (temp != NULL) {
        printf("%dx^%d", temp->coef, temp->exp);
        temp = temp->next;
        if (temp != NULL){
            printf(" + ");}
    }
    printf("\n");
}
struct node* addpolynomials(struct node* poly1, struct node* poly2) {
    struct node* result = NULL;
    struct node *p1 = poly1, *p2 = poly2;
    while (p1 != NULL && p2 != NULL) {
        if (p1->exp == p2->exp) {
            int sum = p1->coef + p2->coef;
            result = add(result, sum, p1->exp);
            p1 = p1->next;
            p2 = p2->next;
        } else if (p1->exp > p2->exp) {
            result = add(result, p1->coef, p1->exp);
            p1 = p1->next;
        } else {
            result = add(result, p2->coef, p2->exp);
            p2 = p2->next;
        }
    }
    while (p1 != NULL) {
        result = add(result, p1->coef, p1->exp);
        p1 = p1->next;
    }
    while (p2 != NULL) {
        result = add(result, p2->coef, p2->exp);
        p2 = p2->next;
    }
    return result;
}
int main() {
    struct node *poly1 = NULL;
    struct node *poly2 = NULL;
    struct node *sum = NULL;
      

    int n1, n2, coef, exp;
    printf("Enter the number of terms in the first polynomial: ");
    scanf("%d", &n1);
    for (int i = 0; i < n1; i++) {
        scanf("%d %d", &coef, &exp);
        poly1 = add(poly1, coef, exp);
    }
    printf("Enter the number of terms in the second polynomial: ");
    scanf("%d", &n2);
    for (int i = 0; i < n2; i++) {
        scanf("%d %d", &coef, &exp);
        poly2 = add(poly2, coef, exp);
    }
    printf("Polynomial 1: ");
    display(poly1);
    printf("Polynomial 2: ");
    display(poly2);
    sum = addpolynomials(poly1, poly2);
    printf("Sum: ");
    display(sum);
    return 0;
}