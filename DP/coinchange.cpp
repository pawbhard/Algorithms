//https://leetcode.com/problems/coin-change/
#include <bits/stdc++.h>
using namespace std;

int recursive(vector<int>& coins, int amount) {
    //cout<<"checking amount "<< amount<<endl;
    if (amount == 0) return 0;
    if (amount < 0) return -1;
    int mval = INT_MAX;
    for (int c: coins) {
        int val = recursive(coins, amount-c);
        if (val != -1 and val < mval) {
            mval = val;
        }
    }
    return mval == INT_MAX ? -1 : mval+1;
}

int worker(vector<int>& coins, int amount, unordered_map<int,int> &mem) {
    if (amount == 0) return 0;
    if (amount < 0) return -1;

    int mval = INT_MAX;
    auto it = mem.find(amount);
    if (it != mem.end()) return it->second;

    for (int c: coins) {
        int val = worker(coins, amount-c, mem);
        if (val != -1 and val < mval) {
            mval = val;
        }
    }
    ;
    mem[amount] = mval == INT_MAX ? -1 : mval+1;
    return mem[amount];
}

int memoization(vector<int>& coins, int amount) {
    unordered_map<int,int> mem{};
    
    return worker(coins, amount, mem);
}

int dp(vector<int>& coins, int amount) {
    vector<int> dp(amount+1,INT_MAX);
    sort(coins.begin(), coins.end());
    dp[0] = 0;
    for(int i = 1; i <=amount ; i++) {
        for (int c: coins) {
            if (i<c) break;
            if (dp[i-c] != INT_MAX) dp[i] = min(dp[i], 1+ dp[i-c]);
        }
    }
    return dp[amount] == INT_MAX ? -1 : dp[amount];
}

int coinChange(vector<int>& coins, int amount) {
    return dp(coins,amount);
    //return memoization(coins, amount);
    //return recursive(coins, amount);    
}

int main() {
    vector<int> coins {6,4,1};
    vector<int> invalid{8,4,2};

    cout<<"For amount 8 "<<coinChange(coins, 8)<<" Expected 2"<<endl;
    cout<<"For amount 21 "<<coinChange(coins, 21)<<" Expected 5"<<endl;
    cout<<"For amount 16 "<<coinChange(coins, 16)<<" Expected 3"<<endl;
    cout<<"For amount 1 "<<coinChange(coins, 1)<<" Expected 1"<<endl;
    cout<<"For amount 4 "<<coinChange(coins, 4)<<" Expected 1"<<endl;
    cout<<"For amount 0 "<<coinChange(coins, 0)<<" Expected 0"<<endl;

    cout<<"For amount 17 "<<coinChange(invalid, 17)<<" Expected -1"<<endl;
    
}