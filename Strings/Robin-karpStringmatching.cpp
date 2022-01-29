#include <bits/stdc++.h>

using namespace std;

#define d 256

int search(string pat, string text) {
    int q = 997;

    int pat_sz = pat.length();
    int text_sz = text.length();

    int pat_hash = 0;
    int text_hash = 0;
    int h = 1;
    //h = pow(d, M-1) % q
    
    for(int i = 0; i < pat_sz -1; i++) {
        h = (h * d) % q;
    }


    for (int i = 0 ; i < pat_sz; i++) {
        pat_hash = (d * pat_hash + pat[i]) % q;
        text_hash = (d * text_hash + text[i]) % q;
    }

    //slide the pattern and check the hash
    for (int i = 0; i <= text_sz-pat_sz; i++) {

        if(pat_hash == text_hash)  {
            int j;
            for(j = 0; j < pat_sz; j++) {
                if (pat[j] != text[i+j]) break;
            }

            if(j == pat_sz) return i;
        }

        if (i < text_hash - pat_sz) {

            //Remove start and add trailing digit
            text_hash = (d * (text_hash - text[i] * h) + text[i+pat_sz] ) % q;
            //if negative make positive
            if (text_hash < 0)
                text_hash = q + text_hash; 
        }
    }
}

int main() {
    cout<<search("AACG", "AAACGACCAACCGAACGG")<<"\n";
}