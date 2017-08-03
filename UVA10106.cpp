#include <stdio.h>
#include <string.h>
int main()
{
    char x[251], y[251];
    while(scanf("%s",&x)==1){
        scanf("%s",&y);
        char  t[251];
        int  Ans[502]={0};
        int xlen = strlen(x);
        int ylen = strlen(y);
        int i, j;
        strcpy(t, x);
        for(i = 0; i < xlen; i++)
            x[i] = t[xlen-i-1];
        strcpy(t, y);
        for(i = 0; i < ylen; i++)
            y[i] = t[ylen-i-1];
        for(i = 0; i < xlen; i++){
            for(j = 0; j < ylen; j++)
                Ans[i+j] += (x[i]-'0')*(y[j]-'0');
        }
        for(j = 0; j < 502; j++){
                if(Ans[j] >= 10){
                    Ans[j+1] += Ans[j]/10;
                    Ans[j] %= 10;
                }
        }        
        j = 501;
        while(Ans[j] == 0)  j--;
        if(j < 0)
            puts("0");
        else{
            for(j; j >= 0; j--)
                printf("%d", Ans[j]);
            puts("");
        }
    }
    return 0;
}
