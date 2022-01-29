#include <vector>
#include <string>
#include <stack>
#include <unordered_map>
#include <set>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <unordered_set>
using namespace std;

bool containsDuplicate(vector<int>& nums) {
    return nums.size() != unordered_set<int> (nums.begin(), nums.end()).size();
}

int main() {
    vector<int> data {2,1,3,4,5};
    cout<<boolalpha<<containsDuplicate(data)<<endl;
    return 0;
}
