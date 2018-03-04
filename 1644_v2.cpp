#include<stdio.h>
#include<math.h> // double sqrt(double)
#include<vector>
#define max 1299709+1
using namespace std;
bool sieve[1299709+1]; // 0-1299709
vector<int> prime;
void eratosthenes()
{
	int sqt = sqrt(max);
	for(int i=2;i<max;i++)
	{
		sieve[i] = true;
	}
	
	for(int i=2;i<=sqt;i++)
	{
		if(sieve[i])
		{
			for(int j=i*i;j<max;j+=i)
			{
				sieve[j] = false ;
			}
		}
	}
	
}
void pt()
{
	// vector<int> prime;
	for(int i=2;i<max;i++)
	{ 
		if(sieve[i])
		{
			prime.push_back(i);
			//printf("%d\n",i);
		} 
	}		
}
int main()
{
	//double p = sqrt(max);
    //printf("%lf\n",p);
    	int in;
    	eratosthenes(); // imp.
    	pt(); // imp.
    	while(scanf("%d",&in)&&in!=0){
    	//eratosthenes(); // 篩法結束
		//pt(); // 建立質數表
		int flag = 0;
		int size = prime.size();
		//printf("size:%d\n",size);
		for(int i=0;i<prime.size();i++)
		{
			if(in>prime[i]&&in<prime[i+1]&&i+1<prime.size()) // imp.
			{
				int a = prime[i];
				int b = prime[i+1];
				//printf("a:%d\n",a);
				//printf("b:%d\n",b);
			
				printf("%d\n",b-a);
				flag=1;
				break;
			}
		}
		if(flag==0) printf("0\n");
	}	
	return 0;	
} 
