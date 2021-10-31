#include<stdio.h>
#include<stdlib.h>
#include<string.h>

const int CHARACTER_MAX = 26;
const int MAX_INPUT_LENGTH = 105;

int cnt1[CHARACTER_MAX];
int cnt2[CHARACTER_MAX];

char input1[MAX_INPUT_LENGTH];
char input2[MAX_INPUT_LENGTH];

int cmp(const void *a, const void *b){
    return *(int *)a - *(int *)b;
}

void CleanTable(){
    memset(cnt1,0,sizeof(cnt1));
    memset(cnt2,0,sizeof(cnt2));
    memset(input1,0,sizeof(input1));
    memset(input2,0,sizeof(input2));
}

void ScanInputAndCount(){
    int len = strlen(input1);
    for(int i=0;i<len;i++){
        cnt1[input1[i]-'A']+=1;
        cnt2[input2[i]-'A']+=1;
    }
}

void SortTheCounter(){
    qsort(cnt1,26,sizeof(int),cmp);
    qsort(cnt2,26,sizeof(int),cmp);
}

void CompareAndOutput(){
    for(int i=0;i<CHARACTER_MAX;i++){
        if(cnt1[i]!=cnt2[i]) {
            printf("NO\n");
            return;
        }
    }
    printf("YES\n");
}

int main(){

    CleanTable();

    while(scanf("%s",input1) == 1){
        if(input1[0] == EOF) break;
        scanf("%s",input2);

        ScanInputAndCount();

        SortTheCounter();

        CompareAndOutput();

        CleanTable();

    }

    return 0;
}

