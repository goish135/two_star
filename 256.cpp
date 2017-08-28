/*
2
2
--
00
01
81
00
01
81
*/

#include<stdio.h>
int t[4][100];
int size[4];
void ct()
{
	for(int i=0;i<10000;i++){
		for(int j=0;j<10000;j++){
			int len = 10;
			for(int k=0;k<4;k++,len*=10){
				if((i+j)*(i+j)==i*len+j && (i/len==0) && (j/len==0))
				{
					t[k][size[k]++]=i*len+j;
				}
			}//for k
		}//for j
	}//for i
	return;
}
int main()
{
	ct();
	int n;
	while(scanf("%d",&n)==1)
	{
		// 0,1,2,3 //1 2 3 4 // 2 4 6 8
		int n_size = n/2-1;
		for(int i=0;i<size[n_size];i++)
		printf("%0*d\n",n,t[n_size][i]);	
	}		
}
