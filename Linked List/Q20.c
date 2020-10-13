#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *next;
}*start=NULL,*last=NULL;
int num = 0;
void insert()
{
    num++;
    struct node *t = (struct node*)malloc(sizeof(struct node));
    printf("Enter Info: ");
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
    if(start==NULL)
    {
        printf("LL is Empty!\n");
        return;
    }
    struct node *t = start;
    while(t!=NULL)
    {
        printf("%d ",t->info);
        t = t->next;
    }
    printf("\n");
}
void rev_ll()
{
    struct node *p1,*p2,*p3;
    p1 = start;
    p2 = p1->next;
    p3 = p2->next;
    int t;
    if(num%2==0)
    {
        while(p2->next!=NULL)
        {
            t = p1->info;
            p1->info = p2->info;
            p2->info = t;
            p1 = p2->next;
            p2 = p1->next;
        }
    }
    else
    {
        while(p2!=NULL)
        {
            t = p1->info;
            p1->info = p2->info;
            p2->info = t;
            p1 = p2->next;
            p2 = p1->next;
        }
    }
}
void main()
{
    printf("Enter LL: \n");
    for(int i=0;i<7;i++)
        insert();
    printf("LL: ");
    display();
    printf("New LL: ");
    rev_ll();
    display();
}
