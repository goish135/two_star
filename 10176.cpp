//ps:��J���G�i��ơA�̪��F10000��ơA�����Q�i���(�z��:�W�L�ܼƽd��) => �P�l 
//�G�i���ഫ���Q�i�쪺�L�{ �A�ϥ�"�P�l"�A�p��l�ơC
//�Y�̫᪺�l�Ƭ�0,��ܥi�H�㰣 
// �����D:uva11344 => '�W�j��'�Ʀr �O�_ �Q�C�|�X���Ʀrs �㰣 �O=>Wonderful ���O=>Simple
//���P�B:uva10176 �h�@���ഫ(10->2) 
#include<stdio.h>
const int prime = 131071;
int main()
{
	char ch;
	int temp=0;
	while((ch=getchar())!=EOF)
	{
		if(ch=='1'||ch=='0') //�קK�Y���L���r��(ex:�ť�) 
		{
			temp = ((temp*2)+(ch-'0'))%prime;//�P�l���� 
		}
		
		if(ch=='#')//��X���G 
		{
			if(temp==0) printf("YES\n");
			else printf("NO\n");
			temp = 0; //�k�s 
		}
	}
	return 0;
} 
