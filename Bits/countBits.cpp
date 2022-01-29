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

vector<int> countBits(int n) {
    vector<int> res {};
    int num = 1;
    res.push_back(0);

    for (int i = 1; i <= n; i++) {
        if (num*2 == i) num *= 2;
        res.push_back(res[i-num]+1);
    }
    return res;
}

int main() {
    vector<int> res = countBits(21);
    copy(res.begin(), res.end(), ostream_iterator<int>(cout, " "));
    return 0;
}