#include<stdio.h>
#define size 10
int arr[size];
int push(int num,int max_size,int top)
{
    if(top==max_size)
        printf("Stack Full!\n");
    else
    {
        arr[++top] = num;
        return top;
    }
}
int pop(int stack_num,int min_size,int top)
{
    if(top==min_size)
        printf("Stack Empty!\n");
    else
    {
        printf("%d pop form Stack %d\n",arr[top--],stack_num);
        return top;
    }
}
void main()
{
    int no_of_stack,flag=1;
    printf("Enter Number of Stack: ");
    scanf("%d",&no_of_stack);
    int top[no_of_stack];
    for(int i=0;i<no_of_stack;i++)
        top[i] = (i*(size/no_of_stack))-1;
    int choice,num,ch;
    while(flag)
    {
        printf("1. Push Element in Stack\n");
        printf("2. Pop Element form Stack\n");
        printf("3. Exit\n");
        printf("Enter Choice: ");
        scanf("%d",&ch);
        if(ch==1)
        {
            printf("Enter Number: ");
            scanf("%d",&num);
            printf("Enter Stack Number: ");
            scanf("%d",&choice);
            if(choice>no_of_stack)
                printf("Stack not present!\n");
            else
            {
                int max = (choice*(size/no_of_stack))-1;
                top[choice-1] = push(num,max,top[choice-1]);
            }
        }
        else if(ch==2)
        {
            printf("Enter Stack Number: ");
            scanf("%d",&choice);
            if(choice>no_of_stack)
                printf("Stack not present!\n");
            else
            {
                int min = ((choice-1)*(size/no_of_stack))-1;
                top[choice-1] = pop(choice,min,top[choice-1]);
            }
        }
        else if(ch==3)
            flag = 0;
        else
            printf("Wrong Option!\n");
    }
    /*for(int i=0;i<size;i++)
        printf("%d ",arr[i]);*/
}
