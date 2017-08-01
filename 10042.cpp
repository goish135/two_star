#include<stdio.h>
#include<math.h>

int digit_sum(int n)//计㎝ 
{
	int sum = 0;
	for(int i=n;i;i/=10)
	{
		sum=sum+(i%10);
	}
	//printf("ds:%d\n",sum);

	return sum;
}
int bnj(int j)//借计㎝ 
{
	int prime = 0;//0:琌借计 1:ぃ琌借计
	int temp = j;
	int sum = 0;
	for(int k=2;k<=sqrt(j);k++)
	{
		while(temp%k==0)
		{
			prime=1;
			sum=sum+k;
			temp/=k;
		}
	} 
	if(prime==1)
	{
		if(temp!=1)
			sum = sum + digit_sum(temp);
		//printf("$%d\n",sum);	
		return sum;	
	}
}
int main()
{
	int tc;
	scanf("%d",&tc);
	while(tc--)
	{
		int n;
		scanf("%d",&n);
		for(int j=n+1;;j++)
		{
			if(bnj(j)==digit_sum(j))
			{
				printf("%d\n",j);
				break;	
			}
		}
	}
} 
