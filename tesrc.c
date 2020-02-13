#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
typedef struct node NODE;
NODE *start;


int length(){
    NODE *p;
    p=start;
    int count=0;
    while(p!=NULL){
        count++;
        p=p->next;
    }
    return count;
}
void insert_at_begining(){
    int item;
    NODE *temp;
    temp=(NODE *)malloc(sizeof(NODE));
    printf("enter the element");
    scanf("%d",&item);
    temp->data=item;
    temp->next=start;
    start=temp;
}
void insert_at_end(){
    int item;
    NODE *temp , *hold;
        printf("enter the element");
    scanf("%d",&item);
    temp=(NODE *)malloc(sizeof(NODE));
       temp->data=item;
    while(hold!=NULL)
        hold=hold->next;
     temp->next=NULL;
     hold->next=temp;
     return ;
}
void insert_at_position(){
    int item,position,i;
    NODE *temp , *hold;
    printf("enter the element and the position");
    scanf("%d%d",&item,&position);
    if(position>length()){
        printf("\n\nposition does not exist in the list\n\n");
        return;
    }
    temp=(NODE *)malloc(sizeof(NODE));
    for(i=1;i<=position-1;i++)
        hold=hold->next;
    temp->data=item;
    temp->next=hold->next;
    hold=temp;
}
void traverse(){
    NODE *temp;
    temp=start;
    while(temp!=NULL){
        printf("%d  ",temp->data);
        temp=temp->next;
    }
    printf("\n\n");
}


int main(){
    int choice;
    NODE *start;
    do{
        printf("1.  insert at BEGINING\n\n");
        printf("2.  insert at end \n\n");
        printf("3.  insert at any position\n\n");
        printf("4.  Length\n\n");
        printf("5.  traverse\n\n");
        printf("6.  exit\n\n");
        printf("Enter your choice");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            insert_at_begining();
            break;
            case 2:
            insert_at_end();
            break;
            case 3:
            insert_at_position();
            break;
            case 4:
            printf("the length of the link list is %d",length());
            break;
            case 5:
            traverse();
            break;
            case 6:
            exit (0);
            break;
        }
    }while(1);
    getch();
    return 0;

}
