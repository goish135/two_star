#include<stdio.h>
#include<vector>
#include<iostream>
using namespace std;
int main()
{
	int tc;
	scanf("%d",&tc);
	while(tc--)
	{
		int len;
		vector<int> va;
		vector<int> vb;
		scanf("%d",&len);
		int a,b;
		for(int i=0;i<len;i++)
		{
			//cin>>va[i]>>vb[i];
			//cout<<va[i]<<" "<<vb[i]<<endl;
			scanf("%d %d",&a,&b);
			va.push_back(a);vb.push_back(b);
		}
		//cout<<"va.size():"<<va.size()<<" "<<"vb.size():"<<vb.size()<<endl; 
		//for(int j=0;j<va.size();j++)
		//cout<<va[j];
		//cout<<endl;
		vector<int> vc;
		for(int j=len-1;j>=0;j--)
		{
			int ans = va[j] + vb [j];
			vc.push_back(ans);
			//printf("%d\n",ans);
		}
		int flag = 0;
		for(int k=0;k<len;k++)
		{
			//cout<<vc[k]<<endl;
			if(vc[k]>=10)
			{
				if(k+1==len)
				{
				  	vc[k+1]=0;
				  	vc[k+1] = vc[k+1]+(vc[k]/10);
				  	flag = 1;
				}
				else
				vc[k+1] += vc[k]/10;
				vc[k]%=10;
				//cout<<vc[k+1]<<endl;
				//if(k+1==len) {flag=1;cout<<k+1<<" "<<vc[k+1]<<endl;} 
			}
			
		}
		if(flag == 0)
		{
			for(int m=len-1;m>=0;m--)
			cout<<vc[m];
		}
		else 
		{
			for(int m=len;m>=0;m--)
			 cout<<vc[m];
		}	
		if(tc!=0) cout<<endl<<endl;
		else cout<<endl;
	}	
	return 0;
} 
