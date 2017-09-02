#include<stdio.h>
int main()
{
	long long int fib[51]={0};
	fib[1]=1;
	fib[2]=2;
	for(int i=3;i<=50;i++)
	{
		fib[i] = fib[i-1]+fib[i-2];
	}
	
	int f;
	while(scanf("%d",&f)!=EOF)
	{
		if(f==0) break;
		printf("%lld\n",fib[f]);		
	}	
	return 0;
} 
