//�ϥ�Java���ҥͽЪ`�N�A�̥~�h�����O(class)�ݩR�W�� main �C
//�p�G�J��W�G�Q�������p�A�Ч��sĶ���լݬ�!! �U�sĶ���S�ʤ��P!!
//�w�]����B�H������B�T�w����O�Ψ����U�����Ϊ��C���ɡA�u�ݷt������O�_�q�L!!
// uva10142
#include<stdio.h>
#include<string.h> //strcmp strtok
#include<stdlib.h> //atoi
int main()
{
	//freopen("����_10142.txt","r",stdin); // smart method
	
	int n; // case
	int c; // candidate
	char can[20+1][80+1];   // name
	//int  vot[1000+1][20+1]; // ballot
	
	scanf("%d",&n);
	//int print = 0;
	while(n--){
		scanf("%d",&c);
		getchar(); // eat \n ,otherwise gets() will eat it
		for(int i=0;i<c;i++)
		{
			//scanf("%s",&can[i]);
			gets(can[i]);
			//printf("print:%s\n",can[i]);
		}
	//}
	
	int p=0; // �벼�H�� 
	char A[1000];
	int  vot[1000+1][20+1];
	
	for(int i=0;i<1001;i++)
	{
		for(int j=0;j<21;j++)
		{
			vot[i][j]=0;
		}
	}
	
	while(gets(A))
	{
		if(strcmp(A,"")==0) // the same
		{
			break;
		}

		char *token;
		token=strtok(A," ");
		int j=0;
		while(token!=NULL)
		{
			//printf("XD\n");
			int temp = atoi(token);
			//printf("%d\n",temp);
			vot[p][j++]=temp;
			token=strtok(NULL," ");
		}
		p++;
	}
	
	/*for(int i=0;i<p;i++)
	{
		for(int j=0;j<c;j++)
		{
			printf("%d ",vot[i][j]);		
		}
		printf("OK\n"); 
	}*/
	
	int sum[20+1]; // save candidate's ballot number // �έp�C��Կ�H������
	for(int i=0;i<21;i++)
	{
		sum[i] = 0;
	}
	int elimate[20+1]; // �����ֳQ�^�O 1:�^�O 0:�S�Q�^�O
	for(int i=0;i<21;i++)
	{
		elimate[i] = 0;
	}
	int max=0,min=1000;
	
	int result = 0;
	
	while(result==0)
	{
		//printf("loop\n");
		
		for(int i=0;i<p;i++)
		{
			int j=0;
			while(elimate[vot[i][j]]==1)
			{
				j++;
			}
			sum[vot[i][j]]++;
			//printf("vote for: %d\n",vot[i][j]);
		}
		// �C�ӤH�����ƬҲέp�n
		
		max = 0 , min = 1000;
		//int whoa,whob;
		for(int i=1;i<=c;i++)
		{
			if(elimate[i]==0)
			{
				//printf("in: %s\n",can[i-1]);
				if(sum[i]>max)
				{
					max  = sum[i];
					//whoa = i ; 	
				}
				if(sum[i]<min)
				{
					min  = sum[i];
					//whob = i;
				}
			}
		}
		// ��X�̰��� �̧C��
		//printf("max: %d\n",max);
		//printf("min: %d\n",min);
		
		for(int i=1;i<=c;i++)
		{
			if(max==sum[i])
			{
				if(max+max>p) // good method
				{
					//printf("test\n");
					//printf("%d %d\n",max,p);
					
					printf("%s\n",can[i-1]);
					result = 1 ;	
				} 
			}
			if(min==sum[i])
			{
				//printf("bye: %s\n",can[i-1]);
				elimate[i] = 1;	
			}		
		}
		if(result==1) break;
		if(max==min)
		{
			//printf("Hi\n");
			for(int i=1;i<=c;i++)
			{
				if(sum[i]==max)
				{
					result = 1;
					printf("%s\n",can[i-1]);
				} 	
			}
			//if(result==1) break;	
		} 
		
		if(result==0)
		{
			for(int i=1;i<=c;i++)
			{
				sum[i] = 0;	
			}	
		}			
	}
	if(n>0) printf("\n");

	//print = 1;
	/*for(int i=1;i<=c;i++)
	{
		printf("%d %d\n",i,sum[i]);
	}*/
	 
	}
	return 0;  
 } 
