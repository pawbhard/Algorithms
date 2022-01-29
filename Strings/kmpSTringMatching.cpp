#include <bits/stdc++.h>

using namespace std;

void computeLps(string pat, int pat_sz, vector<int> &lps) {
    int len = 0;
    int j = 1;
    lps[0] = 0;
    while (j < pat_sz) {
        if (pat[len] == pat[j]) {
            lps[j] = len + 1;
            len++; j++;
        } else if (len != 0) {
            len = lps[len-1];
        } else {
            lps[j] = 0;
            j++;
        }
    }
}

int match(string pat, string text) {
    int pat_sz = pat.length();
    int text_sz = text.length();

    vector<int> lps(pat_sz, 0);
    computeLps(pat, pat_sz, lps);

    int i = 0;
    int j = 0;
    while (i < text_sz) {
        if (text[i] == pat[j]) {
            i++;
            j++;
        } else if (j != 0) {
            j = lps[j-1];
        } else {
            i++;
        }

        if(j == pat_sz) break;
    }

    return i-j;
}

int main() {
    cout<<match("onion", "oniojonioonion")<<"\n";
}