// uva 10340
#include<stdio.h>
#include<string>
#include<iostream>
int main()
{
	//freopen("10340.in.txt","r",stdin);
	//freopen("10340.out.txt","w",stdout);
	
	std::string str1;
	std::string str2;
	while(std::cin>>str1>>str2)
	{
		// std::cout<<str1<<" "<<str2<<'\n';
		int len1 = str1.length();
		
		// std::cout << len1 << '\n';
		
		
		int count = len1 ;
		int len2 = str2.length();
		// std::cout << len2 << '\n';
		
		int i;
		int pre = -1;
		for(i=0;i<len1;i++)
		{
			int flag = 0 ;
			for(int j=0;j<len2;j++)
			{
				// std::cout << str1[i] << "<>" << str2[j] << '\n';
				if(str1[i]==str2[j])
				{
					if(j>pre) 
					{ 
						pre = j;
						flag = 1 ;
						break;
					}
				}
			}
			if(flag==0)
			{
				printf("No\n");
				break;
			}
		}
		if(i==len1) printf("Yes\n");
	}
	return 0;
}
