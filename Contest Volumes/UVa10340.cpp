#include <string>
#include <iostream>
using namespace std;

bool checkAllInAll(const string input1, const string input2){
    int max1=input1.length();
    int max2=input2.length();
    int i=0,j=0;
    while(j<max2){
        if(input1[i]==input2[j]){
            i++;
            j++;
        }
        else
        {
            j++;
        }
        if(i >= max1) return true;
    }
    return false;
}

int main(){
    string input1,input2;

    //freopen("data.in","r",stdin);

    while(cin >> input1 >> input2){

        if(checkAllInAll(input1,input2)){
            printf("Yes\n");
        }
        else{
            printf("No\n");
        }

    }

    return 0;
}
