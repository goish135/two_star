#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char ar[51][51]; 


int main()
{
	
	for(int i=0;i<51;i++)
	{
		for(int j=0;j<51;j++)
		{
			ar[i][j] = '0';
		}
	}

	int m,n;
	scanf("%d %d",&m,&n);
	int a,b;
	char d;
	char com[100+1];
	while(scanf("%d %d %c",&a,&b,&d)!=EOF) 
	{
		getchar();
		scanf("%s",&com);
	
		int len = strlen(com);

		int flag;
		for(int i=0;i<len;i++)
		{
		
			
			int ta,tb;
			char td;
			ta = a;
			tb = b;
			td = d;
			
			if(ar[a][b] == '1'&&com[i]=='F')
			{
				if(d=='N') 
				{
					if(b+1>n)
						continue;
				}
				else if(d=='S')
				{
					if(b-1<0)
						continue;
				}
				else if(d=='E')
				{
					if(a+1>m)
						continue;
				}
				else if(d=='W')
				{
					if(a-1<0)
						continue;
				}
			
			}
	
			if(d =='N')
			{
				if(com[i]=='L') d = 'W';
				else if (com[i]=='R') d = 'E';
				else if (com[i]=='F') b+=1;
			}
			else if(d =='S')
			{
				if(com[i]=='L') d = 'E'; 
				else if(com[i]=='R') d = 'W'; 
				else if(com[i]=='F') b-=1;
			}
			else if(d =='E')
			{
				if(com[i]=='L') d = 'N';
				else if(com[i]=='R') d = 'S';
				else if(com[i]=='F') a+=1;
			}
			else if(d =='W')
			{
				if(com[i]=='L') d = 'S';
				else if(com[i]=='R') d = 'N';
				else if(com[i]=='F') a-=1;
			}
			flag = 0;
			if(a>m||b>n||a<0||b<0) 
			{
				printf("%d %d %c LOST\n",ta,tb,td);
				ar[ta][tb] = '1' ;
				flag = 1;
				break;
			}
		
		}
		if(flag==0)
			printf("%d %d %c\n",a,b,d);
	}
	return 0;	
} 
