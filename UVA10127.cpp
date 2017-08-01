#include<stdio.h>
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int initial = 1;
		int sum = 1;
		while(initial%n!=0)
		{
			initial = (initial%n)*10+1;
			sum++;
		}
		printf("%d\n",sum);
	}
	return 0;
}			
