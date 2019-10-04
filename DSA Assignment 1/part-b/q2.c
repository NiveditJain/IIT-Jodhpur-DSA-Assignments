/*
Problem Link:- https://www.spoj.com/problems/SAMBOX/
Submitted By:- Nivedit Jain, B18CSE039
*/

#include<stdio.h>
#include<stdlib.h>

typedef long long int number;

typedef struct LIST
{
    number data;
    struct LIST * prev;
}list;

list * insert(list * node, number data)
{
    list * temp = (list *)malloc(sizeof(list));
    temp->prev=node;
    temp->data=data;
    return temp;
}

int main()
{
    number * sticker_box;
    number * box_sticker;
    number * answer;
    number * parent;
    list ** children;
    number i;
    number boxes,queries;
    scanf("%lld %lld",&boxes,&queries);

    sticker_box=(number *)malloc(sizeof(number)*(boxes+2));
    box_sticker=(number *)malloc(sizeof(number)*(boxes+2));
    answer=(number *)malloc(sizeof(number)*(boxes+2));
    parent=(number *)malloc(sizeof(number)*(boxes+2));
    children=(list **)malloc(sizeof(list *)*(boxes+2));

    for(i=0;i<=boxes;i++)
    {
        children[i]=NULL;
        answer[i]=0;
        box_sticker[i]=i;
        sticker_box[i]=i;
    }
    parent[1]=0;

    number temp;
    for(i=2;i<=boxes;i++)
    {
        scanf("%lld",&temp);
        parent[i]=temp;
        children[temp]=insert(children[temp],i);
    }
    
    while(queries)
    {
        number type,x,y;
        scanf("%lld %lld",&type,&x);
        switch (type)
        {
        case 1:
        {
            scanf("%lld",&y);
            number present = sticker_box[y];
            while(present)
            {
                answer[present]+=x;
                present=parent[present];
            }
        }
        break;
        
        case 2:
        {
            scanf("%lld",&y);
            number box_x=sticker_box[x];
            number box_y=sticker_box[y];
            sticker_box[y]=box_x;
            sticker_box[x]=box_y;
            box_sticker[box_x]=y;
            box_sticker[box_y]=x;
        }
        break;

        case 3:
        {
            printf("%lld\n",answer[sticker_box[x]]);
        }
        break;

        case 4:
        {
            list * childs = children[sticker_box[x]];
            if(childs==NULL)
                printf("-1\n");
            else
            {
                number min=box_sticker[childs->data];
                do
                {   
                    if(box_sticker[childs->data]<min)
                        min=box_sticker[childs->data];
                    childs=childs->prev;    
                } while(childs!=NULL);
                printf("%lld\n",answer[sticker_box[min]]);
            }
        }
        break;

        }
        queries--;
    }
} 