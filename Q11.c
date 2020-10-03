#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *next;
}*start=NULL,*last=NULL;
int num = 0;
struct node *create_node(struct node *t)
{
    num++;
    t = (struct node*)malloc(sizeof(struct node));
    return t;
};
void insert()
{
    struct node *t;
    t = create_node(t);
    printf("Enter Data: ");
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
    struct node *p = start;
    while(p!=NULL)
    {
        printf("%d ",p->info);
        p = p->next;
    }
    printf("\n");
}
void change_node()
{
    if(start==NULL)
    {
        printf("Operation cant be done!\n");
        return;
    }
    struct node *p,*t = start;
    for(int i=1;i<=num;i++)
    {
        if(i%2==0)
        {
            p->next = t->next;
            last->next = t;
            t->next = NULL;
            last = t;
            t = p;
        }
        p = t;
        t = t->next;
    }
}
void main()
{
    for(int i=0;i<5;i++)
        insert();
    printf("Linked List: ");
    display();
    printf("Changed Linked List: ");
    change_node();
    display();
}
