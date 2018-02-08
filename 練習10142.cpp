//使用Java的考生請注意，最外層的類別(class)需命名為 main 。
//如果遇到超乎想像的狀況，請更改編譯器試看看!! 各編譯器特性不同!!
//預設測資、隨機測資、固定測資是用來幫助除錯用的。批改時，只看暗中測資是否通過!!
// uva10142
#include<stdio.h>
#include<string.h> //strcmp strtok
#include<stdlib.h> //atoi
int main()
{
	//freopen("測資_10142.txt","r",stdin); // smart method
	
	int n; // case
	int c; // candidate
	char can[20+1][80+1];   // name
	//int  vot[1000+1][20+1]; // ballot
	
	scanf("%d",&n);
	//int print = 0;
	while(n--){
		scanf("%d",&c);
		getchar(); // eat \n ,otherwise gets() will eat it
		for(int i=0;i<c;i++)
		{
			//scanf("%s",&can[i]);
			gets(can[i]);
			//printf("print:%s\n",can[i]);
		}
	//}
	
	int p=0; // 投票人數 
	char A[1000];
	int  vot[1000+1][20+1];
	
	for(int i=0;i<1001;i++)
	{
		for(int j=0;j<21;j++)
		{
			vot[i][j]=0;
		}
	}
	
	while(gets(A))
	{
		if(strcmp(A,"")==0) // the same
		{
			break;
		}

		char *token;
		token=strtok(A," ");
		int j=0;
		while(token!=NULL)
		{
			//printf("XD\n");
			int temp = atoi(token);
			//printf("%d\n",temp);
			vot[p][j++]=temp;
			token=strtok(NULL," ");
		}
		p++;
	}
	
	/*for(int i=0;i<p;i++)
	{
		for(int j=0;j<c;j++)
		{
			printf("%d ",vot[i][j]);		
		}
		printf("OK\n"); 
	}*/
	
	int sum[20+1]; // save candidate's ballot number // 統計每位候選人的票數
	for(int i=0;i<21;i++)
	{
		sum[i] = 0;
	}
	int elimate[20+1]; // 紀錄誰被淘汰 1:淘汰 0:沒被淘汰
	for(int i=0;i<21;i++)
	{
		elimate[i] = 0;
	}
	int max=0,min=1000;
	
	int result = 0;
	
	while(result==0)
	{
		//printf("loop\n");
		
		for(int i=0;i<p;i++)
		{
			int j=0;
			while(elimate[vot[i][j]]==1)
			{
				j++;
			}
			sum[vot[i][j]]++;
			//printf("vote for: %d\n",vot[i][j]);
		}
		// 每個人的票數皆統計好
		
		max = 0 , min = 1000;
		//int whoa,whob;
		for(int i=1;i<=c;i++)
		{
			if(elimate[i]==0)
			{
				//printf("in: %s\n",can[i-1]);
				if(sum[i]>max)
				{
					max  = sum[i];
					//whoa = i ; 	
				}
				if(sum[i]<min)
				{
					min  = sum[i];
					//whob = i;
				}
			}
		}
		// 找出最高票 最低票
		//printf("max: %d\n",max);
		//printf("min: %d\n",min);
		
		for(int i=1;i<=c;i++)
		{
			if(max==sum[i])
			{
				if(max+max>p) // good method
				{
					//printf("test\n");
					//printf("%d %d\n",max,p);
					
					printf("%s\n",can[i-1]);
					result = 1 ;	
				} 
			}
			if(min==sum[i])
			{
				//printf("bye: %s\n",can[i-1]);
				elimate[i] = 1;	
			}		
		}
		if(result==1) break;
		if(max==min)
		{
			//printf("Hi\n");
			for(int i=1;i<=c;i++)
			{
				if(sum[i]==max)
				{
					result = 1;
					printf("%s\n",can[i-1]);
				} 	
			}
			//if(result==1) break;	
		} 
		
		if(result==0)
		{
			for(int i=1;i<=c;i++)
			{
				sum[i] = 0;	
			}	
		}			
	}
	if(n>0) printf("\n");

	//print = 1;
	/*for(int i=1;i<=c;i++)
	{
		printf("%d %d\n",i,sum[i]);
	}*/
	 
	}
	return 0;  
 } 
