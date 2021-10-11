#include<stdio.h>
#include<string.h>
// #include<time.h>
const int MAXN = 85;

int main(){
    //freopen("data.in","r",stdin);
    //freopen("data.out","w",stdout);

    char input[MAXN];

    int T;
    while(scanf("%d",&T) == 1 && T){
        //scanf("%s",temp1);
        int count=0;
        while(count < T){
            scanf("%s",input);

            int length = strlen(input);
            int step=1;
            while(input[0] != input[step] && step < length) step++;
            bool flag = true;

            while(flag){
                if(length % step != 0){
                    step++;
                    continue;
                }

                int loop = length/step;

                for(int i=1;flag && i<loop;i++){
                    for(int j=0;flag && j<step;j++){
                        if(input[j] != input[step*i+j]) {
                            flag = false;
                        }
                    }
                }

                if(!flag){
                    flag=true;
                    step++;
                }else{
                    if(count) printf("\n");
                    printf("%d\n",step);
                    count ++;
                    break;
                }

            }
        }

    }

    // printf("\nTime used = %.2f\n",(double)clock() / CLOCKS_PER_SEC);

    return 0;
}

