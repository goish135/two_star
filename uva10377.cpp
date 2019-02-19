#include<stdio.h>

int main()
{
	//freopen("10377.txt","r",stdin);
	//freopen("10377out.txt","w",stdout);
	
	int tc;
	int row,col;
	scanf("%d",&tc);
	while(tc--)
	{
		scanf("%d %d",&row,&col);
		getchar();
		char loc[row+1][col+1];
		for(int i=1;i<=row;i++)
		{
			for(int j=1;j<=col;j++)
				scanf("%c",&loc[i][j]);
			getchar();
		}

		int x,y;
		scanf("%d %d",&x,&y);
		char ch;
		int cnt = 0 ;
		int d = 0; // 0:N 1:E 2:S 3:W   
		while((ch=getchar())!='Q')
		{
			//printf("%c",ch);
			//printf("%d %d %d\n",x,y,d);
			if(ch=='F')
			{
				if(d==0&&loc[x-1][y]!='*') 
				{
					x--;
				}
				if(d==1&&loc[x][y+1]!='*')
				{
					y++;
				}
				if(d==2&&loc[x+1][y]!='*')
				{
					x++;
				}
				if(d==3&&loc[x][y-1]!='*')
				{
					y--;
				}
			}
			else if(ch=='R')
			{
				d = (d+1)%4;
			}
			else if(ch=='L')
			{
				d = (d-1+4)%4;
			}
		}
		printf("%d %d",x,y);
		if(d==0)
		{
			printf(" N\n");
		}
		if(d==1)
		{
			printf(" E\n");
		}
		if(d==2)
		{
			printf(" S\n");
		}
		if(d==3)
		{
			printf(" W\n");
		}
		if(tc) printf("\n");
	
	} 
	return 0;	
}
