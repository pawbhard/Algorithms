#include <vector>
#include <string>
#include <stack>
#include <unordered_map>
#include <set>
#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;
typedef vector<int>::iterator vec_itr;

vector<vector<int>> threeSum(vector<int>& nums) {
    int target = 0;
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++) {
        int rest = target - nums[i];
        for (int j = i+1, k = nums.size()-1; j < k ; ) {
            if (nums[j] + nums[k] < rest) {
                j++;
            } else if (nums[j] + nums[k] > rest) {
                k--;
            } else {
                res.push_back(vector<int> {nums[i],nums[j],nums[k]});
                while(j+1<nums.size() and nums[j] == nums[j+1]) j++;
                while(k-1>=0 and nums[k] == nums[k-1]) k--;
                j++;
                k--;
            }
        }
        while(i+1<nums.size() and nums[i] ==nums[i+1]) i++;
    }
    return res;
}
int main() {
    vector<int> n {-1,0,1,2,-1,-4};
    auto res = threeSum(n);
    for (auto r : res) {
        copy(r.begin(), r.end(), ostream_iterator<int>(cout, " "));
        cout<<"\n";
    }
    return 0;
}
