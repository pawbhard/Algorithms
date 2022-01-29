#include <vector>
#include <string>
#include <stack>
#include <unordered_map>
#include <set>
#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;

int maxProduct(vector<int>& nums) {
    int maxProd = nums[0];
    int maxTillHere = nums[0];
    int minTillHere = nums[0];

    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] < 0)
            swap(minTillHere, maxTillHere);

        maxTillHere = max(nums[i], nums[i] * maxTillHere);
        minTillHere = min(nums[i], nums[i] * minTillHere);

        maxProd = max(maxTillHere, maxProd);
    }
    return maxProd;
}
int main() {
    vector<int> nums{3,1,2,-1,4,0, 6,4,-1,3,-2};
    cout<<maxProduct(nums)<<"\n";
    return 0;
}
