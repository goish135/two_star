// uva 12347
#include<stdio.h>
#include<iostream>

struct node{
	int value;
	node *left = NULL;
	node *right = NULL;
};

node *root = NULL; // Creating an empty tree

void build(int num)
{
	node *cur_node = root ; // imp. // ex: root = new node()
	node *par = NULL;
	 
	if(cur_node==NULL)
	{
		root = new node(); // root = new(node); // add new node // imp.
		root->value = num;
	}
	else
	{
		while(cur_node!=NULL) // find new node's parent (previous node)
		{
			if(cur_node->value<num) 
			{
				par = cur_node;
				cur_node = cur_node->right;
			}
			else
			{
				par = cur_node;
				cur_node = cur_node->left;
			}
		}	
	
	
	    node *newnode = new node(); // insert one new node 
	 	newnode->value = num; // 
	 	
		if(par->value<num)
		{	
			par->right = newnode;	 
		}
		else
		{
			par->left = newnode;
		}
	}
}

void postorder(node *cur)
{
	if(cur==NULL) return; // leaf node
	postorder(cur->left);  
	postorder(cur->right);
	std::cout << cur->value << '\n'; 
}

int main()
{
	freopen("12347.in.txt","r",stdin);
	freopen("12347.out.txt","w",stdout);
	
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		build(n);
	}
	postorder(root);
	return 0;
}
