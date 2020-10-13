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
        return;
    else
    {
        printf("%d ",t->info);//for forward print
        ret(t->next);
        printf("%d ",t->info);//for backward print
    }
};
void main()
{
    for(int i=0;i<7;i++)
        insert();
    display();
    ret(start);
}
