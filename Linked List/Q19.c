#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *next;
}*start1=NULL,*start2=NULL,*last1=NULL,*last2=NULL;
void insert(struct node **s,struct node **l)
{
    struct node *t = (struct node*)malloc(sizeof(struct node));
    printf("Enter Info: ");
    scanf("%d",&t->info);
    t->next = NULL;
    if((*s)==NULL)
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
int count(struct node *start)
{
    int c;
    struct node *t = start;
    while(t!=start)
    {
        c++;
        t=t->next;
    }
    return c;
}
void detect_intersection(struct node *s1,struct node *s2)
{
    struct node *p,*q;
    int c1,c2,diff;
    c1=count(s1);
    c2=count(s2);
    if(c1==0||c2==0)
    {
        printf("LL Is Empty!\n");
        return;
    }
    else if(c1 == c2)
    {
        int flag = 0;
        p=s1;
        q=s2;
        while(p!=NULL||q!=NULL)
        {
            if(p == q)
            {
                printf("%d is Element for intersection\n",p->info);
                flag = 1;
                break;
            }
            p = p->next;
            q = q->next;
        }
        if(flag==0)
            printf("No Point of Intersection!\n");
    }
    else
    {
        int flag = 0;
        if(c1>c2)
        {
            diff=c1-c2;
            p = s1;
            for(int i=0;i<diff;i++)
            {
                p=p->next;
            }
            q = s2;
            while(p!=NULL||q!=NULL)
            {
                if(p==q)
                {
                    printf("Intersection Point Element = %d",p->info);
                    flag = 1;
                    break;
                }
                p=p->next;
                q=q->next;
            }
            if(flag==0)
                printf("No Point of Intersection!\n");
        }
        else
        {
            diff = c2 - c1;
            p = s2;
            for(int i=0;i<diff;i++)
            q = q->next;
            p=s1;
            while(p!=NULL || q!=NULL)
            {
                if(p == q)
                {
                    printf("Intersection Point Element =%d",p->info);
                    flag = 1;
                    break;
                }
                p = p->next;
                q = q->next;
            }
            if(flag==0)
                printf("No Point of Intersection!\n");
        }
    }
}

void display(struct node *s)
{
    if(s==NULL)
    {
        printf("LL Is Empty!\n");
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
void main()
{
    printf("Enter 1st LL: \n");
    for(int i=0;i<5;i++)
        insert(&start1,&last1);
    printf("Enter 2nd LL: \n");
    for(int i=0;i<5;i++)
        insert(&start2,&last2);
    printf("1st LL: ");
    display(start1);
    printf("2nd LL: ");
    display(start2);
    detect_intersection(start1,start2);
}
