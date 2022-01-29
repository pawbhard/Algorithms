//
#include<bits/stdc++.h>
using namespace std;

bool canJump(vector<int>& nums) {
    int sz = nums.size();
    int max_len = 0;
    for (int i = 0; i < sz;i++) {
        if (i > max_len) return false;
        max_len = max(max_len, nums[i]+i);
    }
    return true;
}

//Min number of jumps
int jump(vector<int>& nums) {
          int sz = nums.size();
        vector<int> mem(sz, INT_MAX);
        mem[0] = 0;
        for (int i = 0; i < sz; i++) {
            int val = nums[i];
            cout<<"val : "<<val<<endl;
            for(int j = i+1; j<= val+i and j< sz; j++) {
                if(mem[j] == INT_MAX) mem[j] = 1+mem[i];
                else mem[j] = min(mem[j], 1+mem[i]);
            }
            copy(mem.begin(), mem.end(), ostream_iterator<int>(cout," "));
            cout<<endl;
        }
        return mem[sz-1];  
}

bool canReach(vector<int>& arr, int start) {
    int sz = arr.size();
    vector<bool> mem(sz, 0);
    queue<int> q;
    q.push(start);
    
    while(not q.empty()) {
        int idx = q.front();
        q.pop();
        mem[idx] = 1;
        if (arr[idx] == 0) return true;
        if (idx + arr[idx] < sz and mem[idx + arr[idx]] != 1) q.push(idx + arr[idx]);
        if (idx - arr[idx] >= 0 and mem[idx - arr[idx]] != 1) q.push(idx - arr[idx]); 
    }
    return true;
}

int main() {
    vector<int> nums {2,1,2,0,5};
    cout<<boolalpha<<canJump(nums)<<endl;
    //vector<int> n{2,3,1,1,4};
    //cout<<jump(n)<<endl;
    vector<int> n{3,0,2,1,2};
    int s = 2;
    cout<<canReach(n,s)<<endl;
    return 0;
}