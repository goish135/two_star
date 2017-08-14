#include<stdio.h>
int main()
{
	int size = 10000; 
	int ans[1000+1];//0-1000//store sum
	for(int w=0;w<1001;w++) ans[w]=0;//initial
	int product[size];//store 階乘的每個位數 
	product[0]=1;
	for(int w=1;w<size;w++) product[w]=0;//initial
	//for(int i=0;i<1000;i++)//會爆掉 
	//{
		//product[i+1]=product[i]*(i+1);
	//}
	for(int i=1;i<=1000;i++)//1!-> 2! -> 3! -> 4! -> 5! ...... 各位數的加總
	{
		for(int j=0;j<size;j++)
		{
			product[j]=product[j]*i;//大數乘法 
		}
		for(int k=0;k<size;k++)//進位 
		{
			product[k+1] += product[k]/10;
			product[k] = product[k]%10;
		}
		for(int z=0;z<size;z++) ans[i]+=product[z];//各位數的加總 
	}
	int n;
	while(scanf("%d",&n)!=EOF)
	printf("%d\n",ans[n]);
	return 0;
} 
