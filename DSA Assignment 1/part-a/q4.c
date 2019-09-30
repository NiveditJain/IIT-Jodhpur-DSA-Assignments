/* 
Problem Link:- https://www.spoj.com/status/BRIDGE/
Submitted By:- Nivedit Jain, B18CSE039
*/

#include<stdlib.h>
#include<stdio.h>

typedef struct PAIR
{
    int first,second;
}pair;

int comp(const void * a, const void * b) {
   return ((*(pair *)a).first == (*(pair*)b).first)?((*(pair *)a).second > (*(pair*)b).second):((*(pair *)a).first > (*(pair*)b).first);
}

int lis(pair * data,int size)
{
   int dp[size],max=0;

   for(int i=0;i<size;i++)
      dp[i]=1;
    
   for(int i=1;i<size;i++)
      for(int j=0;j<i;j++)
         if(data[i].second>=data[j].second && dp[i]<dp[j]+1)
            dp[i]=dp[j]+1;

   for(int i=0;i<size;i++)
        if(max<dp[i])
            max=dp[i];

   return max;
}

int main()
{
    int no_of_test;
    scanf("%d",&no_of_test);
    while (no_of_test)
    {
        int size,maxi=0;
        scanf("%d",&size);
        pair data[size];
        for(int i=0;i<size;i++)
            scanf("%d",&data[i].first);
        for(int i=0;i<size;i++)
            scanf("%d",&data[i].second);
        qsort(data,size,sizeof(pair),comp);
        printf("%d\n",lis(data,size));
        no_of_test--;      
    }
}