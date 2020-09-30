#include<stdio.h>
#include<malloc.h>
struct node
{
    int info;
    struct node *next;
}*start=NULL,*last=NULL;
void insert()
{
    struct node *t = (struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d",&t->info);
    t->next = NULL;
    if(start==NULL)
    {
        start = t;
        last = t;
    }
    else
    {
        last->next = t;
        last = t;
    }
}
void display()
{
    struct node *q = start;
    while(q!=NULL)
    {
        printf("%d ",q->info);
        q = q->next;
    }
    printf("\n");
}
void swap(int n1,int n2)
{
    struct node *q = start;
    struct node *num1,*prv1=NULL;
    struct node *num2,*prv2=NULL;
    struct node *temp;
    num1 = start;
    num2 = start;
    while(num1->info!=n1)
    {
        if(num1==NULL)
        {
            printf("Wrong Input!\n");
            return;
        }
        prv1 = num1;
        num1 = num1->next;
    }
    while(num2->info!=n2)
    {
        if(num2==NULL)
        {
            printf("Wrong Input!\n");
            return;
        }
        prv2 = num2;
        num2 = num2->next;
    }
    if(num1==num2)
        return;
    else if(num1 == start)
    {
        if(num1->next==num2)
        {
            start = start->next;
            num1->next = start->next;
            start->next = num1;
        }
        else
        {
            prv2->next = num2->next;
            start = start->next;
            num2->next = start;
            start = num2;
            num1->next = prv2->next;
            prv2->next = num1;
        }
    }
    else if(num1->next==num2)
    {
        num1->next = num2->next;
        num2->next = num1;
        prv1->next = num2;
    }
    else
    {
        temp = num1;
        prv1->next = num1->next;
        prv2->next = num2->next;
        num2->next = prv1->next;
        prv1->next = num2;
        num1->next = prv2->next;
        prv2->next = num1;
    }

}
void main()
{
    insert();
    insert();
    insert();
    insert();
    insert();
    insert();
    insert();
    insert();
    insert();
    display();
    swap(1,2);
    display();
}
