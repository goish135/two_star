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
		    
		for(int m=2;m<=n;m++)
		{
			printf("%d 's previous node:%d\n",m,path[m]);
		}
				
        getchar();
        getchar();
        return 0;
}
