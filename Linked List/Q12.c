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
void change()
{
    int flag = 0;
    struct node *pre,*t = start;
    if(start==NULL)
    {
        printf("Operation cant be done!\n");
        return;
    }
    for(int i=0;i<num;i++)
    {
        t = start;
        while(t!=NULL)
        {
            if(t->info%2==0)
                break;
            pre = t;
            t = t->next;
        }
        if(t==start)
        {
            start = start->next;
            last->next = t;
            last = t;
            last->next = NULL;
        }
        else
        {
            pre->next = t->next;
            last->next = t;
            last = t;
            last->next = NULL;
        }
    }
}
void main()
{
    for(int i=0;i<5;i++)
        insert();
    printf("Linked List: ");
    display();
    printf("Changed Linked List: ");
    change();
    display();
}
