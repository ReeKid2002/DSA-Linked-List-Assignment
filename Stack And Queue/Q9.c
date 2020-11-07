#include<stdio.h>
#define size 100
int indx[size],height[size],i_top = -1,h_top = -1,max = 0;
void push_index(int num)
{
    if(i_top==size-1)
        printf("Stack Full!\n");
    else
        indx[++i_top] = num;
}
int pop_index()
{
    if(i_top==-1)
        printf("Stack Empty!\n");
    else
        return indx[i_top--];
}
void push_height(int num)
{
    if(h_top==size-1)
        printf("Stack Full!\n");
    else
        height[++h_top] = num;
}
int pop_height()
{
    if(h_top==-1)
        printf("Stack Empty!\n");
    else
        return height[h_top--];
}
void main()
{
    int num;
    printf("Enter Length of Histogram: ");
    scanf("%d",&num);
    int arr[num];
    printf("Enter Heights of Histogram: ");
    for(int i=0;i<num;i++)
        scanf("%d",&arr[i]);
    push_height(arr[0]);
    push_index(0);
    for(int i=1;i<num;i++)
    {
        if(arr[i]>height[h_top])
        {
            push_height(arr[i]);
            push_index(i);
        }
        else if(arr[i]<height[h_top])
        {
            int h,idx;
            while(height[h_top]>arr[i])
            {
                h = pop_height();
                idx = pop_index();
                int cal = h*(i-idx);
                if(max<cal)
                    max = cal;
            }
            push_height(arr[i]);
            push_index(idx);
        }
        else
            continue;
    }
    if(h_top!=-1)
    {
        while(h_top!=-1)
        {
            int h = pop_height();
            int i = pop_index();
            int cal = h*(num-i);
            if(max<cal)
                max = cal;
        }
    }
    printf("Max Area: %d",max);
}

