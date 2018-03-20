#include<stdio.h>
#include<math.h>
char r[10000];

 
bool prime(int p)
{
	for(int i=2;i<=sqrt(p);i++)
	{
		if(p%i==0) return false;
	}
	return true;
}

int main() 
{
	//char r[1000];
	int a,b,c,t;
	while(scanf("%d%d",&a,&b)!=EOF)
	{
		c=0;
		for(int i=a;i<=b;i++)
		{
			if(r[i]==0)
			{
				t = i*i+i+41;
				if(prime(t))
				{
					r[i]=1; 
					c++;
				}
				else 
				{
					r[i]=2;
				}
			}
			else if(r[i]==1)
			{
				c++;
			}	
		}
		//printf("c: %d\n",c);
		double t1 =(double) c / (b-a+1);
		double ans = t1 * 100 + 0.00001;
		printf("%.2lf\n",ans);
	}
	return 0;	
}
