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

int maxArea(vector<int>& height) {
    int m = 0;
    for (int i = 0, j = height.size()-1; i<j; ) {
        int cm =  min(height[i], height[j]) * (j-i);
        if ( cm > m) {
            m = cm;
        }

        if(height[i] < height[j])
            i++;
        else
            j--;
    }
    return m;
}

int main() {
    vector<int> data {1,8,6,2,5,4,8,3,7,6};
    cout<<maxArea(data)<<endl;
    return 0;
}
