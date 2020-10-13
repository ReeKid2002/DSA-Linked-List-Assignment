#include<stdio.h>
#include<malloc.h>
struct node
{
    int info;
    struct node *next;
};
struct node *start = NULL,*last = NULL;
void insert()
{
    struct node *q = (struct node*)malloc(sizeof(struct node));
    printf("Enter Number: ");
    scanf("%d",&q->info);
    q->next = NULL;
    if(start == NULL)
    {
        start = q;
        last = q;
    }
    else
    {
        last->next = q;
        last = q;
    }
}
void display()
{
    struct node *t = start;
    if (start ==NULL)
    {
        printf("LL is empty!");
        return;
    }
    while(t!=NULL)
    {
        printf("%d ",t->info);
        t = t->next;
    }
    printf("\n");
}
void dellinkl()
{
    struct node *t;
    if(start==NULL)
    {
        printf("LL is already Empty!\n");
        return;
    }
    while(start!=NULL)
    {
        t = start;
        printf("%d Deleted\n",t->info);
        start = t->next;
        free(t);
    }
}
void main()
{
    for(int i=0;i<6;i++)
        insert();
    display();
    dellinkl();
    display();
}
