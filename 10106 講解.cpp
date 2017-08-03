#include <stdio.h>
#include <string.h>
int main()
{
    char x[251], y[251];
    while(scanf("%s",&x)==1){ //"==1" 直到 EOF 才會跳出迴圈  
        scanf("%s",&y);
        char  t[251]; // temp :暫存字串  
        int  Ans[502]={0}; // 一口氣"進位"運算 和 存最終答案 
        int xlen = strlen(x);
        int ylen = strlen(y);
        int i, j;
        strcpy(t, x); // 複製x存入t 
        for(i = 0; i < xlen; i++)
            x[i] = t[xlen-i-1];// 字串反轉  
        strcpy(t, y);
        for(i = 0; i < ylen; i++)
            y[i] = t[ylen-i-1];
        for(i = 0; i < xlen; i++){ // 乘法 
            for(j = 0; j < ylen; j++)
                Ans[i+j] += (x[i]-'0')*(y[j]-'0');
        }
        for(j = 0; j < 501; j++){ // 一口氣進位 
                if(Ans[j] >= 10){
                    Ans[j+1] += Ans[j]/10;// ps:陣列大小502 index max:501 => j<501  
                    Ans[j] %= 10;
                }
        }        
        j = 501;
        while(Ans[j] == 0)  j--; // pass 數字0
		 
        if(j < 0) // 運算結果是 0 輸出 0    
            puts("0");
        else{ //輸出 answer 
            for(j; j >= 0; j--)
                printf("%d", Ans[j]);
            puts("");
        }
    }
    return 0;
}
