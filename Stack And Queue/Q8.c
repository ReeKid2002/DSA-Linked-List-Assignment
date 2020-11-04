#include<stdio.h>
#define size 10
int stack[size],top=-1;
void push(int num)
{
    stack[++top] = num;
}
int pop()
{
    if(top==-1)
        return;
    else
        return stack[top--];
}
void main()
{
    int num;
    printf("Enter number of element: ");
    scanf("%d",&num);
    int arr[num];
    printf("Enter Array: ");
    for(int i=0;i<num;i++)
        scanf("%d",&arr[i]);
    push(arr[0]);
    for(int i=1;i<num;i++)
    {
        if(stack[top]>=arr[i])
            push(arr[i]);
        else
        {
            while(stack[top]<arr[i] && top!=-1)
            {
                int num = pop();
                printf("NGE of %d is %d.\n",num,arr[i]);
            }
            push(arr[i]);
        }
    }
    if(top!=-1)
    {
        while(top!=-1)
        {
            int num = pop();
            printf("No NGE of %d.\n",num);
        }
    }
}
