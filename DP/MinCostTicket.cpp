//https://leetcode.com/problems/minimum-cost-for-tickets/
#include <bits/stdc++.h>

using namespace std;

int recursive(vector<int>& days, vector<int>& costs, int si) {
    if (si >= days.size()) return 0;
    int cost_day = costs[0] + recursive(days, costs, si+1);
    int i;
    for (i = si; i < days.size() and days[i] < days[si]+7;i++);
    int cost_week = costs[1] + recursive(days,costs, i);

    for (i = si; i < days.size() and days[i] < days[si]+30;i++);
    int cost_month = costs[2] + recursive(days, costs, i);

    return min( {cost_day, cost_month, cost_week }); 
}

int _worker(vector<int> &days, vector<int>& costs, int si, vector<int> &mem) {
    if (si>= days.size()) return 0;
    if (mem[si]) {
        cout<<"using saved value" <<endl;
        return mem[si];
    }
    int cost_day = costs[0] + _worker(days, costs, si+1, mem);
    int i;
    for (i = si; i < days.size() and days[i] < days[si]+7;i++);
    int cost_week = costs[1] + _worker(days,costs, i, mem);

    for (i = si; i < days.size() and days[i] < days[si]+30;i++);
    int cost_month = costs[2] + _worker(days, costs, i, mem);

    mem[si] =  min( {cost_day, cost_month, cost_week });

    return mem[si];
}

int memoization(vector<int>&days, vector<int>& costs) {
    vector<int> mem(365,0);
    return _worker(days, costs, 0, mem);
}


int dp(vector<int>& days, vector<int>& costs) {
    unordered_set<int> dy(days.begin(),days.end());
    vector<int> mem(366,0);
    for (int i = 1; i <= 365; i++) {
        if (dy.find(i) == dy.end()) {
            mem[i] = mem[i-1];
        } else {
            if (i >= 30)
                mem[i] = min({costs[0] + mem[i-1], costs[1] + mem[i-7], costs[2] + mem[i-30]});
            else if (i >= 7)
                mem[i] = min(costs[0]+mem[i-1], costs[1]+mem[i-7]);
            else
                mem[i] = costs[0] + mem[i-1];
        }
    }
    return mem[365];
}

int mincostTickets(vector<int>& days, vector<int>& costs) {
    return dp(days, costs);
}

int main() {
    vector<int> days {1,4,6,7,8,20};
    vector<int> costs {2,7,15};
    cout<<mincostTickets(days, costs) <<endl;
    return 0;
}