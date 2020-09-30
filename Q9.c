#include<stdio.h>
#include<malloc.h>
struct node
{
    int info;
    struct node *prev;
    struct node *next;
}*start1=NULL,*last1=NULL,*start2=NULL,*last2=NULL,*start3=NULL,*last3=NULL;
int num = 0;
void insert(struct node **start,struct node **last)
{
    struct node *t = (struct node*)malloc(sizeof(struct node));
    printf("Enter Data: ");
    scanf("%d",&t->info);
    t->prev = NULL;
    t->next = NULL;
    if(*start==NULL)
    {
        num++;
        *start = t;
        *last = t;
    }
    else
    {
        num++;
        t->prev = (*last);
        (*last)->next = t;
        *last = t;
    }
}
void display(struct node *start)
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
struct node* merge()
{
    struct node *start=NULL, *last=NULL;
    struct node *s1 = last1;
    struct node *s2 = last2;
    while(s1!=NULL && s2!=NULL)
    {
        if(s1->info > s2->info)
        {
            struct node *t = (struct node*)malloc(sizeof(struct node));
            t->info = s1->info;
            t->next = NULL;
            t->prev = NULL;
            if(start==NULL)
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
            s1 = s1->prev;
        }
        else if(s1->info < s2->info)
        {
            struct node *t = (struct node*)malloc(sizeof(struct node));
            t->info = s2->info;
            t->next = NULL;
            t->prev = NULL;
            if(start==NULL)
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
            s2 = s2->prev;
        }
        else
        {
            struct node *t = (struct node*)malloc(sizeof(struct node));
            t->info = s2->info;
            t->next = NULL;
            t->prev = NULL;
            if(start==NULL)
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
            s1 = s1->prev;
            s2 = s2->prev;
        }
    }
    if(s1==NULL)
    {
        while(s2!=NULL)
        {
            struct node *t = (struct node*)malloc(sizeof(struct node));
            t->info = s2->info;
            t->next = NULL;
            t->prev = NULL;
            if(start==NULL)
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
            s2 = s2->prev;
        }
    }
    else
    {
        while(s1!=NULL)
        {
            struct node *t = (struct node*)malloc(sizeof(struct node));
            t->info = s1->info;
            t->next = NULL;
            t->prev = NULL;
            if(start==NULL)
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
            s1 = s1->prev;
        }
    }
    return start;
}
void main()
{
    insert(&start1,&last1);
    insert(&start1,&last1);
    insert(&start1,&last1);
    insert(&start1,&last1);
    insert(&start1,&last1);
    insert(&start2,&last2);
    insert(&start2,&last2);
    insert(&start2,&last2);
    insert(&start2,&last2);
    insert(&start2,&last2);
    display(start1);
    display(start2);
    start3 = merge();
    //struct node *t = start2;
    //printf("%u",start3);
    display(start3);
}
