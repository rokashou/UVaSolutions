#include <stdio.h>
#include <string.h>

char puzzle[12][12];
char leads[12][12];

void cleanPuzzle(){
    memset(puzzle,0,sizeof(puzzle));
    memset(leads,0,sizeof(leads));
}

void searchLeads(int r, int c){
    int count=1;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(puzzle[i][j]=='*') continue;
            if(i==0 || puzzle[i-1][j] == '*' || j==0 || puzzle[i][j-1] == '*'){
                leads[i][j]=count;
                count++;
            } 
        }
    }
}

void printAcross(int maxR,int maxC,int r, int c)
{
    printf("%3d.",leads[r][c]);
    for(int j=c;j<maxC;j++){
        if(puzzle[r][j] != '*'){
            printf("%c",puzzle[r][j]);
        }
        else
            break;
    }
    printf("\n");
}

void printDown(int maxR,int maxC,int r, int c)
{
    printf("%3d.",leads[r][c]);
    for(int i=r;i<maxR;i++){
        if(puzzle[i][c] != '*'){
            printf("%c",puzzle[i][c]);
        }
        else
            break;
    }
    printf("\n");

}

int main(){
    //cleanPuzzle();
    int r,c;
    char input[80];
    int kase=0;

    while(scanf("%d",&r)==1 && r != 0){
        cleanPuzzle();

        kase++;
        if(kase > 1) printf("\n");
        printf("puzzle #%d:\n",kase);

        scanf("%d",&c);
        for(int i=0;i<r;i++){
            scanf("%s",input);
            memcpy(puzzle[i],input,sizeof(char)*c);
        }

        searchLeads(r,c);

        printf("Across\n");
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(leads[i][j]>0){
                    if (j==0 || (j>0 && puzzle[i][j-1]=='*')){
                        printAcross(r,c,i,j);
                    }
                }
            }
        }

        printf("Down\n");
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(leads[i][j]>0){
                    if (i==0 || (i>0 && puzzle[i-1][j]=='*')){
                        printDown(r,c,i,j);
                    }
                }
            }
        }


    }
}