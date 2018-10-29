// UVA10220: I Love Big Numbers!
// Input : 幾階乘
// Output: 階乘後 每位數字的總和
// Ex : 5! => 120 => 1+2+0=3
// Note: Array store factorial number
 
#include<stdio.h>
#include<string.h>

int Array[5000]; // Array size not sure // store big number:factorial product 
int sum[1000+1];

void factorial()
{
	for(int i=0;i<5000;i++) Array[i] = 0;
	Array[0] = 1;
	for(int i=1;i<=1000;i++) // X1 X2 X3 ... X1000
	{
		int rem = 0;
		for(int j=0;j<5000;j++)
		{
			rem = Array[j]*i+ rem;
			Array[j] = rem%10;
			rem = rem/10;
		}
		
		for(int k=0;k<5000;k++)
		{
			sum[i]+=Array[k]; 
		}
	}
}
int main()
{
	factorial();	
	int in;
	while(scanf("%d",&in)==1)
	{
		printf("%d\n",sum[in]);		
	}	
	return 0;
} 
