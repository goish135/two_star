// uva 101
#include<iostream>
#include<stdio.h>
#include<string>
#include<stdlib.h>
 
int stack[25][25];
int top[25];
int loc[25];
int n;

void clear(int ab)
{
	int id = loc[ab];
	
	while(stack[id][top[id]]!=ab)
	{
		int val =stack[id][top[id]--]; // get value
		stack[val][++top[val]] = val;  // return original
		loc[val] = val ;             // record location stack 
	
	}
}

void pile(int a,int b) // pile a to b
{

	int id = loc[a];
	int ID = loc[b];
	int temp[25];
	int ct = -1 ;
	while(stack[id][top[id]]!=a)
	{
		temp[++ct] = stack[id][top[id]--];
	}
	
	loc[a]=ID;
	stack[ID][++top[ID]] = a;
	top[id]--;
	
	
	while(ct>=0)
	{
		loc[temp[ct]] = ID ;
		stack[ID][++top[ID]] = temp[ct--];
	}
}

int main()
{

	
	while(scanf("%d",&n)==1)
	{
		std::string v1,v2;
		int o1,o2;
		for(int i=0;i<n;i++)
		{
			
					stack[i][0] = i ;
					loc[i] = i ; 
					top[i] = 0 ; 
				
		}

		while(std::cin>>v1&&v1!="quit")
		{		
			std::cin>>o1>>v2>>o2;
			if(loc[o1] == loc[o2]) continue;
				
			if(v1=="move")
			{
				clear(o1);
			}
			if(v2=="onto")
			{
				clear(o2);
			}
		
			pile(o1,o2);
				
		}
		
		// output
		for(int i=0;i<n;i++)
		{	
			printf("%d:",i);
			for(int j=0;j<=top[i];j++)
			{ 
				std::cout <<" "<< stack[i][j];
			}
			printf("\n");	
		}
		
	}
	return 0;
}






