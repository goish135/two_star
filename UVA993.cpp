// uva993 Product of digits (23456789)
// 3         // test case
// 1         // 1  
// 10        // 25 --OK
// 123456789 // -1

#include<stdio.h>
int main()
{
	int tc;
	scanf("%d",&tc);
	while(tc--)
	{
		int p; //product
		scanf("%d",&p);
		if(p==1) 
		{
			printf("1\n");
			continue;
		}
		int num[10]={0};
		//process
		for(int i=9;i>=2;i--)
		{
			while(p%i==0)
			{
				num[i]++;
				p/=i;
				//if(p==1) break;	
			}	
		}
		
		int flag = 0;
		if(p!=1) 
		{
			printf("-1");
			flag = 1;
		}
		
		//output
		for(int j=2; j<=9&&flag==0 ;j++)
		{
			while(num[j]--)
				printf("%d",j);
		}
		printf("\n");
	}
	return 0;
 } 
