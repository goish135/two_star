#include<stdio.h>
#include<string.h>
const int c = 131071; 
int main()
{
	char str[10000];
	char ch;
	int i = 0;
	while((ch=getchar())!=EOF)
	{
		if(ch=='#') 
		{
			//printf("%d\n",i);
			int alpha = 0;
			long long int dec=0;// 
			for(int k=i-1;k>=0;k--)
			{
				dec*=2;
				if(str[k]=='1')
				dec++;
				while(dec>=c) dec%=131071;
			}
			if(dec==0) printf("YES\n");
			else printf("NO\n");
			i = 0;
			getchar();	//eat '\n' //imp.
		}
		else
		{
			str[i]=ch;
			i++;
		}
		
	}
	return 0;	
} 