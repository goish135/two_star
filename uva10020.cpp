#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
const int MAX = 100000; // �D��says�̤j�u�q�O10�U
typedef struct Seg //���c�W�� 
{
	int left; //�����I
	int right; //�k���I 
}seg;//���c�ܼƦW��

seg sg[MAX],ans[MAX];//sg�sinput ans�soutput
seg cover; 
int ss;//seg's size
int ans_size(int m)
{
	int size = 0; // ans's size 
	while(1)
	{
	
		int max = -1 ; //��X�̻��k���I���u�q
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
		ans[size] = sg[max]; // �N���G�s�J
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
			/*cout << ans_size(m) <<endl; //int ans_size(int m):�^�ǳ̤p�u�q��
			for(int i=0;i<ans_size(m);i++)
			{
				cout<<ans[i].left<<" "<<ans.right;	
			} */
			
		}
		int test = ans_size(m);
		cout << test <<endl; //int ans_size(int m):�^�ǳ̤p�u�q��
		
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
	
		int max = -1 ; //��X�̻��k���I���u�q
		for(int i=0;i<ss;i++)
		{
			if(sg[i].left>cover.left||sg[i].right<cover.left) 
				continue
			if(max==-1||sg[i].right>sg[max].right)
				max = i;	
		}
		if(max==-1) break;
		if(seg[max].left>=seg[max].right) return size;
		ans[size] = seg[max]; // �N���G�s�J	
	}
	return 0;	
} */ 
 
