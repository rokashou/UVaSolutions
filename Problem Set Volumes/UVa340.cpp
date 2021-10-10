// 340: Master-Mind Hints

#include <stdio.h>

#define MAXN 1010

int main(){
    int n, question[MAXN], answer[MAXN];
    int kase = 0;
    while(scanf("%d",&n) == 1 && n){
        printf("Game %d:\n", ++kase);
        for(int i=0;i<n;i++)
            scanf("%d", &question[i]);
        while(1){
            int A = 0, B = 0;
            for(int i = 0;i<n;i++){
                scanf("%d", &answer[i]);
                if(question[i]==answer[i]) A++;
            }
            if(answer[0]==0) break; // if there is a 0, it is STOP
            for(int num=1;num<=9;num++){
                int countQuestion = 0, countAnswer = 0; // for checking how many times *num* appears in *question* and *answer* array.
                for(int i=0;i<n;i++){
                    if(question[i]==num) countQuestion++;
                    if(answer[i]==num) countAnswer++;
                }
                if(countQuestion < countAnswer) 
                    B+=countQuestion;
                else
                    B+=countAnswer;
            }
            printf("    (%d,%d)\n",A,B-A);
        }
    }

    return 0;
}
