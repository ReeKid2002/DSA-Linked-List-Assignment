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
    printf("Enter Data :");
    scanf("%d",&t->info);
    t->next = NULL;
    if(start==NULL)
    {
        start=t;
        last = t;
    }
    else
    {
        last->next = t;
        last = t;
    }
}
void find_loop()
{
    int flag = 0;
    int counter = 0;
    struct node *p = start,*q = start;
    while(counter == 0)
    {
        if(p==q && p!=start && q!=start)
        {
            printf("Loop Exist!\n");
            flag==1;
            break;
        }
        if(p==NULL || q==NULL)
        {
            counter = 1;
            break;
        }
        p = p->next;
        q = p->next;
    }
    if(flag==0)
    {
        printf("No Loop Exist!\n");
        return;
    }
    else
    {
        p = start;
        while(p!=q)
        {
            p = p->next;
            q = q->next->next;
        }
        printf("Intersection point data = %d\n",p->info);
        while(p->next!=q)
            p = p->next;
        p->next = NULL;
    }
}
void display()
{
    if(start==NULL)
    {
        printf("LL Empty!\n");
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
void main()
{
    printf("Enter LL: \n");
    for(int i=0;i<6;i++)
        insert();
    printf("LL: ");
    display();
    find_loop(start);
}
