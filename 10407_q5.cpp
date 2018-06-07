// uva 10407
#include<stdio.h>
#include<math.h>
#include<string.h>
#define max 1000
int A[max];
int B[max];

int GCD(int a,int b)
{
	if(b>a) 
	{
		int tmp = b ;
		b = a ;
		a = tmp;	
	} 
	
	while(b!=0)
	{
		int tp = a;
		a=b;
		b=tp%b;
	}
	return a ;
	
}

int main()
{
	//freopen("10407.in.txt","r",stdin); 
	//freopen("10407.out.txt","w",stdout); 
	int n;
	int cnt;
	while(scanf("%d",&n)&&n!=0)
	{
		memset(A,0,sizeof(A)); // imp.
		memset(B,0,sizeof(B)); // imp.
		cnt = 0;
		A[cnt++]=n;
		while(scanf("%d",&n)&&n!=0) A[cnt++]=n; 
		//for(int i=0;i<cnt;i++) printf("A[%d]: %d\n",i,A[i]);
		int ct = 0; 
		for(int i=1;i<cnt;i++)
		{
			B[ct] = abs(A[i]-A[0]);
			ct++; 	
		}
		//printf("\n");
		int temp = GCD(B[0],B[1]);
		
		for(int i=2;i<ct;i++)
		{
			temp = GCD(temp,B[i]);
		}
		printf("%d\n",temp);	
	}
	
	
	return 0;	
} 
