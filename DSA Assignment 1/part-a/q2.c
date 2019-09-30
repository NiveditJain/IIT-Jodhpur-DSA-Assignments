/* 
Problem Link:- https://www.spoj.com/problems/ADAQUEUE/
Submitted By:- Nivedit Jain, B18CSE039
*/

#include<stdio.h>
#include<stdlib.h>
#define default_message "No job for Ada?\n"

typedef struct DOUBLE_QUEUE
{
    int data;
    struct  DOUBLE_QUEUE * next;
    struct  DOUBLE_QUEUE * prev;
} d_que;

d_que * front=NULL, * rear =NULL;
int is_reverse=0;

void push_back(int data)
{
    if(front==NULL)
    {
        front=(d_que *)malloc(sizeof(d_que));
        rear=front;
        front->data=data;
        front->next=NULL;
        front->prev=NULL;
        return;
    }
    d_que * temp = (d_que *)malloc(sizeof(d_que));
    temp->data=data;
    if(is_reverse==0)
    {
        rear->next=temp;
        temp->prev=rear;
        temp->next=NULL;
        rear=temp;
    }
    else
    {
        temp->prev=NULL;
        temp->next=front;
        front->prev=temp;
        front=temp;   
    }
}

void to_front(int data)
{
    if(front==NULL)
    {
        front=(d_que *)malloc(sizeof(d_que));
        rear=front;
        front->data=data;
        front->next=NULL;
        front->prev=NULL;
        return;
    }
    d_que * temp = (d_que * )malloc(sizeof(d_que));
    temp->data=data;
    if(is_reverse==0)
    {
        temp->prev=NULL;
        temp->next=front;
        front->prev=temp;
        front=temp;
    }
    else
    {
        temp->next=NULL;
        temp->prev=rear;
        rear->next=temp;
        rear=temp;
    }
}

int main()
{
    int no_of_quarries;
    d_que * temp;
    scanf("%d",&no_of_quarries);
    while (no_of_quarries!=0)
    {
        char querry[10];
        scanf("%s",querry);
        if(querry[0]=='b')
        {
            if(front==NULL)
                printf(default_message);
            else if(is_reverse==0)
            {
                printf("%d\n",rear->data);
                temp=rear;
                rear=rear->prev;
                if(rear!=NULL)
                    rear->next=NULL;
                free(temp);
                if(rear==NULL)
                    front=NULL;
            }
            else
            {    
                printf("%d\n",front->data); 
                temp=front;
                front=front->next;
                if(front!=NULL)
                    front->prev=NULL;
                free(temp);
                if(front==NULL)
                    rear=NULL;               
            }        
        }
        else if(querry[0]=='f')
        {
            if(front==NULL)
                printf(default_message);
            else if(is_reverse==0)
            {
                printf("%d\n",front->data);
                temp=front;
                front=front->next;
                if(front!=NULL)
                    front->prev=NULL;
                free(temp);
                if(front==NULL)
                    rear=NULL;
            }
            else
            {
                printf("%d\n",rear->data);  
                temp=rear;
                rear=rear->prev;
                if(rear!=NULL)
                    rear->next=NULL;
                free(temp);
                if(rear==NULL)
                    front=NULL;
            }
        }
        else if(querry[0]=='r')
        {
            if(is_reverse==0)
                is_reverse=1;
            else
                is_reverse=0;            
        }
        else if(querry[0]=='p')
        {
            int data;
            scanf("%d",&data);
            push_back(data);
        }
        else
        {
            int data;
            scanf("%d",&data);
            to_front(data);
        }
        no_of_quarries--;
    }
}