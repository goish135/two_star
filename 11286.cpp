#include<stdio.h>
//#include<string>
//#include <cstring>
#include<map>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int fm;//freshman
	int c[5];//class
	char s[100];//
	while(scanf("%d",&fm))
	{
		if(fm==0) break;
		map<string,int> myMap;
		int ss;
		//while(fm--)
	    for(int k = 0; k < fm; k++)
		{
			//cin>>c[0]>>c[1]>>c[2]>>c[3]>>c[4];//five class
			for(int j = 0; j < 5; j++)
                scanf("%d", &c[j]);
			sort(c,c+5);
			sprintf(s,"%d%d%d%d%d",c[0],c[1],c[2],c[3],c[4]);
			myMap[s]++;
		}//for k//O
		//一組測資輸入完 //
			ss = 0;//set sum
			int max = 0;
			//做一次性的排序 
			for(map<string,int>::iterator i = myMap.begin();i!=myMap.end();i++)
			{
				if(i->second>max) 
				{
					max = i->second;
					ss=0;
				}
				if(i->second==max)
				{
					ss+=max;
				}
			}
			//cout<<ss<<endl;
		//}//for k //括錯地方//X 
		//cout<<ss<<endl;
		printf("%d\n",ss);
	}
	return 0;	
} 
