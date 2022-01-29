#include <bits/stdc++.h>
using namespace std;

int lengthOfLIS(vector<int> nums) {
    size_t sz = nums.size();
    vector<int> dp(sz,1);
    vector<int> path(sz,-1); //to store path
    for(size_t i = 1; i < sz; i++) {
        for(int j = i-1; j >= 0; j--) {
            if (nums[i]> nums[j] and dp[i] < dp[j]+1) {
                dp[i] = dp[j] + 1;
                path[i] = j;
            }

        }
    }

    int i = sz-1;
    vector<int> res;
    while(i >= 0) {
        res.push_back(nums[i]);
        i = path[i];
    }
    cout<<"Sequence : ";
    copy(res.rbegin(), res.rend(), ostream_iterator<int> (cout, " "));
    cout<<"\n";
    return dp[sz-1];
}

//Lower bound solution
vector<int> longestIncreasingSubSeq(vector<int> nums) {
    vector<int> lis{};
    size_t sz = nums.size();
    for(size_t i = 0; i < sz; i++) {
        if (lis.empty() or lis[lis.size()-1] < nums[i]) { 
            lis.push_back(nums[i]);
        } else { //it >= x
            auto it = lower_bound(lis.begin(), lis.end(), nums[i]);
            *it = nums[i];
        }
    }
    return lis;
}
int main() {
    cout<<lengthOfLIS({10,9,2,3,5,7,101,18})<<endl;
    cout<<lengthOfLIS({4,4,4,4,4,4})<<endl;
    cout<<lengthOfLIS({1,3,10,8,2,2,3,3,4})<<endl;

    vector<vector<int>> num_arr{{1,3,10,8,2,2,3,3,4},{4,4,4,4,4,4},{10,9,2,3,5,7,101,18}};
    for(auto v: num_arr) {
        auto res = longestIncreasingSubSeq(v);
        copy(res.begin(), res.end(), ostream_iterator<int>(cout, " "));
        cout<<"\n";
    }
    return 0;
}