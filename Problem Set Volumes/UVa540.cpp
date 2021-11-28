#include <cstdio>
#include <queue>
#include <map>
using namespace std;

const int maxt=1000+10;

int main(){

    int t, kase = 0;
    while(scanf("%d",&t)==1 && t){
        printf("Scenario #%d\n", ++kase);

        // record Team No of all
        map<int, int> team;
        for(int i=0;i<t;i++){
            int n,x;
            scanf("%d",&n);
            while(n--) {scanf("%d",&x); team[x]=i; }
        }

        // Simulation
        queue<int> q,q2[maxt];      // q for team, q2[i] for member in team[i]
        for(;;){
            int x;
            char cmd[10];
            scanf("%s",cmd);
            if(cmd[0]=='S') break;
            else if(cmd[0] == 'D') {
                int t = q.front();
                printf("%d\n", q2[t].front()); q2[t].pop();
                if(q2[t].empty()) q.pop(); // pop out the team when team member is empty;
            }
            else if(cmd[0]=='E'){
                scanf("%d", &x);
                int t = team[x];
                if(q2[t].empty()) q.push(t); // if no team member is queue yet, push team number to team queue.
                q2[t].push(x);
            }
        }
        printf("\n");
    }

    return 0;
}