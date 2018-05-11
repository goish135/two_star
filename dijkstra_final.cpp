#include <stdio.h>
#define max 1000

int main()
{
        int e[10][10],dis[10],book[10],i,j,n,m,t1,t2,t3,u,v,min;
        int inf=99999999; 
        
        scanf("%d %d",&n,&m);
		    
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                if(i==j) e[i][j]=0;
                  else e[i][j]=inf;

        for(i=1;i<=m;i++)
        {
            scanf("%d %d %d",&t1,&t2,&t3);
            e[t1][t2]=t3;
            //e[t2][t1]=t3;
        }
        
        for(i=1;i<=n;i++)
            dis[i]=e[1][i];
    
        for(i=1;i<=n;i++)
            book[i]=0;
        book[1]=1;
   		
   		int path[max];
   		for(int k=1;k<=n;k++)
   		{
   			if(e[1][k]!=inf)
			   path[k] = 1; // k的前一個節點為 1 (起始點)	
		}
   		
        for(i=1;i<=n-1;i++)
        {
            
            min=inf;
            for(j=1;j<=n;j++)
            {
                if(book[j]==0 && dis[j]<min)
                {
                    min=dis[j];
                    u=j;
                }
            }
            book[u]=1;
            
            int jj = 0 ; 
            for(v=1;v<=n;v++)
            {
                if(e[u][v]<inf)
                {
                	
                    if(dis[v]>dis[u]+e[u][v])
                    {
                        dis[v]=dis[u]+e[u][v];
                        path[v] = u ;
                    }
					      
                }
            }
        }
		
        for(i=1;i<=n;i++)
            printf("%d ",dis[i]);
        
		printf("\n");
		/*    
		for(int m=2;m<=n;m++)
		{
			printf("%d 's previous node:%d\n",m,path[m]);
		}
		*/
		//int p[max][max]; // case error : too big to explode
		int p[n+1][n+1];
		for(int i=1;i<n+1;i++)
		{
			for(int j=1;j<n+1;j++)
			{
				p[i][j] = -1;
			}
		}
		//final step
		for(int node=2;node<=n;node++)
		{
			//printf("node %d\n",node);
			int fg = 0;
			if(path[node]==1) 
			{
				//printf("1\n");
				//p[node][0]= 1;
				p[node][0]= 1;
				fg = 1;
			}
			int tp = node;
			int count = 0;
			while(path[tp]!=1)
			{
				//printf("%d->",path[tp]);
				p[node][count++] = path[tp];
				tp = path[tp];
				//p[node][count++] = path[tp]; 	
			}
			if(dis[node]!=inf)
			{
				if(fg==0)
					p[node][count++]=1; 
					//printf("1");
			}
			//printf("\n");		
		}
		
		
		for(int i=2;i<=n;i++)
		{
			for(int j=n;j>=0;j--)
			{
				if(p[i][j]!=-1)
					printf("%d ",p[i][j]);			
			}
			printf("%d",i);
			printf("\n");	
		}
				
        getchar();
        getchar();
        return 0;
}
