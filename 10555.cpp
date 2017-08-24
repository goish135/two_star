#include<iostream>
#include<string>
#include<climits>
#include<stdlib.h>
#include<math.h>
using namespace std;
int GCD(int a,int b)
{
	while(b!=0)
	{
		int r = a%b;
		a = b;
		b = r;
	}
	return a;
}
int main()
{
	string s;
	while(cin>>s&&s!="0")
	{
		s=s.substr(0,s.size()-3).substr(2);//delete ... then delete 0.
		int u,dd=INT_MAX,d,uu;
		int n = s.size();
		for(int i=1;i<=s.size();i++)//cycle len
		{
			u = atoi(s.c_str())-atoi(s.substr(0,n-i).c_str());
			d = pow(10,n)-pow(10,n-i);
			int g = GCD(u,d);
			u = u/g;
			d = d/g;
			if(d<dd) {dd = d;uu = u;}
		}	 
		cout<<uu<<"/"<<dd<<endl;
	}
	return 0;
}			
		
