#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;
int main()
{
	int in;
	while(cin>>in&&in!=0)
	{
		vector<int> myV;
		myV.push_back(in);
		while(cin>>in&&in!=0) myV.push_back(in);
		int gcd = 0;
		for(int i=1;i<myV.size();i++)
		{
			int dif = abs(myV[i]-myV[0]);
			if(gcd==0) gcd = dif; // set (myV[1]-myV[0]) gcd
			else while(dif%=gcd) swap(dif,gcd); //gcd
		}
		cout << gcd << endl;
	}
	return 0;
}	
/*
701 1059 1417 2312 0
14 23 17 32 122 0
14 -22 17 -31 -124 0
0
*/	
