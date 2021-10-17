#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int MAX_REPEAT_DECIMAL = 4000;

char output[MAX_REPEAT_DECIMAL+5];
char repeatDecimal[MAX_REPEAT_DECIMAL+2];
char preDigits[MAX_REPEAT_DECIMAL+2];
int recordMod[MAX_REPEAT_DECIMAL+2];

void cleanTables(){
    memset(output,0,sizeof(output));
    memset(preDigits,0,sizeof(preDigits));
    memset(repeatDecimal,0,sizeof(repeatDecimal));
    memset(recordMod,-1,sizeof(recordMod));
}

int FindContantMod(int mod){
    int i=0;
    while(i<MAX_REPEAT_DECIMAL && recordMod[i] != -1){
        if(mod == recordMod[i]) return i;
        i++;
    }
    return -1;
}

int CalculateDeciamls(int a, int b, int maxDigit){
    int count=0;
    int q=a/b;
    sprintf(output,"%d.",q);
    a-=q*b;
    a*=10;
    int idxPoint=strlen(output);

    while(count < maxDigit){
        int index = FindContantMod(a);
        if(index != -1){
            return index + idxPoint;
        }
        recordMod[count] = a;

        if(a == 0){
            return -1;
        }
        
        q=a/b;
        a-=q*b;
        a*=10;

        char nextDigit='0'+q;

        output[idxPoint+count]=nextDigit;
        count ++;
    }

    return -2;
}


void printOutput(int a, int b, const char preDigit[], const char repeatingDeciaml[]){
    int posOfPoint = strchr(preDigit,'.') - preDigit;
    int decimalPreset = strlen(preDigit) - posOfPoint - 1;
    int repeatLen = strlen(repeatingDeciaml);
    int maxDigitOnScreen = 50 - decimalPreset;
    if(maxDigitOnScreen < 0) maxDigitOnScreen=25; 
    if(repeatLen > maxDigitOnScreen){
        char outputRepeat[55];
        memset(outputRepeat,0,sizeof(outputRepeat));
        memcpy(outputRepeat,repeatDecimal, maxDigitOnScreen );

        char outputPre[55];
        memset(outputPre,0,sizeof(outputPre));
        memcpy(outputPre,preDigit,maxDigitOnScreen);
        //outputRepeat[50]=0;
        printf("%d/%d = %s(%s...)\n",a,b,outputPre,outputRepeat);
        printf("   %d = number of digits in repeating cycle\n", repeatLen);
    }
    else{
        printf("%d/%d = %s(%s)\n",a,b,preDigits,repeatingDeciaml);
        printf("   %d = number of digits in repeating cycle\n", repeatLen);
    }
    printf("\n");
}


int FindRepeatingDecimals(int a,int b){
    // GetDecimal until MAX_REPEAT_DECIMAL = 50
    int repeatStart = CalculateDeciamls(a,b,MAX_REPEAT_DECIMAL);

    int len = strlen(output);
    if(repeatStart == -1){
        memcpy(preDigits,output,len);
        printOutput(a,b,preDigits,"0");
        return 1;
    }

    if(repeatStart == -2){
        printf("%d/%d : No repeat digit.\n\n",a,b);
    }
    
    int idxPoint = strchr(output,'.') - output;

    // copy the repeat;
    int repeatlen = len - repeatStart;
    strncpy(repeatDecimal,output+repeatStart,repeatlen);

    // copy the preDigits 
    strncpy(preDigits,output,repeatStart);

    // make output
    printOutput(a,b,preDigits,repeatDecimal);

    return repeatlen;
}

int main(){
    int a,b;
    int count=0;

    //freopen("data.in","r",stdin);
    //freopen("data.out","w",stdout);
    
    while(scanf("%d %d",&a,&b) == 2){
        cleanTables();
        count++;
        //if(count > 1) printf("\n");
        FindRepeatingDecimals(a,b);
    }
}