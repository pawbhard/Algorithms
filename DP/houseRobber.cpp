//https://leetcode.com/problems/house-robber/
#include <bits/stdc++.h>
using namespace std;

int rob(vector<int>& nums) {
    vector<int> val (nums.size()+1, 0);
    val[1] = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        val[i+1] = max(val[i-1]+nums[i], val[i]);
    }
    copy(val.begin(), val.end(), ostream_iterator<int>(cout," "));
    cout<<endl;
    return val[nums.size()];

}

//first and last are neighbors.
int rob2(vector<int>& nums) {
    vector<int> nums1(nums.begin(), nums.end()-1);
    vector<int> nums2(nums.begin()+1, nums.end());
    return max(rob(nums1), rob(nums2));
}

int main() {
    vector<int> nums{2, 1,2,1,1,4,1,3};
    cout<<rob2(nums)<<endl;
    return 0;
}
