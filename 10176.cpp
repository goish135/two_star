//ps:块秈计程笷10000计传Θ秈计(脄奔:禬筁跑计絛瞅) => 緇 
//秈锣传秈筁祘 ㄏノ"緇"璸衡緇计
//璝程緇计0,ボ俱埃 
// 摸肈:uva11344 => '禬'计 琌 砆羭计s 俱埃 琌=>Wonderful ぃ琌=>Simple
//ぃ矪:uva10176 锣传(10->2) 
#include<stdio.h>
const int prime = 131071;
int main()
{
	char ch;
	int temp=0;
	while((ch=getchar())!=EOF)
	{
		if(ch=='1'||ch=='0') //磷ㄤじ(ex:フ) 
		{
			temp = ((temp*2)+(ch-'0'))%prime;//緇场だ 
		}
		
		if(ch=='#')//块挡狦 
		{
			if(temp==0) printf("YES\n");
			else printf("NO\n");
			temp = 0; //耴箂 
		}
	}
	return 0;
} 
