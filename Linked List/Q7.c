#include<stdio.h>
#include<malloc.h>
struct node
{
    int info;
    struct node *prev;
    struct node *next;
}*start=NULL,*last=NULL;
int num = 0;
void insert()
{
    struct node *t = (struct node*)malloc(sizeof(struct node));
    printf("Enter Data: ");
    scanf("%d",&t->info);
    t->prev = NULL;
    t->next = NULL;
    if(start==NULL)
    {
        num++;
        start = t;
        last = t;
    }
    else
    {
        num++;
        t->prev = last;
        last->next = t;
        last = t;
    }
}
void display()
{
    if(start==NULL)
    {
        printf("LL is empty!\n");
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
void rev(int n)
{
    if(n==1)
        return;
    else if(n == num)
    {
        struct node *p1 = start;
        struct node *p2 = p1->next;
        struct node *p3 = p2->next;
        p1->next = NULL;
        p2->next = p1;
        while(p3!=NULL)
        {
            p1 = p2;
            p2 = p3;
            p3 = p3->next;
            p2->next = p1;
        }
        start = p2;
    }
    else
    {
        int t;
        if(n%2==0)
        {
            struct node *p1=start;
            struct node *p2;
            while(p2->next!=NULL)
            {
                p2 = p1;
                for(int i=1;i<n;i++)
                {
                    if(p2->next==NULL)
                        break;
                    p2 = p2->next;
                }

            }
        }
    }
}
void main()
{
    for(int i=0;i<7;i++)
        insert();
    display();
    rev(7);
    display();
}
