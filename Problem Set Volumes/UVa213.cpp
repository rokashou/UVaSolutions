#include <stdio.h>
#include <string.h>

int readchar(){
    while(true){
        int ch = getchar();
        if(ch != '\n' && ch != '\r') return ch;
    }
}

int readint(int c){
    int v = 0;
    while(c--) v=v*2+readchar()-'0';
    return v;
}

int code[8][1<<8];

int readcodes(){
    memset(code,0,sizeof(code));
    code[1][0]=readchar();
    for(int len = 2; len <= 7; len++){
        for(int i=0;i<(1<<len)-1;i++){
            int ch = getchar();
            if(ch == EOF) return 0;
            if(ch == '\n' || ch == '\r') return 1;
            code[len][i]=ch;
        }
    }
    return 1;
}

void printcodes(){
    for(int len = 0; len <= 7; len++){
        for(int i = 0; i < (1<<len)-1;i++){
            if(code[len][i] == 0) return;
            printf("code[%d][%d] = %c\n",len,i,code[len][i]);
        }
    }
}

int main(){
    while(readcodes()){
        // printcodes();
        for(;;){
            int len = readint(3);
            if(len == 0) break;
            //printf("len=%d\n",len);
            for(;;){
                int v = readint(len);
                //printf("v=%d\n",v);
                if(v==(1<<len)-1) break;
                putchar(code[len][v]);
            }
        }
        putchar('\n');
    }
    return 0;
}