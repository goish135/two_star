#include <stdio.h>
#include <string.h>
int main()
{
    char x[251], y[251];
    while(scanf("%s",&x)==1){ //"==1" ���� EOF �~�|���X�j��  
        scanf("%s",&y);
        char  t[251]; // temp :�Ȧs�r��  
        int  Ans[502]={0}; // �@�f��"�i��"�B�� �M �s�̲׵��� 
        int xlen = strlen(x);
        int ylen = strlen(y);
        int i, j;
        strcpy(t, x); // �ƻsx�s�Jt 
        for(i = 0; i < xlen; i++)
            x[i] = t[xlen-i-1];// �r�����  
        strcpy(t, y);
        for(i = 0; i < ylen; i++)
            y[i] = t[ylen-i-1];
        for(i = 0; i < xlen; i++){ // ���k 
            for(j = 0; j < ylen; j++)
                Ans[i+j] += (x[i]-'0')*(y[j]-'0');
        }
        for(j = 0; j < 501; j++){ // �@�f��i�� 
                if(Ans[j] >= 10){
                    Ans[j+1] += Ans[j]/10;// ps:�}�C�j�p502 index max:501 => j<501  
                    Ans[j] %= 10;
                }
        }        
        j = 501;
        while(Ans[j] == 0)  j--; // pass �Ʀr0
		 
        if(j < 0) // �B�⵲�G�O 0 ��X 0    
            puts("0");
        else{ //��X answer 
            for(j; j >= 0; j--)
                printf("%d", Ans[j]);
            puts("");
        }
    }
    return 0;
}
