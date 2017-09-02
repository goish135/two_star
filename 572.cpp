#include<stdio.h>
#include<string.h>
const int max =100+1; 
int visited[max][max];
char map[max][max];
int dx[8]={-1,-1,-1,0,0,1,1,1};
int dy[8]={-1, 0, 1,-1,1,-1,0,1};

void dfs(int x,int y)
{
	if( map[x][y]=='*' || map[x][y]=='0' || visited[x][y]==1) return;//�D�o�|�θI��(���)�Τw�X�Nreturn 
	visited[x][y]=1;//�N���X�L���y�маO��1 
	for(int i=0;i<8;i++) dfs(x+dx[i],y+dy[i]);
}

int main()
{
	int m,n;
	while(scanf("%d %d",&m,&n)!=EOF)
	{
		memset(visited,0,sizeof(visited));//����l��//0:���X 
		memset(map,'0',sizeof(map));//��l //'0':��� 
		if(m==0&&n==0) break;
		for(int i=1;i<=m;i++) scanf("%s",map[i]+1);//�q(1,1)��m�}�l��J
		int count = 0;//�p�@�h�֪o�| 
		for(int j=1;j<=m;j++)
			for(int k=1;k<=n;k++)
				if(map[j][k]=='@'&&visited[j][k]==0) 
				{
					count++;
					dfs(j,k);			 
				}
		printf("%d\n",count);					 
	}
	return 0;
}
/*
1 1
*
3 5
*@*@*
**@**
*@*@*
1 8
@@****@*
5 5
****@
*@@*@
*@**@
@@@*@
@@**@
0 0
*/
