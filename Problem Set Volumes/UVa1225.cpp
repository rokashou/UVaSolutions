#include <stdio.h>
#include <string.h>

const int MAXN = 10005;
int main()
{
    int i=1;
    int number[10005][10];

    for(int i=0;i<10;i++){
        number[0][i]=0;
    }
    i=0;
    
    while(i<MAXN)
    {
        i++;
        memcpy(number[i],number[i-1],sizeof(number[i]));
        int k=i;
        while(k>0){
            number[i][k % 10]++;
            k /= 10;
        }
    }

    int T;
    while(scanf("%d",&T) == 1 && T){
        for(int i = 0;i<T;i++){
            int n;
            scanf("%d",&n);

            for(int j=0;j<9;j++){
                printf("%d ",number[n][j]);
            }
            printf("%d\n",number[n][9]);
        }
    }

}