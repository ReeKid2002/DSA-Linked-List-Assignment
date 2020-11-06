#include<stdio.h>
#define size 10
int arr[size],f1=-1,r1=-1,f2=size,r2=size;
void enqueue()
{
    int choise;
    printf("Enter Queue(1/2): ");
    scanf("%d",&choise);
    if(choise==1)
    {
        if(r1==size || r1+1==r2 || f1>r1)
        {
            printf("Queue 1 Full!\n");
            return;
        }
        int num;
        printf("Enter Number: ");
        scanf("%d",&num);
        if(f1==-1)
        {
            f1++;
            arr[++r1] = num;
        }
        else
            arr[++r1] = num;
    }
    else if(choise==2)
    {
        if(r2==-1 || r2-1==r1 || f2<r1)
        {
            printf("Queue 2 Full!\n");
            return;
        }
        int num;
        printf("Enter Number: ");
        scanf("%d",&num);
        if(f2==size)
        {
            f2--;
            arr[--r2] = num;
        }
        else
            arr[--r2] = num;
    }
    else
        printf("Wrong Choice!\n");
}
void dequeue()
{
    int choice;
    printf("Enter Queue(1/2): ");
    scanf("%d",&choice);
    if(choice==1)
    {
        if(f1==-1 || f1>r1)
            printf("Queue 1 Empty!\n");
        else
            printf("%d pop from Stack %d\n",arr[f1++],choice);
    }
    else if(choice==2)
    {
        if(f1==size || f2<r2)
            printf("Queue 2 Empty!\n");
        else
            printf("%d pop from Stack %d\n",arr[f2--],choice);
    }
    else
        printf("Wrong Option!\n");
}
void main()
{
    int ch,flag=1;
    while(flag)
    {
        printf("1. Enqueue Element in Queue\n");
        printf("2. Dequeue form Queue\n");
        printf("3. Exit\n");
        printf("Enter Choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:enqueue();
                    break;
            case 2:dequeue();
                break;
            case 3:flag = 0;
                    break;
            default:printf("Wrong Option!\n");
        }
    }
}
