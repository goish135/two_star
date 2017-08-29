#include<stdio.h>
#include<stdlib.h>
int fib[5001][1500];
int digit[5001];
int main()
{
	fib[0][0]=0;//f0
	fib[1][0]=1;//f1
	for(int i=2;i<5001;i++)//f2
	{
		for(int j=0;j<1500;j++)
		{
			fib[i][j]+=fib[i-1][j]+fib[i-2][j];//禣Α计﹚竡 //imp.=> '+=' => '+'
			//because 璶秈ê计
			//ex:f10+f11=55+89
			//9+5=14
			// fib[i][j+1]=>1 fib[i][j]=>4
			//run:j++:秈计 8+5+'1'=14 (O) / 8+5=13 (X) 
			if(fib[i][j]>=10)
			{
				fib[i][j+1]=fib[i][j]/10;
				fib[i][j]%=10;	
			} 
		}
		
		int d;//т程蔼计(程オ) 
		for(d=1500;fib[i][d]==0;d--);
		digit[i]=d;
		/*for(int k=d;k>=0;k--)//test
			printf("%d",fib[i][k]);
		printf("\n");
		system("pause");*/
	}
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		printf("The Fibonacci number for %d is ",n);
		for(int i=digit[n];i>=0;i--)
			printf("%d",fib[n][i]);
		printf("\n");	
	}
	return 0;
}
