#include <bits/stdc++.h>

using namespace std;

struct radix_test {
    int bit;
    radix_test(int b) : bit(b) {}
    bool operator()(int a) {
        if (bit == 31)
            return a < 0;
        return !(a & 1<<bit);
    }
};

void radix_sort_lsb(vector<int> &nums) {
    for(int i = 0; i < 32; i++) {
        stable_partition(nums.begin(), nums.end(), radix_test(i));
    }
}

void radix_sort_msb(vector<int>::iterator nums_begin, vector<int>::iterator nums_end, int bit = 31) {
    if (nums_begin != nums_end and bit >=0) {
        auto it = partition(nums_begin, nums_end, radix_test(bit));
        bit--;
        radix_sort_msb(nums_begin, it, bit);
        radix_sort_msb(it, nums_end, bit);
    }
}

//===========================================================================================

int main() {
    srand(time(0));
    int sz = 50;
    vector<int> nums(sz, 0);
    int offset = -30;
    for(int i = 0; i < sz; i++) {
        nums[i] = rand() %60 + offset;
    }

    //radix_sort_msb(nums.begin(), nums.end());
    radix_sort_lsb(nums);
    copy(nums.begin(), nums.end(), ostream_iterator<int>(cout, " "));
    cout<<"\n";
}