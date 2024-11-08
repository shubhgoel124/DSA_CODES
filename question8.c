#include <stdlib.h>
#include <stdio.h>

struct node {
    int row;
    int col;
    int val;
    struct node* next;
    struct node* down;
    struct node* right;
};

void arrayRepresentation(int n, int m, int arr[n][m]) {
    int a[3][n * m];
    int x = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] != 0) {
                a[0][x] = i;
                a[1][x] = j;
                a[2][x++] = arr[i][j];
            }
        }
    }

    printf("Row:\t");
    for (int i = 0; i < x; i++) {
        printf("%d\t", a[0][i]);
    }
    printf("\nCol:\t");
    for (int i = 0; i < x; i++) {
        printf("%d\t", a[1][i]);
    }
    printf("\nVal:\t");
    for (int i = 0; i < x; i++) {
        printf("%d\t", a[2][i]);
    }
    printf("\n");
}

void linkedlistRepresentation(int n, int m, int arr[n][m]) {
    struct node* head = NULL;
    struct node* ptr = NULL;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] != 0) {
                struct node* newNode = (struct node*)malloc(sizeof(struct node));
                newNode->row = i;
                newNode->col = j;
                newNode->val = arr[i][j];
                newNode->next = NULL;

                if (head == NULL) {
                    head = newNode;
                    ptr = head;
                } else {
                    ptr->next = newNode;
                    ptr = ptr->next;
                }
            }
        }
    }
  
    printf("|Value->Row->Col|--->");
    ptr = head;
    while (ptr != NULL) {
        printf("|%d->%d->%d|", ptr->val, ptr->row, ptr->col);
        if (ptr->next != NULL)
            printf("--->");
        ptr = ptr->next;
    }
    printf("\n");
}

void listoflistRepresentation(int n, int m, int arr[n][m]) {
    struct node* head = NULL;
    struct node* rowPtr = NULL;

    for (int i = 0; i < n; i++) {
        struct node* rowNode = (struct node*)malloc(sizeof(struct node));
        rowNode->row = i;
        rowNode->right = NULL;
        rowNode->down = NULL;

        if (head == NULL) {
            head = rowNode;
            rowPtr = head;
        } else {
            rowPtr->down = rowNode;
            rowPtr = rowPtr->down;
        }

        struct node* colPtr = rowNode;
        for (int j = 0; j < m; j++) {
            if (arr[i][j] != 0) {
                struct node* colNode = (struct node*)malloc(sizeof(struct node));
                colNode->col = j;
                colNode->val = arr[i][j];
                colNode->right = NULL;

                if (colPtr->right == NULL) {
                    colPtr->right = colNode;
                    colPtr = colNode;
                } else {
                    colPtr->right = colNode;
                    colPtr = colPtr->right;
                }
            }
        }
    }

    printf("ROW-->|COL-->VAL|\n|\n");
    rowPtr = head;
    while (rowPtr != NULL) {
        struct node* colPtr = rowPtr->right;
        printf("%d-->", rowPtr->row);
        while (colPtr != NULL) {
            printf("|%d-->%d|--->", colPtr->col, colPtr->val);
            colPtr = colPtr->right;
        }
        printf("NULL\n|\n");
        rowPtr = rowPtr->down;
    }
    printf("NULL\n");
}

int main() {
    int arr[4][5] = {
        {0, 0, 3, 0, 4},
        {0, 0, 5, 7, 0},
        {0, 0, 0, 0, 0},
        {0, 2, 6, 0, 0}
    };

    printf("\n\n_SPARSE MATRIX_\n\n\n\n");

    printf("ARRAY REPRESENTATION :-\n");
    arrayRepresentation(4, 5, arr);

    printf("\n\nLINKED LIST REPRESENTATION :-\n");
    linkedlistRepresentation(4, 5, arr);

    printf("\n\nLIST OF LIST REPRESENTATION :-\n");
    listoflistRepresentation(4, 5, arr);

    return 0;
}
