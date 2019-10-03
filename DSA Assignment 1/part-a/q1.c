/* 
Problem Link:- https://www.spoj.com/problems/MINSTACK/
Submitted By:- Nivedit Jain, B18CSE039
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct  STACK
{
    int data;
    int min;
    struct STACK * prev;
}stack;

stack * stk;

void push(int data)
{
    if(stk==NULL)
    {
        stk = (stack * )malloc(sizeof(stack));
        stk->data=data;
        stk->min=data;
        stk->prev=NULL;
        return;
    }
    stack * temp = (stack *)malloc(sizeof(stack));
    temp->data=data;
    temp->prev=stk;
    if(temp->data<stk->min)
        temp->min=temp->data;
    else
        temp->min=stk->min;
    stk=temp;
}

void pop()
{
    stack * temp=stk;
    stk=stk->prev;
    free(temp);
}

int main()
{
    stk=NULL;
    int no_of_quaries;
    scanf("%d",&no_of_quaries);
    while (no_of_quaries!=0)
    {
        char query[7];
        int data;
        scanf("%s",query);
        if(query[0]=='P' && query[1]=='U')
        {
            scanf("%d",&data);
            push(data);
        }
        else if(stk==NULL)
        {
            printf("EMPTY\n\n");
        }
        else if(query[0]=='P' && query[1]=='O')
        {
            pop();
        }
        else
        {
            printf("%d\n\n",stk->min);
        }
        no_of_quaries--;
    }
}