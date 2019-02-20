// uva 11396 Claw Decomposition //
#include<stdio.h>
#include<vector>
using namespace std;
vector<int> graph[301];
int record[301];
int flag;
void dfs(int x)
{
	if(record[x]!=0) // 已塗色 
	{
		for(int i=0;i<graph[x].size();i++)
		{
			if(record[graph[x][i]]*record[x]==1)
			{
				flag = 0;
				//break;
				return;
			}
			else if(record[graph[x][i]]==0)
			{
				record[graph[x][i]]=record[x]*(-1);
				dfs(graph[x][i]);
			}
		}
		//return;
	}
	else // 未塗色 在其相鄰邊 上不同色 
	{
		record[x] = 1;
		for(int i=0;i<graph[x].size();i++)
		{
			record[graph[x][i]] = record[x]*(-1);
			dfs(graph[x][i]);
		}
	}
}

int main()
{
	//freopen("11396in.txt","r",stdin);
	//freopen("11396out.txt","w",stdout); 
	int n;

	while(scanf("%d",&n)==1)
	{
		flag = 1;
		if(n==0) break;
		int p1,p2;
		for(int i=1;i<=n;i++)
		{
			record[i]=0;
			graph[i].clear();
		}
		while(scanf("%d %d",&p1,&p2)==2)
		{
			if(p1==0&&p2==0) break;
			graph[p1].push_back(p2);
			graph[p2].push_back(p1);
		}

		
		for(int i=1;i<=n;i++)
		{
			dfs(i);
		}
		if(flag) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
