#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};
struct node *l1=NULL,*l2=NULL,*l3=NULL;


void insert_begin_l1(int data){
    struct node *new;
    new=malloc(sizeof(struct node));
    new->data=data;
    new->next=NULL;

    if(l1==NULL){
        l1=new;
        return;
    }

    new->next=l1;
    l1=new;
}


void insert_begin_l2(int data){
    struct node *new;
    new=malloc(sizeof(struct node));
    new->data=data;
    new->next=NULL;

    if(l2==NULL){
        l2=new;
        return;
    }

    new->next=l2;
    l2=new;

}
void insert_begin_l3(int data){
    struct node *new;
    new=malloc(sizeof(struct node));
    new->data=data;
    new->next=NULL;

    if(l3==NULL){
        l3=new;
        return;
    }

    new->next=l3;
    l3=new;

}

void add(){

    int carry=0;
    
    while(l1!=NULL || l2!=NULL || carry!=0){

        int num1=0,num2=0;
        if(l1!=NULL){
            num1=l1->data;
            l1=l1->next;
        }

        if(l2!=NULL){
            num2=l2->data;
            l2=l2->next;
        }


        int sum=num1+num2+carry;
        carry=sum/10;

        insert_begin_l3(sum%10);

    }

}

void print(){
    struct node *temp1;
    temp1=l3;

    while(temp1!=NULL){

        printf("%d  ", temp1->data);

        temp1=temp1->next;
    }
}

int main(){

    printf("please enter the number of digits in both number: \n");
    int m,n;
    scanf("%d", &m);
    scanf("%d", &n);

    char s1[m], s2[n];
    printf("enter the first number:");
    scanf("%s", s1);
    for(int i=0;i<m;i++){
        insert_begin_l1(s1[i]-'0');
    }

    printf("enter the second number:");
    scanf("%s", s2);

    for(int i=0;i<n;i++){
        insert_begin_l2(s2[i]-'0');
    }

    add();

    print();

}