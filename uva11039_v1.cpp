#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<vector>
using namespace std;

int main()
{
	int tc;
	scanf("%d",&tc);
	vector<int> red;
	vector<int> blue;
	while(tc--)
	{
		int total;
		scanf("%d",&total);
		int in;
		vector<int> mv;
		for(int i=0;i<total;i++)
		{
			scanf("%d",&in);
			if(in<0) red.push_back(abs(in));
			else blue.push_back(in);
			in = abs(in);
			mv.push_back(in);
		}
		int rsize = red.size();
		sort(red.begin(),red.end());
		int bsize = blue.size();
		sort(blue.begin(),blue.end());
		sort(mv,mv+total);
		int mark[total];
		// mark red and blue and record by mark
		for(int i=0;i<mv.size();i++)
		{
		    for(int j=0;j<red.size();j++)
		    {
		        if(mv[i]==red[j])
		        {
		            mark[i] = 1;
		            break;
		        }
		    }
		    for(int k=0;k<blue.size();k++)
		    {
		        if(mv[i]==blue[k])
		        {
		            mark[i] = 0;
		            break;
		        }
		    }
		}
		// for(int i=0;i<total;i++) printf("%d ",mark[i]);
		printf("\n");
		int ans = 0;
		int last = -1;
		for(int i=0;i<total;i++)
		{
		    if(mark[i]!=last)
		    {
		        ans++;
		        last = mark[i];
		    }
		}
		printf("%d\n",ans);
		red.clear();
		blue.clear();
	}
	return 0;	
} 