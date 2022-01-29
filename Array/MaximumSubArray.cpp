#include <vector>
#include <vector>
#include <string>
#include <stack>
#include <unordered_map>
#include <set>
#include <iostream>
#include <algorithm>
#include <iterator>


using namespace std;

int maxSubArray(vector<int>& nums) {
    int m = *min_element(nums.begin(), nums.end());
    //cout<<"\n Minimum : "<<m<<"\n";
    int large_sum = nums[0];
    int best_sum = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        best_sum = best_sum + nums[i];
        if (best_sum < nums[i]) {
            best_sum = nums[i];
        }
        if (best_sum > large_sum) {
            large_sum = best_sum;
        }
    }
    return large_sum;
}

int main() {
    vector<vector<int>> data {{4,1,2,3}, {7, -5, 2, -1, 6}, {7, -5, -3, 4, 2, 3}, { -2, -4, -6, -1 , -8}, {0, 0, -1 ,-2}, {-4}, {0}, {9}, {-2,1}};
    for (auto v : data) {
        cout<<"\n Vector : ";
        for (int e : v) {
            cout<<e<<" ";
        }
        cout<<"\n Max Sum "<<maxSubArray(v)<<"\n";
    }
    cout<<"\n";
    return 0;
}
