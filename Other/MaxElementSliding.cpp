//https://leetcode.com/problems/sliding-window-maximum/
#include <bits/stdc++.h>

using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq{};
    vector<int> res{};

    int start = 0;
    int end = 0;
    while (end < nums.size()) {
        int val = nums[end++];
        while(not dq.empty() and val > dq.back()) {
            dq.pop_back();
        }
        dq.push_back(val);

        if (end - start  ==  k) {
            res.push_back(dq.front());
            if (dq.front() == nums[start++])
                dq.pop_front();
        }  
    }
    return res;
}

int main() {
    vector<int> nums {1,3,-1,-3,5,3,6,7};
    int k = 1;
    //vector<int> nums {1};
    //int k = 1;
    vector<int> res = maxSlidingWindow(nums, k);

    copy(res.begin(), res.end(), ostream_iterator<int>(cout, " "));
    cout<<endl;
    return 0;
}