#include <stdio.h>
#include <string.h>

const int MAXN = 85;

int main()
{
    int T;

    while(scanf("%d",&T) == 1 && T){
        char s[MAXN];
        for(int x=1;x<=T;x++){
            scanf("%s",s);
            int n = strlen(s);
            int o=0, result=0;
            for(int i=0;i<n;i++){
                if(s[i]=='O') 
                    o+=1;
                else
                    o = 0;
                result += o;
            }
            printf("%d\n",result);
        }
    }

}