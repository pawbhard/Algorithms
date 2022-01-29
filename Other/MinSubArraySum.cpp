//https://leetcode.com/problems/minimum-size-subarray-sum/
#include <bits/stdc++.h>

using namespace std;

int minSubArrayLen(int target, vector<int>& nums) {
    int len = 0;
    int sum = 0;
    int start = 0, end = 0;
    bool flag = true;
    while(start <= end and end < nums.size()) {
        sum += nums[end++];
        while (sum >= target) {
            if (flag or end - start < len) {
                cout<<"Start: "<<start<<", End: "<<end<<", Sum: "<<sum<<endl;
                len = end - start;
                flag = false;
            }

            //make invalid/valid by increasing start
            sum -= nums[start++];
        }
    }
    return len;
}

int main() {
    int target = 7;
    vector<int> nums {2,3,1,2,4,3};
    cout<<minSubArrayLen(target, nums)<<endl;
    return 0;
}