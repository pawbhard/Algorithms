#include <vector>
#include <string>
#include <stack>
#include <unordered_map>
#include <set>
#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;

int maxProfit(vector<int>& prices) {
    vector<int> profit{};
    int m = prices[0];
    for (int i = 0; i < prices.size(); i++) {
        profit.push_back(prices[i] - m);
        if (prices[i] < m)
            m = prices[i];
    }
    return *max_element(profit.begin(), profit.end());
}

int main() {
    vector<int> nums{3,1,2, 11,4,0, 6,4,1,3,12};
    cout<<maxProfit(nums)<<"\n";
    return 0;
}
