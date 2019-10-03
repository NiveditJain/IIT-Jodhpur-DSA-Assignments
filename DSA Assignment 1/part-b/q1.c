/*
Problem Link:- https://www.spoj.com/problems/CLSLDR/
Submitted By:- Nivedit Jain, B18CSE039
*/

#include<stdio.h>
#include<stdlib.h>

int dp[1001][1001];

int CLSLDR(int first, int second)
{
	if(first==1) 
    {
        return 1;
    }
	else 
	{
		dp[first][second] = (CLSLDR(first-1,second)+second-1)%first+1;
		return dp[first][second];
	}
}

int main()
{
	int no_of_test;
    scanf("%d",&no_of_test);
    for(int i=1;i<1000;i++)
    {
        dp[1][i]=1;
        CLSLDR(1000,i);
    }
	while (no_of_test)
    {
        int n,m,o;
        scanf("%d %d %d",&n,&m,&o);
        printf("%d\n",(m+dp[n][o]-1)%n+1);
        no_of_test--;
    }	
}