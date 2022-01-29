#include <bits/stdc++.h>

using namespace std;

std::string longestPalindrome(std::string s) {
    if(s.length() < 2) return s;
    int left=0, len =0;
    int start, end;
    int count = 0;
    for (int i = 0 ; i < s.length(); i++) {
        start=end=i;
        while(start>=0 and s[start] == s[end]) {
            count++;
            start--;
            end++;
        }
        start++;
        
        if(end -start > len) {
            left = start;
            len = end-start;
        }
        start = i; end = i+1;
        while(start >=0 and s[start] == s[end]) {
            count++;
            start--;
            end++;
        }
        start++;
        
        if(end -start > len) {
            left = start;
            len = end-start;
        }
    }
    cout<<"Total substrs "<<count<<endl;
    cout<<"left : "<<left<<" len : "<<end<<endl;
    return s.substr(left,len);
}

int main() {
    string s;
    do {
        cin>>s;
        cout<<longestPalindrome(s)<<endl;
    } while(s!= "q");
    return 0;
}