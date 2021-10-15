#include <stdio.h>
#include <string.h>

char matrix[50+2][1000+2];
int ACGT[4][1000+2];

void cleanTable(){
    memset(matrix,0,sizeof(matrix));
    memset(ACGT,0,sizeof(ACGT));
}

int main()
{
    int T=0;
    while(scanf("%d",&T) == 1 && T){
        int m,n;
        for(int round=0;round<T;round++){
            cleanTable();
            scanf("%d %d",&m,&n);
            char input[1002];

            // READ DNAs
            for(int i=0;i<m;i++){
                scanf("%s",input);
                for(int j=0;j<n;j++){
                    matrix[i][j]=input[j];
                    int dnaIdx = 0;
                    switch(input[j]){
                        case 'A':
                            dnaIdx = 0;
                            break;
                        case 'C':
                            dnaIdx = 1;
                            break;
                        case 'G':
                            dnaIdx = 2;
                            break;
                        case 'T':
                            dnaIdx = 3;
                            break;
                    }
                    ACGT[dnaIdx][j]+=1;
                }
            }

            // Create Best DNA
            for(int i=0;i<n;i++){
                int maxChar = 0;
                int maxCount = 0;
                for(int k=0;k<4;k++){
                    if(ACGT[k][i] > maxCount) {
                        maxChar = k;
                        maxCount = ACGT[k][i];
                    }
                }
                char output;
                switch(maxChar){
                    case 0:
                        output='A';
                        break;
                    case 1:
                        output='C';
                        break;
                    case 2:
                        output='G';
                        break;
                    case 3:
                        output='T';
                        break;
                }
                printf("%c",output);
                input[i]=output;
            }
            printf("\n");

            // count different
            int different=0;
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(matrix[i][j]!=input[j]) different += 1;
                }
            }
            printf("%d\n",different);
        }
    }

    return 0;
}