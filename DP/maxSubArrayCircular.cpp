#include <bits/stdc++.h>
using namespace std;

int maxSubarraySumCircular(vector<int> nums) {
    int ma , ma_c, mi, mi_c;
    ma = ma_c = mi = mi_c = nums[0];
    int total = nums[0];
    size_t sz = nums.size();
    for(size_t i = 1; i < sz; i++) {
        total += nums[i];
        ma = max(ma, ma_c = max(nums[i], ma_c+nums[i]));
        mi = min(mi, mi_c = min(nums[i], mi_c+nums[i]));
    }
    return (ma < 0) ? ma: max(ma, total-mi);
}

int main() {
    cout<<maxSubarraySumCircular({1,-2,3,-2})<<"\n";
    cout<<maxSubarraySumCircular({1})<<"\n";
    cout<<maxSubarraySumCircular({1,2,-2,-5,3,-2})<<"\n";
    cout<<maxSubarraySumCircular({1,-2,3,2})<<"\n";
    cout<<maxSubarraySumCircular({-3,-2,-3})<<"\n";
    return 0;
}