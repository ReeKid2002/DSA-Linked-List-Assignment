//Without Stack
/*
#include<stdio.h>
void main()
{
    int n;
    printf("Enter the size of String: ");
    scanf("%d",&n);
    char string[n];
    printf("Enter String: ");
    scanf("%s",string);
    int max,count=0;
    for(int i=0;string[i]!='\0';i++)
    {
        if(string[i]=='(')
            continue;
        else if(string[i]==')')
        {
            max = count;
            count = 0;
        }
        else
            count++;
    }
    printf("%d",max);
}
*/
//With Stack
#include<stdio.h>
char stack[5];
int top=-1;
void push(char b)
{
    stack[++top] = b;
}
void pop()
{
    top--;
}
void main()
{
    int n;
    printf("Enter the size of String: ");
    scanf("%d",&n);
    char string[n];
    printf("Enter String: ");
    scanf("%s",string);
    int max=0,count=0;
    for(int i=0;string[i]!='\0';i++)
    {
        if(string[i]=='(')
            push(string[i]);
        else if(string[i]==')')
        {
            if(max<count)
                max = count;
            count = 0;
            pop();
        }
        else
            count++;
    }
    printf("Max Sized String: %d",max);
}
