#include <stdio.h>
#include <string.h>

const int MAX_M = 1000;

#define debugFlag1 1

//int ipTable[MAX_M][4];
int m;
int address[4];
int netmask[4];

//unsigned int nmask;

void initialize(){
    //memset(ipTable,0,sizeof(ipTable));
    memset(address,0,sizeof(address));
    netmask[0]=255;netmask[1]=255;netmask[2]=255;netmask[3]=255;
    //nmask=(255<<24) + (255 << 16) + (255 << 8) + 255;
    //m=0;
}


int maxBit(int n){
    int flag=1;
    int result = 0;
    for(int i=7;i>=0;i--){
        if( (n & (1<<i)) > 0) break;
        result += (1<<i);
    }
    return result;
}

int checkNum(int idx, int n){
    //int temp = address[idx] & n;
    int vers = address[idx] ^ n;
    int mask=maxBit(vers);
    
    //address[idx] &= mask;
    netmask[idx] &= mask;
    address[idx] &= netmask[idx];

    if(idx < 3 && (255 - netmask[idx]) > 0) netmask[idx+1]=0;
    return mask;
}

void read_ips(){
    for(int i=0;i<m;i++){
        int input[4];

        scanf("%d.%d.%d.%d",&input[0],&input[1],&input[2],&input[3]);

        if(i==0){
            address[0]=input[0];
            address[1]=input[1];
            address[2]=input[2];
            address[3]=input[3];
            continue;
        }

        for(int j=0;j<4;j++){
            checkNum(j,input[j]);
        }
    }
}

void printOutput(){
    printf("%d.%d.%d.%d\n",address[0],address[1],address[2],address[3]);
    printf("%d.%d.%d.%d\n",netmask[0],netmask[1],netmask[2],netmask[3]);
}

int main()
{
#ifdef debugFlag
    freopen("data3.in","r",stdin);
    freopen("data3.out","w",stdout);
#endif
    int count=0;
    while(scanf("%d",&m)==1 && m){
        count+=1;
        initialize();
        read_ips();
        printOutput();
    }

    return 0;
}