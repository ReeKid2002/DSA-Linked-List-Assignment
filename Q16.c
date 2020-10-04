#include<stdio.h>
#include<malloc.h>
struct node
{
    int info;
    struct node *next;
};
void insert(struct node **s,struct node **l)
{
    struct node *t = (struct node*)malloc(sizeof(struct node));
    printf("Enter Info: ");
    scanf("%d",&t->info);
    t->next = NULL;
    if((*s) == NULL)
    {
        (*s) = t;
        (*l) = t;
    }
    else
    {
        (*l)->next = t;
        (*l) = t;
    }
}
void display(struct node *s)
{
    if(s==NULL)
    {
        printf("LL is Empty!");
        return;
    }
    struct node *t = s;
    while(t!=NULL)
    {
        printf("%d ",t->info);
        t = t->next;
    }
    printf("\n");
}
void difference_ll(struct node **s1,struct node **s2)
{
    struct node *t1=(*s1);
    struct node *t2=(*s2);
    int ch;
    printf("1. LL1 - LL2\n");
    printf("2. LL2 - LL1\n");
    printf("Enter Choice: ");
    scanf("%d",&ch);
    while(t1!=NULL || t2!=NULL)
    {
        if(ch==1)
        {
            t1->info = t1->info-t2->info;
            t1 = t1->next;
            t2 = t2->next;
        }
        else if(ch==2)
        {
            t2->info = t2->info-t1->info;
            t1 = t1->next;
            t2 = t2->next;
        }
        else
        {
            printf("Wrong Option!\n");
            break;
        }
    }
    struct node *p;
    if(ch==1)
    {
        p = (*s1);
        printf("Difference of LL: ");
        display(p);
    }
    else
    {
        p = (*s2);
        printf("Difference of LL: ");
        display(p);
    }
}
void main()
{
    struct node *s1=NULL,*s2=NULL,*l1=NULL,*l2=NULL;
    printf("Enter 1st LL: \n");
    for(int i=0;i<5;i++)
        insert(&s1,&l1);
    printf("Enter 2nd LL: \n");
    for(int i=0;i<5;i++)
        insert(&s2,&l2);
    printf("1st LL: ");
    display(s1);
    printf("2nd LL: ");
    display(s2);
    difference_ll(&s1,&s2);
}
