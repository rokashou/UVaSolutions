#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int MAXMN=30;
int table[MAXMN*MAXMN];

void readTable(int m, int n){
    for(int i=0;i<m;i++)
    for(int j=0;j<n;j++){
        scanf("%d",&table[i*n+j]);
    }
}

void sortTable(int m, int n){
    sort(table,table+m*n);
}

void calculate(int m, int n, int water){
    int maxindex = m*n;
    int idx=1;
    float waterLevel = 0;

    while(idx<maxindex){
        int step = table[idx] - table[idx-1];
        int baseLevel = step*idx*100;
        if(water > baseLevel){
            water -= baseLevel;
            idx++;
        }
        else{
            waterLevel = 1.0*water/(idx*100) + table[idx-1] + 5e-5;
            float percent = 1.0*(idx)/maxindex*100;
            printf("Water level is %.2f meters.\n",waterLevel);
            printf("%.2f percent of the region is under water.\n\n",percent);
            return;
        }
    }

    waterLevel = 1.0*water/(maxindex*100) + table[maxindex-1] + 5e-5;
    printf("Water level is %.2f meters.\n",waterLevel);
    printf("100.00 percent of the region is under water.\n\n");
            

}

int main(){

    //freopen("data.in","r",stdin);
    //freopen("data.out","w",stdout);

    int region=0;
    int m,n;
    while(scanf("%d %d",&m,&n)==2 && m && n){
        readTable(m,n);
        sortTable(m,n);

        int water;
        scanf("%d",&water);

        region++;
        //if(region > 1) printf("\n");
        printf("Region %d\n",region);
        calculate(m,n,water);

    }

    return 0;
}