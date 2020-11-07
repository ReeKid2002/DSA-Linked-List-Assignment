#include<stdio.h>
#define size 100
char stack[size];
int top=-1;
void push(char b)
{
    stack[++top] = b;
}
char pop()
{
    return stack[top--];
}
void main()
{
    char string[100];
    printf("Enter String: ");
    scanf("%s",string);
    int max=0,count=0;
    for(int i=0;string[i]!='\0';i++)
    {
        if(string[i]=='(')
            push(string[i]);
        else
        {
            if(stack[top]=='(')
            {
                char c = pop();
                count+=2;
            }
        }
    }
    printf("Max Sized String: %d",count);
}
