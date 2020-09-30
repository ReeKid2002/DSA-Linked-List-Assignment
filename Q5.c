#include<stdio.h>
#include<malloc.h>
struct node
{
    int info;
    struct node *next;
}*start = NULL,*last = NULL;
int num = 0;
void insert()
{
    struct node *t = (struct node*)malloc(sizeof(struct node));
    printf("Enter Data: ");
    scanf("%d",&t->info);
    t->next = NULL;
    if(start==NULL)
    {
        start = t;
        last = t;
        num++;
    }
    else
    {
        last->next = t;
        last = t;
        num++;
    }
}
void display()
{
    if(start ==NULL)
    {
        printf("LL is Empty!\n");
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
void checkpalin()
{
    if(start!=NULL)
    {
        int flag = 0;
        int n = num;
        struct node *chk1,*chk2;
        chk1 = start;
        if(num%2==0)
        {
            while(n>0)
            {
                chk2 = chk1;
                for(int i=1;i<n;i++)
                    chk2 = chk2->next;
                if(chk1->info == chk2->info)
                {
                    chk1 = chk1->next;
                    n-=2;
                }
                else
                {
                    flag = 1;
                    break;
                }
            }
        }
        else
        {
            while(n>1)
            {
                chk2 = chk1;
                for(int i=1;i<n;i++)
                    chk2 = chk2->next;
                if(chk1->info == chk2->info)
                {
                    chk1 = chk1->next;
                    n-=2;
                }
                else
                {
                    flag = 1;
                    break;
                }
            }
        }
        if(flag == 0)
            printf("LL is a palindrome!\n");
        else
            printf("LL is not a palindrome!\n");
    }
    else
        printf("LL is Empty!\n");
}
void main()
{
    checkpalin();
    insert();
    insert();
    insert();
    insert();
    insert();
    insert();
    insert();
    display();
    checkpalin();
}
