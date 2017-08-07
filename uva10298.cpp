#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	char A[1000000];
	while(scanf("%s",&A)&&A[0]!='.')
	{
		int n = 1;
		int len = strlen(A);
		for(int k=1;k<=len;k++)
		{	 
			if(len%k!=0) continue;//imp.
			int flag = 1;
			for(int i=k;i<len&&flag==1;i+=k)
			{
				for(int m=0;m<k&&flag==1;m++)//imp.
				{
					if(A[m]!=A[m+i])
					{
						flag = 0;
					}
				}
			}
			if(flag==1) {printf("%d\n",len/k);break;}
		}	
	}
	return 0;
}				
	
