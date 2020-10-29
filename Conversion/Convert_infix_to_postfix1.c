#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char stack[30];
int top=-1;
char infix[50],postfix[50];
void push(char ele)
{
    top++;
    stack[top] = ele;
}
char pop()
{
    return stack[top--];
}
int check_precedence(char ele)
{
    if(ele=='+' || ele=='-')
        return 1;
    else if(ele=='/' || ele=='*')
        return 2;
    else if(ele=='%' || ele=='^')
        return 3;
    else
        return 0;
}
void main()
{
    int len_infix,len_postfix,index_postfix = -1;
    printf("Enter Infix Expression: ");
    scanf("%s",infix);
    push('(');
    len_infix = strlen(infix);
    infix[len_infix] = ')';
    int check1,check2;
    for(int i=0;i<=len_infix;i++)
    {
        if(infix[i]==')')
        {
            while(stack[top]!='(')
            {
                char temp = pop();
                postfix[++index_postfix] = temp;
            }
            char garbege = pop();
        }
        else if(infix[i]=='(')
        {
            push(infix[i]);
        }
        else if(infix[i]=='+'||infix[i]=='-'||infix[i]=='/'||infix[i]=='*'||infix[i]=='^'||infix[i]=='%')
        {
            check1 = check_precedence(infix[i]);
            check2 = check_precedence(stack[top]);
            while(check1<=check2)
            {
                char temp = pop();
                postfix[++index_postfix] = temp;
                check2 = check_precedence(stack[top]);
            }
            push(infix[i]);
        }
        else
        {
            postfix[++index_postfix] = infix[i];
        }
    }
    len_postfix = strlen(postfix);
    printf("Postorder: ");
    for(int i=0;i<len_postfix;i++)
        printf("%c",postfix[i]);
}
