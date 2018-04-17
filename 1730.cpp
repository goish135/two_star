#include<stdio.h>
#define max 20000001
long long ans[max];
int main()
{

	long long int n;
	//long long ans[max];
	for(int i=0;i<max;i++)
	{
		ans[i] = 0;
	}
	for(long long int i=2;i<=max;i++)
	{
		for(long long int j=i;j<=max;j+=i)
		{
			ans[j] += i;
		}
	}
	
	while(scanf("%lld",&n)&&n)
	{
		/*
		sum = 0;
		for(long long int i=1;i<=n;i++)
		{
			long long int total = n / i ;
			sum += total*i;
		}
		*/
		long long int sum=0;
		for(int i=2;i<=n;i++)
		{
			sum+=ans[i];
		}
		sum += (n-2+1);
		printf("%lld\n",sum);
	}
	return 0;	
} 
