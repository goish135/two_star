//�ϥ�Java���ҥͽЪ`�N�A�̥~�h�����O(class)�ݩR�W�� main �C
//�p�G�J��W�G�Q�������p�A�Ч��sĶ���լݬ�!! �U�sĶ���S�ʤ��P!!
//�w�]����B�H������B�T�w����O�Ψ����U�����Ϊ��C���ɡA�u�ݷt������O�_�q�L!!
// uva 993
#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		int in;
		scanf("%d",&in);
		int ans[1000];
		
		int key = 0;
		if(in>=0&&in<=9)
		{
			printf("%d\n",in);
			key = 1;	
		}
		
		int cnt = 0;
		
		while(key!=1)
		{
			
			int i;
			int flag = 0;
			for(i=9;i>=2;i--)
			{
				if(in%i==0)
				{
					//printf("i: %d\n",i);
					ans[cnt] = i ;
					cnt++; 
					in = in / i ;
				
					if(in==1) 
					{
						//printf("");
						for(int k=cnt-1;k>=0;k--)
						{
							printf("%d",ans[k]);
						}
						printf("\n");
						flag = 1;
						break; 
					}
					break;
				}
			}
			if(i==1&&flag==0) 
			{
				printf("-1\n");
				break;
			}
			if(flag==1) break; 
		}
	}
	return 0;	
} 
