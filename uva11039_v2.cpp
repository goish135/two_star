#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<vector>
using namespace std;
bool cmp(int a,int b)
{
	if(abs(a)>abs(b)) return true;
	return false;
}

int main()
{
	int tc;
	scanf("%d",&tc);	
	while(tc--)
	{
		int total;
		scanf("%d",&total);
		long long int A[total];
		for(int i=0;i<total;i++)
		{
			scanf("%lld",&A[i]);  // imp. ������ line 36 // �� %d (int) �|�X��(�B��Ȫ��P�_) 
		}
		sort(A,A+total,cmp);
		/*
		for(int i=0;i<total;i++)
		{
			printf("%d ",A[i]);
		}
		printf("\n");
		*/
		int ans = 0;
		for(int j=0;j<total-1;j++)
		{
			if(A[j]*A[j+1]<0) 
			{
				//printf("%d X %d\n",A[j],A[j+1]);
				ans++;
			}
		}
		ans = ans + 1;
		printf("%d\n",ans);
	}
	return 0;	
} 
