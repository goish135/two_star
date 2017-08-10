#include<stdio.h>
#include<math.h>
bool prime(int n)
{
	for(int i=2;i<=sqrt(n);i++)
	{
		if(n%i==0) return false;
	}
	return true;
}
int main()
{
	int a,b;
	int table[10000];
	for(int j=0;j<10000;j++)
	{
		table[j]=0;
	}	
	while(scanf("%d %d",&a,&b)!=EOF)
	{
		int sum=0;
		for(int k=a;k<=b;k++)
		{
			if(table[k]==0)//?
			{
				int temp = k*k+k+41;
				if(prime(temp)==true)
				table[k]=1;//yes
			}
			if(table[k]==1) sum++;
		}
		double ans =((double)sum/(b-a+1)*100);//imp.
		printf("%.2lf\n",ans);
	}
	return 0;	
}
