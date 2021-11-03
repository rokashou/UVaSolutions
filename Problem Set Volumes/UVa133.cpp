#include <stdio.h>
const int MAXN = 25;
int n,k,m,a[MAXN];

/** step: steps in counter-clock.
    distence: as the distence for every step. if distence < 0, the step is go in clock
    
 */
int go(int position, int distence, int step){ 
    while(step--){
        do { position = (position+distence+n-1)%n+1; }while( a[position] == 0 );
    }
    return position;
}

int main(){
    while(scanf("%d%d%d",&n,&k,&m)==3 && n){
        for(int i=1;i<=n;i++) a[i]=i;
        int remain=n;
        int p1 = n, p2 = 1;
        while(remain){
            p1 = go(p1,1,k);
            p2 = go(p2,-1,m);
            printf("%3d",p1); remain--;
            if(p2 != p1) { printf("%3d",p2); remain--; }
            a[p1] = a[p2] = 0;
            if(remain) printf(",");
        }
        printf("\n");
    }
}