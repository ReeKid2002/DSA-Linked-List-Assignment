#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *next;
}*start=NULL,*last=NULL;
void insert()
{
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
void sort()
{
    int num;
    printf("Enter Number: ");
    scanf("%d",&num);
    int temp;
    struct node *t = start;
    struct node *p;
    for(t=start;t->next!=NULL;t=t->next)
        for(p=t->next;p!=NULL;p=p->next)
        {
            if(t->info>p->info)
            {
                temp = t->info;
                t->info = p->info;
                p->info = temp;
            }
        }
}
void main()
{
    for(int i=0;i<5;i++)
        insert();
    display();
    sort();
    display();
}
