#include<stdio.h>
#include<malloc.h>
struct node
{
    int info;
    struct node *next;
};
struct node *start=NULL,*last=NULL;
void insert()
{
    struct node *t = (struct node*)malloc(sizeof(struct node));
    printf("Enter Info: ");
    scanf("%d",&t->info);
    t->next = NULL;
    if(start == NULL)
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
        printf("LL is Empty!");
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
void ret(struct node *t)
{
    if(t==NULL)
    {
        start = NULL;
        last = NULL;
        return;
    }
    else
    {
        ret(t->next);
        if(start==NULL)
        {
            start = t;
            last = t;
        }
        else
        {
            last->next = t;
            last = t;
            last->next = NULL;
        }
    }
};
void main()
{
    for(int i=0;i<5;i++)
        insert();
    display();
    ret(start);
    display();
}
