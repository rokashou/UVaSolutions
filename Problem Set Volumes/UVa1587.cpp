#include <cstdio>
#include <algorithm>
using namespace std;

struct rect{
    int w;
    int h;
};

bool sortRect(const rect &r1, const rect &r2){
    if(r1.w != r2.w)
    {
        return r1.w < r2.w;
    }
    else
    {
        return r1.h < r2.h;
    }
}

int main(){
    rect rects[6];
    int i=0,j=0;
    int flag;

    int count=0;

    while( scanf("%d %d",&i,&j) == 2 && i ){
        if(i<j){
            rects[count].w=i;
            rects[count].h=j;
        }else{
            rects[count].w=j;
            rects[count].h=i;
        }

        count ++;


        if(count == 6){
            // sort the rects
            sort(rects, rects+6, sortRect);
            flag=0;

            // check pairs
            if(rects[0].w != rects[1].w || rects[0].h != rects[1].h ||
                rects[2].w != rects[2].w || rects[2].h != rects[3].h ||
                rects[4].w != rects[5].w || rects[4].h != rects[5].h){
                    flag=1;
                }
            else if(rects[0].w != rects[2].w ||
                rects[0].h != rects[4].w ||
                rects[2].h != rects[4].h) {
                    flag+=1;
            }


            if(flag==0) 
                printf("POSSIBLE\n");
            else
                printf("IMPOSSIBLE\n");
            count =0;
        }
    }
}