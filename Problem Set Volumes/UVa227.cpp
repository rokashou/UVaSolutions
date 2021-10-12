#include<stdio.h>
#include<string.h>

char puzzle[7][7];


void PrintPuzzle(){
    for(int i=0;i<5;i++){
        printf("%c %c %c %c %c\n",
                puzzle[i][0],
                puzzle[i][1],
                puzzle[i][2],
                puzzle[i][3],
                puzzle[i][4]);
    }
}

char getPossibleChar(){
    char c;
    while( (c = getchar()) != EOF){
        if(c >= 'A' && c <='Z') return c;
        if(c == ' ') return c;
        if(c == '0') return c;
    }
    return EOF;
}

int main() {
    //freopen("data.in","r",stdin);
    //freopen("data.out","w",stdout);

    // fill puzzle with 0;
    memset(puzzle,0,sizeof(puzzle));

    char c;
    int kase=0;

    while( (c=getPossibleChar()) != EOF ){
        if(c=='Z') break;
        kase++;
        if(kase > 1) printf("\n");
        printf("Puzzle #%d:\n",kase);

        // read puzzle
        int i=0,j=0;
        puzzle[i][j]=c;
        j++;
        while(i<5){
            puzzle[i][j]=getPossibleChar();
            j++;
            if(j>=5){
                j=0;
                i++;
            }
        }

        // find the space in puzzle
        i=0;j=0;
        while(true){
            if(puzzle[i][j]==' ') break;
            j++; 
            if(j>=5){
                j=0;i++;
            }
        }

        int illegal=0;

        while((c=getPossibleChar()) != '0')
        {
            switch(c){
                case 'A'://up
                    if(i>0){
                        puzzle[i][j]=puzzle[i-1][j];
                        i--;
                        puzzle[i][j]=' ';
                    }
                    else
                    {
                        illegal=1;
                    }
                    break;
                case 'B'://down
                    if(i<4){
                        puzzle[i][j]=puzzle[i+1][j];
                        i++;
                        puzzle[i][j]=' ';
                    }
                    else
                    {
                        illegal=1;
                    }
                    break;
                case 'L'://left
                    if(j>0){
                        puzzle[i][j]=puzzle[i][j-1];
                        j--;
                        puzzle[i][j]=' ';
                    }
                    else{
                        illegal=1;
                    }
                    break;
                case 'R'://right
                    if(j<4){
                        puzzle[i][j]=puzzle[i][j+1];
                        j++;
                        puzzle[i][j]=' ';
                    }
                    else{
                        illegal = 1;
                    }
                    break;
                default:
                    illegal = 1;
                    break;
            }
        }
        c=getchar();// take the newline
        if(illegal != 0){
            printf("This puzzle has no final configuration.\n");
        }
        else
        {
            PrintPuzzle();
        }

    }

    return 0;
}
