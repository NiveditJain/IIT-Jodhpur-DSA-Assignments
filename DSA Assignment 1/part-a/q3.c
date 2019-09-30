/* 
Problem Link:- https://www.spoj.com/problems/ARRAYSUB/
Submitted By:- Nivedit Jain, B18CSE039
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct D_Que
{
    int data;
    struct D_Que * next;
    struct D_Que * prev;
}d_que;

d_que * front = NULL;
d_que * rear = NULL;

void push_back(int data)
{
    d_que * temp = (d_que *)malloc(sizeof(d_que));
    temp->data=data;
    if(front==NULL)
    {
        temp->next=NULL;
        temp->prev=NULL;
        front=rear=temp;
        return;
    }
    temp->next=NULL;
    temp->prev=rear;
    rear->next=temp;
    rear=temp;    
}

void pop_front()
{
    d_que * point = front;
    front=front->next;
    if(front==NULL)
        rear=NULL;
    else
        front->prev=NULL;
    free(point);
}

void pop_back()
{
    d_que * point = rear;
    rear=rear->prev;
    if(rear==NULL)
        front=NULL;
    else
        rear->next=NULL;
    free(point);
}

int main()
{
    int size;
    scanf("%d",&size);
    int data[100001];
    for(int i=0;i<size;i++)
    {
        scanf("%d",data+i);
    }
    int window_size;
    scanf("%d",&window_size);
    for(int i=0;i<window_size;i++)
    {
        while(rear!=NULL && data[i]>=data[rear->data])
          pop_back();
        push_back(i);
    }
    d_que * temp = front;
    printf("%d ",data[front->data]);
    for(int i=window_size;i<size;i++)
    {
        while(front!=NULL && front->data<=i-window_size)
            pop_front();
        while(rear!=NULL && data[i]>=data[rear->data])
            pop_back();
        push_back(i);
        printf("%d ",data[front->data]);
    }
}