// uva 1200
// A DP Problem
#include<stdio.h> 
#include<math.h>
#include<string.h>
// #include<stdlib.h>
void parse(char* s,int& o,int& p)  // m: «Y¼Æ a c  // n: ±`¼Æ  b d
{
  o =0 , p = 0;
  int len = strlen(s);
  //printf("%d %d\n",m,n);
  //printf("len: %d\n",len);
  // + - x
  int pre = 1;
  int v   = 0;
  int flag = 0;
  for(int i=0;i<len;i++)
  {
    //printf("%c\n",s[i]);
    
    if(s[i]=='x')
    {
      
      if(flag)
      {
        o+= (pre*v);
        //printf("test\n");  
      }
      else  // 1x case
      {
        //printf("m: %d\n",m);
        o+=pre;
        //printf("pre : %d\n",pre);
        //printf("1x: %d\n",m);
      }
      pre = 1;
      v = 0;  
      flag = 0;
      //printf("f:%d\n",flag);
    } 
    else
    {
      if(s[i]=='+') 
      {
        if(flag) // notice
          p+= pre*v;
        pre = 1;
        v = 0;
        flag = 0;
      }
      else if(s[i]=='-')
      {
        if(flag) // notice
          p += pre*v;
        pre = -1;
        v = 0;
        flag = 0;
      }
      else
      {
        v = v*10 + s[i]-'0';
        //printf("v: %d\n",v);
        flag = 1;  
      }
      
    }
  } 
  if(flag==1)
  {
    //printf("n: %d\n",n);
    //printf("v: %d\n",v);
    //printf("XD\n");
    //printf("> %d %d\n",p,v);
    p += v*pre; // notice
  }
  //printf(">> %d %d\n",o,p);  
}

int main()
{
  //freopen("B.txt","r",stdin);
  int n;
  scanf("%d",&n);
  getchar(); // eat '\n'
  char sign='+';
  int value=0;

  int a=0,b=0,c=0,d=0; // ans = (d-b) / (a-c)
  // char ch;
  char A[1000];
  char s1[1000],s2[1000];  
  while(n--)
  {
    gets(A);
    int len = strlen(A);
    int position ;
    for(int i=0;i<len;i++)
    {
      if(A[i]=='=') 
      {
        position = i;  
      }      
    }
    //printf("position: %d\n",position);
    for(int j=0;j<position;j++)
    {
      s1[j] = A[j];
      //printf("j: %d\n",j);
      //printf("%c",s1[j]);  
    }
    
    s1[position] = '\0'; // imp.
    
    //printf("\n");
    int lenTwo=0;
    for(int j=position+1;j<len;j++) // imp.
    {
      s2[lenTwo] = A[j];
      //printf("%d %c\n",j,A[j]);
      //printf("%c",s2[lenTwo]);
      //printf("two:%d\n",lenTwo);
      lenTwo++;  
    }
    s2[lenTwo]='\0';
    //printf("lenTwo: %d\n",lenTwo); 
    //printf("\n");
    //s2[lenTwo]='\0';
    //int len_1=strlen(s1);
    //printf("s1: %d\n",len_1);
    // two sides
    //int la,lb,ra,rb;
    parse(s1,a,b); // calculate a,b
    parse(s2,c,d); // calculate c,d
    
    
    if(a==c&&b!=d)
    {
      printf("IMPOSSIBLE\n"); 
    }
    else if(a==c&&b==d)
    {
      printf("IDENTITY\n");
    }
    else 
    {
      double ans = (double) (d-b)/(a-c);
      //printf("ans: %lf\n",ans); 
      int real_ans = floor(ans);
      printf("%d\n",real_ans);
    }
  }
  return 0;
}
