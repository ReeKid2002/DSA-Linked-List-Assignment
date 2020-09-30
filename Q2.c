#include<stdio.h>
#include<malloc.h>
struct node
{
    int info;
    struct node *prev;
    struct node *next;
};
struct node *start = NULL,*last = NULL;
void insert()
{
    struct node *q = (struct node*)malloc(sizeof(struct node));
    printf("Enter Data: ");
    scanf("%d",&q->info);
    q->next = NULL;
    q->prev = NULL;
    if(start == NULL)
    {
        q->prev = NULL;
        start = q;
        last = q;
    }
    else
    {
        q->prev = last;
        last->next = q;
        last = q;
    }
}
void display()
{
    struct node *t = start;
    if(start=NULL)
    {
        printf("LL is Empty!");
        return;
    }
    while(t!=NULL)
    {
        printf("%d ",t->info);
        t = t->next;
    }
    printf("\n");
}
void showinfo(int n)
{
    struct node *q = last;
    if(n<0)
    {
        printf("Wrong Input!\n");
        return;
    }
    for(int i=1;i<n;i++)
    {
        if(q->prev==NULL)
        {
            printf("Wrong Input!");
            return;
        }
        q = q->prev;
    }
    printf("Data of %d last node: %d\n",n,q->info);
}
void main()
{
    insert();
    insert();
    insert();
    insert();
    insert();
    display();
    showinfo(9);
}
