/*
    input: 
        NOTAPALINDROME
        ISAPALINILAPASI
        2A3MEAS
        ATOYOTA
    output:
        NOTAPALINDROME -- is not a palindrome.

        ISAPALINILAPASI -- is a regular palindrome.

        2A3MEAS -- is a mirrored string.

        ATOYOTA -- is a mirrored palindrome.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
const char* rev = "A   3  HIL JM O   2TUVWXY51SE Z  8 ";
const char* msg[] = {"not a palindrome","a regular palindrome","a mirrored string","a mirrored palindrome"};

char r(char ch){
    if(isalpha(ch)) return rev[ch-'A'];
    // it must be a *number*
    return rev[ch - '0' + 25];
}

int main()
{
    char s[30];
    while(scanf("%s",s) == 1) {
        int len=strlen(s);
        int p=1, m=1;
        for(int i=0;i<(len+1)/2;i++){ // count as (len+1)/2 for odd length
            if(s[i] != s[len-1-i]) p = 0; // not palindrome
            if(r(s[i]) != s[len-1-i]) m = 0; // not mirrored
        }
        printf("%s -- is %s.\n\n", s, msg[m*2+p]);
    }

    return 0;
}
