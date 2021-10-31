#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

// Ref Url: http://naivered.github.io/2016/08/08/Problem_Solving/UVa/UVa-11809-Floating-Point-Numbers/

const int MAX_M=10;
const int MAX_E=30;
const double TOLERENCE = 1e-6;

int E[MAX_M][MAX_E];
double M[MAX_M][MAX_E];

void CleanTable(){
    memset(M,0,sizeof(M));
    memset(E,0,sizeof(E));
}

void MakeTable(){
    double mantissa,ex,x;
    
    for(int i=0;i<MAX_M;i++){
        for(int j=0;j<MAX_E;j++){
            mantissa = 1 - pow(2, -1 - i); // 1-2^(-1-m)
            ex = pow(2,j+1) - 1; // 2^e-1
            x=log10(mantissa) + ex*log10(2.0); 

            double e,m; 
            e = floor(x);
            m = pow(10,x-e); // 10 ^ (x-e)
            E[i][j] = e;
            M[i][j] = m;
        }
    }
}

void PrintOut(int m, int e){
    printf("%d %d\n",m,e);
}

void FindInTableAndPrintOut(double mantissa, int n){
    for(int i=0;i<MAX_M;i++){
        for(int j=0;j<MAX_E;j++){
            if(n==E[i][j] && fabs(mantissa - M[i][j]) < TOLERENCE){
                PrintOut(i,j+1);
                return ;
            }
        }
    }
}

bool ReadInput(double &A, int &B){
    char input[22];
    int result = scanf("%s",input);
    int eIdx = (strchr(input,'e') - input);
    input[eIdx]=' ';

    sscanf(input,"%lf %d",&A,&B);

    if(A==0 && B==0) return false;
    return true;

}

int main(){
    double A;
    int B;
    
    MakeTable();

    while(ReadInput(A,B)){
        FindInTableAndPrintOut(A,B);
    }

    return 0;
}
