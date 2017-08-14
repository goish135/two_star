#include<stdio.h>
int main()
{
	int size = 10000; 
	int ans[1000+1];//0-1000//store sum
	for(int w=0;w<1001;w++) ans[w]=0;//initial
	int product[size];//store 顶–计 
	product[0]=1;
	for(int w=1;w<size;w++) product[w]=0;//initial
	//for(int i=0;i<1000;i++)//穦脄奔 
	//{
		//product[i+1]=product[i]*(i+1);
	//}
	for(int i=1;i<=1000;i++)//1!-> 2! -> 3! -> 4! -> 5! ...... 计羆
	{
		for(int j=0;j<size;j++)
		{
			product[j]=product[j]*i;//计猭 
		}
		for(int k=0;k<size;k++)//秈 
		{
			product[k+1] += product[k]/10;
			product[k] = product[k]%10;
		}
		for(int z=0;z<size;z++) ans[i]+=product[z];//计羆 
	}
	int n;
	while(scanf("%d",&n)!=EOF)
	printf("%d\n",ans[n]);
	return 0;
} 
