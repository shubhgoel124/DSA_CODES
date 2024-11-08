//priority queue using double linked list
#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    int priority;
    struct Node* next;
    struct Node* prev;
};

struct Node* newNode(int d, int p){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = d;
    temp->priority = p;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}

int peek(struct Node* head){
    return head->data;
}

struct Node* dequeue(struct Node* head){
    struct Node* temp = head;
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    }
    free(temp);
    return head;
}

struct Node* enqueue(struct Node* head, int d, int p){
    struct Node* start = head;
    struct Node* temp = newNode(d, p);

    if (head == NULL || head->priority > p) {
        temp->next = head;
        if (head != NULL) {
            head->prev = temp;
        }
        return temp;
    } else {
        while (start->next != NULL && start->next->priority <= p) {
            start = start->next;
        }
        temp->next = start->next;
        if (start->next != NULL) {
            start->next->prev = temp;
        }
        start->next = temp;
        temp->prev = start;
        return head;
    }
}

int isEmpty(struct Node* head){
    return head == NULL;
}

int main(){
    struct Node* head = NULL;
    int n, data, priority;

    printf("Enter the number of elements to insert: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        printf("Enter value and priority for element %d: ", i+1);
        scanf("%d %d", &data, &priority);
        head = enqueue(head, data, priority);
    }

    while(!isEmpty(head)){
        printf("Element with highest priority: %d\n", peek(head));
        head = dequeue(head);
    }

    return 0;
}
