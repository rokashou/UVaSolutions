#include <stdio.h>
#include <string.h>

const int MAXN = 85;

const double MOLAR[4]={12.01,1.008,16.0,14.01};

int main(){
    //freopen("data.in","r",stdin);
    //freopen("data.out","w",stdout);

    int T;
    char s[MAXN];
    while(scanf("%d",&T)==1 && T){
        while(T--){
            scanf("%s",s);
            int n = strlen(s);
            double result = 0.0;
            int times = 1;
            double baseMolar=0;
            bool lastIsAlpha = true;

            for(int i=0;i<n;i++){
                switch(s[i]){
                    case 'C':
                        result += baseMolar * times;
                        baseMolar = MOLAR[0];

                        times = 1;
                        lastIsAlpha = true;

                        break;
                    case 'H':
                        result += baseMolar * times;
                        baseMolar = MOLAR[1];
                        times = 1;
                        lastIsAlpha = true;
                        break;
                    case 'O':
                        result += baseMolar * times;
                        baseMolar = MOLAR[2];
                        times = 1;
                        lastIsAlpha = true;
                        break;
                    case 'N':
                        result += baseMolar * times;
                        baseMolar = MOLAR[3];
                        times = 1;
                        lastIsAlpha = true;
                        break;
                    default:
                        if(lastIsAlpha) {
                            times = 0;
                            lastIsAlpha = false;
                        }
                        times = times * 10 + (s[i] - '0');
                }
            } 
            result += baseMolar * times;
            
            printf("%.3f\n",result);
        }
    }

    return 0;
}