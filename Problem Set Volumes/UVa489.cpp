#include<stdio.h>
#include<string.h>
#define maxn 100
int left,chance;
char question[maxn],answer[maxn];
int win,lose;

void guess(char ch){
    int bad = 1;
    for(int i=0;i<strlen(question); i++){
        if(question[i]==ch) { 
            left-=1; 
            question[i]=' ';
            bad=0;
        }
    }
    if(bad) chance-=1;
    if(!chance) lose = 1;
    if(!left) win = 1;
}

int main(){

    int rnd=0;
    while(scanf("%d%s%s",&rnd,question,answer) == 3 && rnd != -1){
        printf("Round %d\n",rnd);
        win = 0; lose = 0;
        left = strlen(question);
        chance = 7;
        for(int i=0;i<strlen(answer);i++){
            guess(answer[i]);
            if(win || lose) break;
        }
        
        // output the result
        if(win) printf("You win.\n");
        else if(lose) printf("You lose.\n");
        else printf("You chickened out.\n");
    }

    return 0;
}
