#include<stdio.h>
#include<iostream>
#include<stdlib.h>
using namespace std;
const int max = 10001;
typedef struct coor
{
	int x;
	int y;
}coo;
coo oo[10001];
int main()
{
	int n;
	while(scanf("%d",&n)==1&&n!=0)
	{
		int N = 2*n;
	
		for(int i=0;i<N;i++)
		{
			cin>>oo[i].x>>oo[i].y;
			
		}
		int flag = 0;
		for(int i=-500;i<=500;i++) //A
		{
			for(int j=-500;j<=500;j++) //B
			{
				int sum_1 = 0;
				int sum_2 = 0;
				int k;
				for(k=0;k<N;k++)
				{
					if((i*oo[k].x+j*oo[k].y)>0) sum_1++;
					if((i*oo[k].x+j*oo[k].y)<0) sum_2++;
					if((i*oo[k].x+j*oo[k].y)==0)//imp.//櫻桃不能有切一半的 
					{
				
						break;	
					} 
				}
				if(k<N) continue;
			
				if(sum_1==n) 
				{
				
					flag = 1;
					printf("%d %d\n",i,j);
					break;
				}
			
			}
			if(flag==1) break;
		
		}
	}
	return 0;
} 
