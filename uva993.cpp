//使用Java的考生請注意，最外層的類別(class)需命名為 main 。
//如果遇到超乎想像的狀況，請更改編譯器試看看!! 各編譯器特性不同!!
//預設測資、隨機測資、固定測資是用來幫助除錯用的。批改時，只看暗中測資是否通過!!
// uva 993
#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		int in;
		scanf("%d",&in);
		int ans[1000];
		
		int key = 0;
		if(in>=0&&in<=9)
		{
			printf("%d\n",in);
			key = 1;	
		}
		
		int cnt = 0;
		
		while(key!=1)
		{
			
			int i;
			int flag = 0;
			for(i=9;i>=2;i--)
			{
				if(in%i==0)
				{
					//printf("i: %d\n",i);
					ans[cnt] = i ;
					cnt++; 
					in = in / i ;
				
					if(in==1) 
					{
						//printf("");
						for(int k=cnt-1;k>=0;k--)
						{
							printf("%d",ans[k]);
						}
						printf("\n");
						flag = 1;
						break; 
					}
					break;
				}
			}
			if(i==1&&flag==0) 
			{
				printf("-1\n");
				break;
			}
			if(flag==1) break; 
		}
	}
	return 0;	
} 
