#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
const int MAX = 100000; // 題目says最大線段是10萬
typedef struct Seg //結構名稱 
{
	int left; //左端點
	int right; //右端點 
}seg;//結構變數名稱

seg sg[MAX],ans[MAX];//sg存input ans存output
seg cover; 
int ss;//seg's size
int ans_size(int m)
{
	int size = 0; // ans's size 
	while(1)
	{
	
		int max = -1 ; //找出最遠右端點的線段
		for(int i=0;i<ss;i++)
		{
			if(sg[i].left>cover.left||sg[i].right<=cover.left) //imp.
				continue;
			if(max==-1||sg[i].right>sg[max].right)
				max = i;	
		}
		if(max==-1) {
			size = 0;
			//cout<<"XD"<<endl;
		
			break;
		}
		//if(cover.left>=cover.right) return size;
		ans[size] = sg[max]; // 將結果存入
		//cout<<ans[size].left<<" "<<ans[size].right<<endl;
	    
		cover.left = sg[max].right;//update
		//cout<<"before:"<<size<<endl;
		size++;	
		//cout<<"after:"<<size<<endl;
	
		if(cover.left>=cover.right) return size;
	}
	return size;	
}  
int main()
{
	int tc;
	scanf("%d",&tc);
	while(tc--)
	{
		int m; // [0,m]
		//scanf("%d",&m);
		cin>>m;
		cover = {0,m};
		ss=0;
		while(cin>>sg[ss].left>>sg[ss].right)
		{
			if(sg[ss].left==0 && sg[ss].right==0) break;
			//cout<<sg[ss].left<<" "<<sg[ss].right<<endl;
			ss++;
			/*cout << ans_size(m) <<endl; //int ans_size(int m):回傳最小線段數
			for(int i=0;i<ans_size(m);i++)
			{
				cout<<ans[i].left<<" "<<ans.right;	
			} */
			
		}
		int test = ans_size(m);
		cout << test <<endl; //int ans_size(int m):回傳最小線段數
		
		//cout << "$$" << test <<endl;
		for(int i=0;i<test;i++)
		{
				cout<<ans[i].left<<" "<<ans[i].right<<endl;
				//cout<<"hi~"<<endl;	
		} 
		if(tc!=0) cout<<endl; //format
	}
	return 0;
}
/*size(int m)
{
	int size = 0; // ans's size 
	while(1)
	{
	
		int max = -1 ; //找出最遠右端點的線段
		for(int i=0;i<ss;i++)
		{
			if(sg[i].left>cover.left||sg[i].right<cover.left) 
				continue
			if(max==-1||sg[i].right>sg[max].right)
				max = i;	
		}
		if(max==-1) break;
		if(seg[max].left>=seg[max].right) return size;
		ans[size] = seg[max]; // 將結果存入	
	}
	return 0;	
} */ 
 
