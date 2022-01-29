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

vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> vec {nums};
    vector<int> res{};
    sort(vec.begin(), vec.end());
    for(vec_itr start = vec.begin(), end = vec.end()-1; start != end; ) {
        if (start != end){
            if (*start + *end < target) {
                start++;
            } else if (*start + *end > target) {
                end--;
            } else {
                for (int i = 0; i < nums.size(); i++) {
                    if (nums[i] == *start) {
                        res.push_back(i);
                    } else if (nums[i] == *end) {
                        res.push_back(i);
                    }
                }
                break;
            }
        }
    }
    return res;
}

int main() {
    vector<int> n {2,7,11,15};
    auto r = twoSum(n, 9);
    copy(r.begin(), r.end(), ostream_iterator<int>(cout, " "));
    return 0;
}
