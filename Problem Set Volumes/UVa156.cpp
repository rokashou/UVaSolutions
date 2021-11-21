// UVa 156: Ananagrams

#include <iostream>
#include <algorithm>
#include <vector>
#include <cctype>
#include <map>
#include <string>
using namespace std;

map<string,int> cnt;
vector<string> words;

// standardise word
string repr(const string& s){
    string ans = s;
    for(int i=0;i<ans.length();i++){
        ans[i] = tolower(ans[i]);
    }
    sort(ans.begin(), ans.end());
    return ans;
}

int main(){
    int n=0;
    string s;

    while(cin >> s){
        if(s[0] == '#') break;
        words.push_back(s);
        string r = repr(s);

        // if r is not in cnt, set the word as new key
        if(!cnt.count(r)) cnt[r] = 0;
        cnt[r]++;
    }

    vector<string> ans;
    for(int i=0;i<words.size();i++){
        if(cnt[repr(words[i])]==1) {
            // add the word into the ans vector, if the count in cnt is 1
            ans.push_back(words[i]);
        }
    }
    sort(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++){
        cout << ans[i] << "\n";
    }

    return 0;
}
