//https://leetcode.com/problems/combination-sum-iv/
//https://leetcode.com/problems/combination-sum/
#include <bits/stdc++.h>
using namespace std;

int combinationSum4_recur(vector<int>& nums, int target) {
    if(target == 0) return 1;
    if (target < 0) return -1;
    int tot = 0;
    for (int n: nums) {
        int val = combinationSum4_recur(nums, target-n);
        if(val != -1)
            tot += val;
    }
    return tot;
}
//DP solution
int combinationSum4(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    vector<unsigned int> mem(target+1,0);
    mem[0] = 1;
    for (int i = 1; i <= target; i++) {
        for (int j : nums) {
            if (j > i) break;
            mem[i] += mem[i-j];
        }
    }

    copy(mem.begin(), mem.end(), ostream_iterator<int>(cout," "));
    cout<<endl;
    return mem[target];
}

void _worker(vector<int>& candidates, int target, int ci, vector<int>& res, vector<vector<int>> &f) {
    if (target == 0) f.push_back(res);
    if (target < 0) return;
    for (int i = ci; i < candidates.size(); i++) {
        res.push_back(candidates[i]);
        _worker(candidates, target-candidates[i], i, res, f);
        res.pop_back();
    }
}
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> f{};
    sort(candidates.begin(), candidates.end());
    vector<int> res{};
    _worker(candidates, target, 0, res, f);
    return f;     
}

//=============== comb 2 only once
void _worker2(vector<int>& candidates, int target, int ci, vector<int>& res, vector<vector<int>> &f) {
    if (target == 0) f.push_back(res);
    if (target < 0) return;
    for (int i = ci; i < candidates.size(); i++) {
        res.push_back(candidates[i]);
        _worker2(candidates, target-candidates[i], i+1, res, f);
        res.pop_back();
        while (i < candidates.size() and candidates[i+1] == candidates[i]) i++;
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> f{};
    sort(candidates.begin(), candidates.end());
    vector<int> res{};
    _worker2(candidates, target, 0, res, f);  
    return f;
}

int main() {
    vector<int>nums {10,1,2,7,6,1,5,5};
    int target = 12;
    cout<<combinationSum4_recur(nums, target)<<"\n"<<combinationSum4(nums, target)<<endl;
    vector<vector<int>> f = combinationSum2(nums, target);
    for (auto v : f) {
        cout<<"[";
        for (int n: v) {
            cout<<n<<", ";
        }
        cout<<"]";
    }
    cout<<endl;
    return 0;
}