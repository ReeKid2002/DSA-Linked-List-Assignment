#include<stdio.h>
#define size 10
int top1=-1,top2=-1;
int ar1[size],ar2[size];
int push1(int num)
{
    if(top1==size-1)
    {
        printf("Stack Overflow!\n");
        return 0;
    }
    ar1[++top1] = num;
}
int push2(int num)
{
    if(top2==size-1)
    {
        printf("Stack Overflow!\n");
        return 0;
    }
    ar2[++top2] = num;
}
int pop1()
{
    if(top1==-1)
    {
        printf("Stack Underflow!\n");
        return 0;
    }
    return ar1[top1--];
}
int pop2()
{
    if(top2==-1)
    {
        printf("Stack Underflow!\n");
        return 0;
    }
    return ar2[top2--];
}
int copy()
{
    if(top1==-1)
        return 0;
    int temp = pop1();
    copy();
    push1(temp);
    push2(temp);
}
void main()
{
    for(int i=0;i<size;i++)
    {
        int num;
        printf("Enter Number: ");
        scanf("%d",&num);
        push1(num);
    }
    copy();
    printf("Element of Stack 1: ");
    for(int i=0;i<size;i++)
    {
        int num = pop1();
        printf("%d ",num);
    }
    printf("\n");
    printf("Element of Stack 2: ");
    for(int i=0;i<size;i++)
    {
        int num = pop2();
        printf("%d ",num);
    }
}
