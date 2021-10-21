#include <cstdio>
#include <cstring>
using namespace std;

const int MaxLength = 105;
const int DoubleLength = 2*MaxLength;

char str1[MaxLength];
char str2[MaxLength];
char strTemp[DoubleLength];

void cleanTables(){
    memset(str1,0,sizeof(str1));
    memset(str2,0,sizeof(str2));
    memset(strTemp,0,sizeof(strTemp));
}
 
bool checkKickdown(){
    int len = strlen(strTemp);
    for(int i=0;i<len;i++){
        if(strTemp[i] < '0' && strTemp[i] > 3){
            return false;
        }
        else if(strTemp[i] > '3'){
            return false;
        }
    }
    return true;
}

void cleanTemp(){
    memset(strTemp,0,sizeof(strTemp));
}


int main(){
    cleanTables();

    while(scanf("%s",str1) == 1){
        scanf("%s",str2);
        int len1 = strlen(str1),len2 = strlen(str2);
        int minimum=len1+len2;

        int x=len1-1;
        while(x>=0){
            cleanTemp();
            int i=0;
            for(;i<len1;i++){
                strTemp[i]=str1[i]-'0';
            }
            for(i=0;i<len2;i++){
                strTemp[i+x]+=str2[i]-'0';
            }
            if(checkKickdown()){
                if(strlen(strTemp) < minimum) minimum = strlen(strTemp);
            }

            x--;
        }

        x=len2-1;
        while(x>=0){
            cleanTemp();

            int i=0;
            for(;i<len2;i++){
                strTemp[i]=str2[i]-'0';
            }
            for(i=0;i<len1;i++){
                strTemp[i+x]+=str1[i]-'0';
            }
            if(checkKickdown()){
                if(strlen(strTemp) < minimum) minimum = strlen(strTemp);
            }

            x--;
        }

        printf("%d\n",minimum);

        cleanTables();
    }

    return 0;
}