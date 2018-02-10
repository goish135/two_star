// uva 696
#include<stdio.h>
#include<algorithm> // C++ library
int main()
{
	//freopen("696.txt","r",stdin);
	int m,n;
	while(scanf("%d %d",&m,&n))
	{
		//printf("check: %d %d\n",m,n); //--OK
		if(m==0&&n==0)
		{
			break;
		}
		int mi;
		mi = std::min(m,n);
		//printf("min: %d\n",mi); //--OK
		int ans;
		if(mi==1) // case 1
		{
			if(m*n==1)
			{
				printf("%d knights may be placed on a %d row %d column board.\n",m*n,m,n);
			}
			else
				printf("%d knights may be placed on a %d row %d column board.\n",m*n,m,n);
		}
		else if(mi==2)
		{
			if(m!=2) 
			{
				int a=m/4;
				//printf("a:%d\n",a);
				int b=m%4;
				//printf("b:%d\n",b);
				if(b==1) // +1
				{
					ans = ((a*2)+b)*2;
					printf("%d knights may be placed on a %d row %d column board.\n",ans,m,n);	
				} 
				else if(b==2||b==3) // +2
				{
					ans = ((a*2)+2)*2;
					printf("%d knights may be placed on a %d row %d column board.\n",ans,m,n);
				}
				else // ...0
				{
					ans = (a*2)*2;
					printf("%d knights may be placed on a %d row %d column board.\n",ans,m,n);
				}
			}
			else if(n!=2)
			{
			
				int a=n/4;
				//printf("a:%d\n",a);
				int b=n%4;
				//printf("b:%d\n",b);
				if(b==1) // +1
				{
					ans = ((a*2)+1)*2;
					printf("%d knights may be placed on a %d row %d column board.\n",ans,m,n);	
				} 
				else if(b==2||b==3) // +2
				{
					ans = ((a*2)+2)*2;
					printf("%d knights may be placed on a %d row %d column board.\n",ans,m,n);
				}
				else // ...0
				{
					ans = (a*2)*2;
					printf("%d knights may be placed on a %d row %d column board.\n",ans,m,n);
				}
			}
			else {
					printf("4 knights may be placed on a %d row %d column board.\n",m,n);
			}
		}
		else // imp.
		{
			ans = (m*n+1)/2 ;
			printf("%d knights may be placed on a %d row %d column board.\n",ans,m,n);
		}		
	}
	return 0;
}
