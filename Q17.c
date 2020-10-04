#include<stdio.h>
#include<malloc.h>
int top = 0,size=1;
int a[1]={0};
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
void push(int val)
{
    if(top==size-1)
        printf("Full\n");
    else
    {
        a[++top] = val;
    }
}
int pop()
{
    if(top==-1)
        printf("Empty!\n");
    else
    {
        int t = a[top];
        top--;
        return t;
    }
}
void cal_sum(struct node *s1,struct node *s2)
{
    struct node *t1 = s1,*t2 = s2;
    while(t1!=NULL || t2!=NULL)
    {
        int sum = pop();
        sum+=(t1->info+t2->info);
        push(sum);
        t1 = t1->next;
        t2 = t2->next;
    }
    int ans = pop();
    printf("Sum of LL: %d\n",ans);
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
    cal_sum(s1,s2);
}
