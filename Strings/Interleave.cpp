#include <bits/stdc++.h>

using namespace std;

bool isInterleave(string A, string B, string C) {
    if (A.size() + B.size() != C.size()) return false;
    if (C.size() == 0) return true;

    return (((A[0] == C[0]) and isInterleave(A.substr(1), B, C.substr(1))) or 
            ((B[0] == C[0]) and isInterleave(A, B.substr(1), C.substr(1))));
            
}

bool isInterleaveDP(string A, string B, string C) {
    size_t M = A.size();
    size_t N = B.size();
    if (M + N != C.size()) return false;

    bool mem[M+1][N+1];
    memset(mem, 0 , sizeof(mem)/sizeof(mem[0]));

    for (int i = 0; i <= M; i++) {
        for (int j = 0; j <= N; j++) {
            if (i == 0 and j == 0) {
                mem[i][j] = true;
            } else if (i == 0) {
                if (B[j-1] == C[j-1])
                    mem[i][j] = mem[i][j-1]; 
            } else if (j == 0) {
                if (A[i-1] == C[i-1])
                    mem[i][j] = mem[i-1][j];
            } else if (A[i-1] == C[i+j-1] and B[j-1] == C[i+j-1]) {
                mem[i][j] = mem[i][j-1] or mem[i-1][j];
            } else if (A[i-1] == C[i+j-1]) {
                mem[i][j] = mem[i-1][j];
            } else if (B[j-1] == C[i+j-1]) {
                mem[i][j] = mem[i][j-1];
            }
        }
    }
    for (int i = 0; i <= M; i++) {
        for (int j = 0; j <= M; j++) {
            cout<<mem[i][j]<<" ";
        }
        cout<<endl;
    }
    return mem[M][N];
}

bool isInterleaved1(
    string A, string B, string C)
{
    // Find lengths of the two strings
    int M = A.size(), N = B.size();
    bool mem[M + 1][N + 1];

    memset(mem, 0, sizeof(mem));
    if ((M + N) != C.size())
        return false;

    // Process all characters of A and B
    for (int i = 0; i <= M; ++i) {
        for (int j = 0; j <= N; ++j) {
            if (i == 0 && j == 0) {
                mem[i][j] = true;
            }else if (i == 0) {
                if (B[j-1] == C[j-1])
                    mem[i][j] = mem[i][j - 1];
            } else if (j == 0) {
                if (A[i-1] == C[i-1])
                    mem[i][j] = mem[i-1][j];
            } else if (A[i-1] == C[i+j-1] and B[j-1] == C[i+j-1]) {
                mem[i][j] = mem[i][j-1] or mem[i-1][j];
            } else if (A[i-1] == C[i+j-1]) {
                mem[i][j] = mem[i-1][j];
            } else if (B[j-1] == C[i+j-1]) {
                mem[i][j] = mem[i][j-1];
            }
        }
    }
        for (int i = 0; i <= M; i++) {
        for (int j = 0; j <= M; j++) {
            cout<<mem[i][j]<<" ";
        }
        cout<<endl;
    }
    return mem[M][N];
}

int main() {
    string A {"XYY"};
    string B {"ABC"};
    string C {"XABYCZ"};
    cout<<boolalpha<<isInterleaveDP(A,B,C)<<endl;
    cout<<boolalpha<<isInterleaved1(A,B,C)<<endl;
    return 0;
    
}
