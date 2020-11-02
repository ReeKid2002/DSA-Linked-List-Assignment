#include<stdio.h>
#define size 5
int queue[size],front=-1,rear=-1;
void enqueue(int num)
{
    if(rear==size-1 || front>rear)
    {
        front=rear=-1;
        printf("Queue Full");
        return;
    }
    if(front==-1)
    {
        front++;
        rear++;
        queue[front] = num;
    }
    else
    {
        queue[++rear] = num;
    }
}
int dequeue()
{
    if(front==-1 || front==size)
        return;
    return queue[front++];
}
void reverse_queue()
{
    if(front==-1 || front>rear)
    {
        front=rear=-1;
        return;
    }
    int num = dequeue();
    reverse_queue();
    enqueue(num);
}
void main()
{
    for(int i=0;i<size;i++)
    {
        int num;
        printf("Enter Number: ");
        scanf("%d",&num);
        enqueue(num);
    }
    printf("Original Queue: ");
    for(int i=0;i<size;i++)
       printf("%d ",queue[i]);
    reverse_queue();
    printf("\nReversed Queue: ");
    for(int i=0;i<5;i++)
       printf("%d ",queue[i]);
}
