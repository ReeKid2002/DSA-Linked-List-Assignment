#include<stdio.h>
#define size 100
int stack[size],queue[size],temp_queue[size],top=-1,f=-1,r=-1,f2=-1,r2=-1;
void push(int num)
{
    if(top==size-1)
        printf("Stack Full!\n");
    else
        stack[++top] = num;
}
int pop()
{
    if(top==-1)
        printf("Stack Empty!\n");
    else
        return stack[top--];
}
void enqueue(int num)
{
    if(r==size-1)
        printf("Stack Full!\n");
    else if(f==-1)
    {
        f++;
        queue[++r] = num;
    }
    else
        queue[++r] = num;
}
int dequeue()
{
    if(f==-1 || f>r)
        printf("Queue Empty!\n");
    else
        return queue[f++];
}
void main()
{
    int num,n,k;
    printf("Enter Number of Element in Queue: " );
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("Enter %d Element: ",i+1);
        scanf("%d",&num);
        enqueue(num);
    }
    printf("Enter Number of element to Reverse: ");
    scanf("%d",&k);
    for(int i=0;i<k;i++)
        push(dequeue());
    while(top!=-1)
        enqueue(pop());
    int t = n-f;
    for(int i=0;i<t;i++)
    {
        int temp = dequeue();
        enqueue(temp);
    }
    printf("Reversed Queue: ");
    for(int i=f;i<=r;i++)
        printf("%d ",queue[i]);
}
