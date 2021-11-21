// UVa 10815: Andy's First Dictionary

#include<iostream>
#include<string>
#include<set>
#include<sstream>
using namespace std;

set<string> dict; 

int main(){
    string s,buf;
    while(cin >> s){
        // preprocess the input string
        // 1. set all the upper character to lower
        // 2. repleace the non-alpha character with space;
        for(int i=0;i<s.length();i++)
            if(isalpha(s[i])) s[i] = tolower(s[i]); else s[i]=' ';
        
        // insert the word into dictionary.
        // "set" will sort and unique the dictionary auto.
        stringstream ss(s);
        while(ss >> buf) dict.insert(buf);
    }

    // output the result;
    for(set<string>::iterator it = dict.begin();it!=dict.end();++it){
        cout << *it << "\n";
    }

    return 0;
}