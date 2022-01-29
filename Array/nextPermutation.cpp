#include <bits/stdc++.h>

using namespace std;

void swap_int(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}
void nextPermutation(vector<int>& nums) {

    int sz = nums.size();
    int i;
    for (i = sz - 1; i >= 1; i--) {
        if (nums[i-1] < nums[i]) break;
    }

    auto it = nums.begin() + i;
    sort(it, nums.end());
    if (i == 0) return;

    int j;
    for(j = i; j < sz; j++) {
        if (nums[j] > nums[i-1]) break;
    }

    swap_int(&nums[i-1], &nums[j]);
}

int main() {
    vector<int> nums {4, 5, 1, 2, 3, 2, 1};
    nextPermutation(nums);
    copy(nums.begin(), nums.end(),ostream_iterator<int>(cout," ")); cout<<"\n";
    return 0;
}