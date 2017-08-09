#include<stdio.h>
#include<iostream>
#include<ctype.h>
#include<string>
using namespace std;
int main()
{
	int n,m;
	string input;
	//string output="";
	//string ans = "";
	int run = 1;
	while(scanf("%d",&n)!=EOF&&n!=0)
	{
	string output="";
	string ans="";
	getchar();//eat '\n' //ex:2\n
	for(int i=0;i<n;i++)
	{
		getline(cin,input);
		if(i==0)
		{
			ans = input;
		}
		else
		{
			ans = ans + '\n';
			ans = ans + input;
		}
	}
	scanf("%d",&m);
	getchar();
	for(int j=0;j<m;j++)
	{
		getline(cin,input);
		if(j==0)
		{
			output = input ;//
		}
		else 
		{
			output = output+'\n';
			output = output+input;
		}
	}
	bool ac = true;
	if(ans!=output) ac = false;
	if(ac==true)
	{printf("Run #%d: Accepted\n",run++);continue;}
	bool pe = true;
	for(int i=0;i<ans.length();i++)//
	{
		if(isdigit(ans[i])==false)
		{
			ans.erase(i,1);//
			i--;
		}
	}
	for(int j=0;j<output.length();j++)//
	{
		if(isdigit(output[j])==false)
		{
			output.erase(j,1);//
			j--;
		}
	}
	if(ans!=output) pe = false;
	if(pe==true) {printf("Run #%d: Presentation Error\n",run++);continue;}//
	printf("Run #%d: Wrong Answer\n",run++);//
		
	}	
return 0;
}
