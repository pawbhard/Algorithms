#include <vector>
#include <string>
#include <stack>
#include <unordered_map>
#include <set>
#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> res{};
    long long int product = 1;
    short zero = 0;
    for (int e : nums) {
        if(e == 0) {
            zero++;
        } else {
            product *= e;
        }
    }

    for (int e : nums) {
        if (e == 0) {
            if (zero == 1) {
                res.push_back(product);
            } else {
                res.push_back(0);
            }
        } else {
            if (zero == 0) {
                res.push_back(product / e);
            } else {
                res.push_back(0);
            }
        }
    }
    return res;
}

int main() {
    vector<int> n {-1,0,1,2,-1,-4};
    auto r = productExceptSelf(n);
    copy(r.begin(), r.end(), ostream_iterator<int>(cout, " "));
    cout<<"\n";
    return 0;
}
