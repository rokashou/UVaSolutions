#include <iostream>
#include <stack>
#include <map>
#include <vector>
//#include <string>
#include <set>
#include <algorithm>
//#define debug
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())

using namespace std;


typedef set<int> Set;
map<Set,int> IDcache; // project the Set to ID
vector<Set> Setcache; // get Set with ID

// find the ID of Set. the Set is not in IDcache, 
// then add the Set into IDcache, and reply a new one.
int ID (Set x){
    if (IDcache.count(x)) return IDcache[x];
    Setcache.push_back(x); // add Set into cache
    return IDcache[x] = Setcache.size() - 1;
}

void process(){
    //IDcache.clear();
    //Setcache.clear();

    stack<int> s;

    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        string op;
        cin >> op;
        if(op[0]=='P'){ // op: PUSH
            s.push(ID(Set())); 
        } 
        else if(op[0]=='D'){ // op: DUP
            s.push(s.top()); 
        }
        else{
            Set x1 = Setcache[s.top()]; s.pop();
            Set x2 = Setcache[s.top()]; s.pop();
            Set x;
            if(op[0]=='U'){ // op:UNION
                set_union(ALL(x1),ALL(x2),INS(x)); 
            }
            if(op[0]=='I'){ //op:INTERSECT
                set_intersection(ALL(x1), ALL(x2), INS(x));
            }
            if(op[0]=='A') { // op:ADD
                x=x2;x.insert(ID(x1)); 
            }
            s.push(ID(x));
        }
        cout << Setcache[s.top()].size() << endl;
    }

}

int main(){
#ifdef debug
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif

    int rc=0;
    while(cin >> rc){
        for(int loop = 0;loop<rc;loop++){
            process();
            cout << "***" << endl;
        }
    }

    return 0;
}
