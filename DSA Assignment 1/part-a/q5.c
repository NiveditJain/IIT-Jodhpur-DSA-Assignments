/* 
Problem Link:- https://www.spoj.com/problems/CMG/
Submitted By:- Nivedit Jain, B18CSE039
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct STACK
{
    int data;
    int max;
    struct STACK * pre;
}stack;

stack * top = NULL;

void push(int data)
{
    stack * temp = (stack *)malloc(sizeof(stack));
    temp->data=data;
    temp->pre=top;
    if(top==NULL)
    {
        temp->max=data;
    }
    else
    {
        if(data>top->max)
            temp->max=data;
        else
            temp->max=top->max;
    }
    temp->pre=top;
    top=temp;    
}

void pop()
{
    if(top==NULL)
        return;
    stack * temp = top;
    top=top->pre;
    free(temp);
}

int main()
{
    int no_of_test;
    scanf("%d",&no_of_test);
    int no_of_queries;
    for(int i=1;i<=no_of_test;i++)
    {
        printf("Case %d:\n",i);
        scanf("%d",&no_of_queries);
        for(int j=0;j<no_of_queries;j++)
        {
            char query[2];
            scanf("%s",query);
            if(query[0]=='A')
            {
                int data;
                scanf("%d",&data);
                push(data);
            }
            if(query[0]=='R')
                pop();
            if(query[0]=='Q')
            {
                if(top==NULL)
                    printf("Empty\n");
                else   
                    printf("%d\n",top->max);
            }            
        }
        while(top!=NULL)
            pop();
    }
}