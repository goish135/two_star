#include<stdio.h>
#include<iostream>
#include<map>
#include<string>
using namespace std;
int main()
{
	map<string,int> Mymap;
	int item,tc;
	scanf("%d %d",&item,&tc);
	string word;
	int price;
	while(item--)
	{
		cin >> word >> price;
		Mymap[word] = price ;
	}	
	
	string input; 
	while(tc--)
	{
		int sum = 0;
		while(cin>>input && input[0]!='.')
		{
			if(Mymap[input]>0) sum = sum + Mymap[input];
		}
		cout << sum << endl;
	}
	return 0;	
}	
