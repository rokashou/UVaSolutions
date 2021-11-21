#include <stdio.h>
#include <string.h>

#define debugFlag1

int table[10][10][2];
int squares[9];

void initializeTable(){
    memset(table,0,sizeof(table));
    memset(squares,0,sizeof(squares));
}

void readLines(int m){
    char ch;
    int i,j;
    char input[10];
    for(int idx=0;idx<m;idx++){
        //scanf("%s",input);
        scanf("%s %d %d",input,&i,&j);
        ch = input[0];
        if(ch == 'H'){
            table[i-1][j-1][0]=1;
        }else{
            table[j-1][i-1][1]=1;
        }
    }
}

void processSquares(int tableSize){
    int squareSize=tableSize-1;

    while(squareSize > 0){
        for(int i=0;i+squareSize<tableSize;i++)
        for(int j=0;j+squareSize<tableSize;j++){
            int flag=1;
            for(int si=0;si<squareSize&&flag;si++){
                // check V by row
                if(table[i+si][j][1]==0) flag=0;
                if(table[i+si][j+squareSize][1]==0) flag=0;

                // check H by column
                if(table[i][j+si][0]==0) flag=0;
                if(table[i+squareSize][j+si][0]==0) flag=0;
            }
            squares[squareSize-1]+=flag;
        }
        squareSize--;
    }

}

void outputResult(int n){
    int count=0;

    for(int i=0;i<n;i++){
        count+=squares[i];
        if(squares[i]>0) printf("%d square (s) of size %d\n",squares[i],i+1);
    }
    if(count == 0){
        printf("No completed squares can be found.\n");
    }
    //printf("\n");
}

int main(){

#ifdef debugFlag
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif

    int problemCount=0;
    int tableSize;
    int lineCount;

    while(scanf("%d",&tableSize)==1 && tableSize){
        problemCount++;

        if(problemCount > 1){
            printf("\n**********************************\n\n");
        }
        printf("Problem #%d\n\n",problemCount);
        initializeTable();

        scanf("%d",&lineCount);

        readLines(lineCount);

        processSquares(tableSize);

        outputResult(tableSize);
    }

    return 0;

}