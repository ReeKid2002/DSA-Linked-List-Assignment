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
void union_ll(struct node **s1,struct node **l1,struct node *s2)
{
    struct node *t1 = (*s1);
    struct node *t2 = s2;
    int flag=0;
    while(t2!=NULL)
    {
        t1 = (*s1);
        while(t1!=NULL)
        {
            if(t2->info==t1->info)
                flag++;
            t1 = t1->next;
        }
        if(flag==0)
        {   struct node *cur = (struct node*)malloc(sizeof(struct node));
            cur->info = t2->info;
            cur->next = NULL;
            (*l1)->next = cur;
            (*l1) = cur;
        }
        flag=0;
        t2 = t2->next;
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
    union_ll(&s1,&l1,s2);
    printf("Union of LL: ");
    display(s1);
}
