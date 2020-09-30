#include<stdio.h>
#include<malloc.h>
struct node
{
    int info;
    struct node *prev;
    struct node *next;
}*start=NULL,*last=NULL;
void insert()
{
    struct node *t = (struct node*)malloc(sizeof(struct node));
    printf("Enter Data: ");
    scanf("%d",&t->info);
    t->next = NULL;
    t->prev = NULL;
    if(start == NULL)
    {
        start = t;
        last = t;
    }
    else
    {
        t->prev = last;
        last->next = t;
        last = t;
    }
}
void display()
{
    if (start == NULL)
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
void change()
{
    int flag = 0;
    struct node *p1=NULL,*p2=NULL;
    struct node *c1 = start;
    struct node *c2 = last;
    while(flag==0)
    {
        c1 = start;
        c2 = last;
        while(c1->info%2==0)
        {
            p1 = c1;
            c1 = c1->next;
        }
        while(c2->info%2!=0)
        {
            p2 = c2;
            c2 = c2->prev;
        }
        if(c2->next==c1 || c1==c2)
        {
            flag=1;
            return;
        }
        if(c1==start && c2==last)
        {
            //
            start = start->next;
            start->prev = NULL;
            //
            last = last->prev;
            last->next = NULL;
            //
            c2->next = start;
            c2->prev = NULL;
            start->prev = c2;
            start = c2;
            //
            last->next = c1;
            c1->next = NULL;
            c1->prev = last;
            last = c1;
            //
        }
        else if(c1 == start && c2!=last)
        {
            //
            start = start->next;
            start->prev = NULL;
            //
            c2->prev->next = p2;
            p2->prev = c2->prev;
            //
            c2->next = start;
            c2->prev = NULL;
            start->prev = c2;
            start = c2;
            //
            c1->next = p2;
            c1->prev = p2->prev;
            p2->prev->next = c1;
            p2->prev = c1;
        }
        else if(c1!=start && c2==last)
        {
            //
            last = last->prev;
            last->next = NULL;
            //
            p1->next = c1->next;
            c1->next->prev = p1;
            //
            last->next = c1;
            c1->prev = last;
            c1->next = NULL;
            last = c1;
            //
            c2->next = p1->next;
            p1->next->prev = c2;
            c2->prev = p1;
            p1->next = c2;
            //
        }
        else
        {
            //
            p1->next = c1->next;
            c1->next->prev = p1;
            //
            p2->prev = c2->prev;
            c2->prev->next = p2;
            //
            c2->next = p1->next;
            p1->next->prev = c2;
            c2->prev = p1;
            p1->next = c2;
            //
            c1->prev = p2->prev;
            p2->prev->next = c1;
            c1->next = p2;
            p2->prev = c1;
            //
        }
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
    display();
    change();
    display();
}
