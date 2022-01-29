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

int worker(vector<int> nums, int start, int end) {
    
    
    if (start > end) return -1;
    if (start == end) return nums[start];
    if (end - start == 1) return min(nums[start], nums[end]);
    
    int mid = (end + start) / 2;
    
    if (nums[start] <= nums[mid]) {
        //First part is sorted
        if (nums[end] > nums[start]) {
            return nums[start];
        } else {
            return worker(nums, mid, end);
        }
    } else {
        //Second part is sorted
        if ( nums[start] < nums[end]) {
            return nums[start];
        } else {
            return worker(nums, start, mid);
        }
    }
}

int findMin(vector<int>& nums) {
    return worker(nums, 0, nums.size()-1);
}

int main() {

    vector<int> data{1,2,3,4,5};
    copy(data.begin(), data.end(), ostream_iterator<int>(cout, " "));
    cout<<"Min :"<<findMin(data)<<endl;

    vector<int> data1{9, 1,2,3,4,5, 6, 7, 8};
    copy(data1.begin(), data1.end(), ostream_iterator<int>(cout, " "));
    cout<<"Min :"<<findMin(data1)<<endl;

    vector<int> data2{9,10,11,12, 13, 14, 15,16,17, 1,2,3,4,5, 6, 7, 8};
     copy(data2.begin(), data2.end(), ostream_iterator<int>(cout, " "));
    cout<<"Min :"<<findMin(data2)<<endl;

}