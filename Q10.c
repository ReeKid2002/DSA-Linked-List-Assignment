#include<stdio.h>
#include<stdlib.h>
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
    if(*s==NULL)
    {
        *s = t;
        *l = t;
    }
    else
    {
        (*l)->next = t;
        (*l) = t;
    }
}
void display(struct node *s)
{
    struct node *t = s;
    if(s==NULL)
    {
        printf("LL is empty!\n");
        return;
    }
    while(t!=NULL)
    {
        printf("%d ",t->info);
        t = t->next;
    }
    printf("\n");
}
void merge(struct node **s1,struct node *s2)
{
    struct node *pre1=NULL,*t1=NULL;
    struct node *t2 = s2,*pre2=s2;
    while(t2!=NULL)
    {
        t1 = *s1;
        if((*s1)==NULL || (*s1)->info>t2->info)
        {
            printf("1.\n");
            struct node *cur = (struct node*)malloc(sizeof(struct node));
            cur->info = t2->info;
            cur->next = NULL;
            cur->next = (*s1);
            (*s1) = t2;
        }
        else
        {
            while(t1!=NULL)
            {
                if(t1->info<t2->info)
                {
                    pre1 = t1;
                    t1 = t1->next;
                }
                else
                    break;
            }
            struct node *cur = (struct node*)malloc(sizeof(struct node));
            cur->info = t2->info;
            cur->next = NULL;
            cur->next = t1;
            pre1->next = cur;

        }
        t2 = t2->next;
    }

}
void main()
{
    struct node *s1=NULL,*l1=NULL,*s2=NULL,*l2=NULL;
    printf("Enter 1st Linked List: \n");
    for(int i=0;i<5;i++)
        insert(&s1,&l1);
    printf("Enter 2nd Linked List: \n");
    for(int i=0;i<5;i++)
        insert(&s2,&l2);
    printf("1st Linked List: ");
    display(s1);
    printf("2nd Linked List: ");
    display(s2);
    merge(&s1,s2);
    printf("Merged Linked List: ");
    display(s1);
}
