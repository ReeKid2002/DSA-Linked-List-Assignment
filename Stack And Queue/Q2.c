#include<stdio.h>
#define size 5
int ar[size],min,top=-1;
int push(int num)
{
    if(top==size-1)
    {
        printf("Stack overflow!");
        return 0;
    }
    ar[++top] = num;
}
int pop()
{
    if(top==-1)
    {
        printf("Stack Underflow!");
        return 0;
    }
    return ar[top--];
}
void find_min()
{
    if(top==-1)
        return;
    int n = pop();
    if(n<min)
        min = n;
    find_min();
    push(n);
}

void main()
{
    for(int i=0;i<size;i++)
    {
        int num;
        printf("Enter Number: ");
        scanf("%d",&num);
        push(num);
    }
    min = ar[top];
    find_min();
    printf("Stack Element: ");
    for(int i=0;i<size;i++)
    {
        int num = pop();
        printf("%d ",num);
    }
    printf("\nMin Element: ");
    printf("%d",min);
}
