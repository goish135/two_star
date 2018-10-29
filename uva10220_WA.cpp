// hw uva10200
// 1. n!
// 2. sum of each digit(n!)
#include<stdio.h>
#define ll long long 
ll factorial(int n)   // 階乘 //  
{
	ll f = 1;
	for(int i=2;i<=n;i++)
	{
		f*=i;
		printf("f:%lld\n",f);	
	}
	return f;		
}

int sum(int rv)
{
	int total = 0;
	while(rv)
	{
		total+=rv%10;
		printf("temp:%d\n",total);
		rv/=10;
	}
	
	return total;		
}  

#include<stdio.h>
int main()
{
	int n;
	while(scanf("%d",&n))
	{
		ll rv =factorial(n);
		printf("rv:%lld",rv);
		int ans = sum(rv);
		printf("%d\n",ans);		
	}
	return 0;
}