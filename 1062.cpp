// uva 1062
/*
A
CBACBACBACBACBA
CCCCBBBBAAAA
ACMICPC
end
*/
#include<stdio.h>
#include<iostream>
#include<vector>
#include<string>
#include<string.h>

#define max 1000
int A[max][max];
int len[max];

int main()
{
	// std::vector< std::vector<int> > V;
	// freopen("1062.in.txt","r",stdin);
	// freopen("1062.out.txt","w",stdout);
	
	std::string str;
	int ce = 1; 
	while(std::cin>>str && str!="end")
	{
		memset(A,0,sizeof(A));
		memset(len,0,sizeof(len));
		
		// std::cout<<str<<'\n';
		//std::cout << "len: " << str.length() <<'\n';
		int cnt=0;
		int ct =0;
		for(int i=0;i<str.length();i++)
		{
			int num;
			num = str[i];
			
			//printf("ASCII: %d\n",num);
			
			if(cnt==0)
			{
				// V[cnt++].push_back(num);
				//V[cnt++][ct++] = num;
				//V[0].push_back(num);
				A[cnt][ct] = num;
				
				//printf("len0:%d\n",A[i][len[i]]);
				len[cnt] = len[cnt] + 1;
				
				cnt++;
				// ct++; 
				
				// len[cnt] = ct;
				//cnt++;
				//ct++;
			}
			// printf("%d %d\n",cnt,ct);
			
			
			else
			{
				int flag = 0 ;
				for(int i=0;i<cnt;i++) // cnt : number of stack
				{
					//for(int j=0;j<ct;j++)
					//printf("pre:%d\n",len[i]-1);
					//printf("test:%d\n",A[i][len[i]-1]);
					
					if(num <= A[i][len[i]-1])
					{
						
						
						A[i][len[i]] = num;
						
						//printf("len1:%d\n",A[i][len[i]]);
						
						len[i] = len[i]+1;
						flag = 1 ;
						break;
					}	
				}
				if(flag==0)
				{
					A[cnt][len[cnt]] = num; 
					
					//printf("len2:%d\n",A[cnt][len[cnt]]);
					
					len[cnt] = len[cnt] + 1;
					cnt = cnt + 1; 	
				}	
			}
			
			
			/*
			else
			{
				for(int i=0;i<V.size();i++)
				{
					int len = V[i].size();
					std::cout << "len:" << len <<'\n';
					 
					if(str[i]<V[i][len-1])
					{
						V[i].push_back(str[i]);
					}	
					else
					{
						V[++cnt].push_back(str[i]); 
					}
						
				}
			}
			*/
		}
		printf("Case %d: %d\n",ce,cnt);
		ce++;
	}		
	return 0;
}
