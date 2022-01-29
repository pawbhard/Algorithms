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

int search_worker(vector<int> nums, int start, int end, int target) {
    
    int mid = (end + start) / 2;
    if (nums[mid] == target) {
        return mid;
    }
    if (start > end) return -1;

    if (nums[start] <= nums[mid]) {
        //First part is sorted
        if (target < nums[mid] and target >= nums[start]) {
            return search_worker(nums, start, mid-1, target);
        } else {
            return search_worker(nums, mid+1, end, target);
        }
    } else {
        //Second part is sorted
        if (target > nums[mid] and target <= nums[end]) {
            return search_worker(nums, mid+1, end, target);
        } else {
            return search_worker(nums, start, mid-1, target);
        }
    }
}

int search(vector<int>& nums, int target) {
    return search_worker(nums, 0, nums.size()-1, target);
}

int main() {
    vector<int> data{1,2,3,4,5};
    int i{0};
    copy(data.begin(), data.end(), ostream_iterator<int>(cout, " "));
    do {
        cin>>i;
        cout<<"Index :"<<search(data, i)<<endl;
    } while (i != -1);

    vector<int> data1{9, 1,2,3,4,5, 6, 7, 8};
    copy(data1.begin(), data1.end(), ostream_iterator<int>(cout, " "));
    do {
        cin>>i;
        cout<<"Index :"<<search(data1, i)<<endl;
    } while(i!= -1);
    vector<int> data2{9,10,11,12, 13, 14, 15,16,17, 1,2,3,4,5, 6, 7, 8};
     copy(data2.begin(), data2.end(), ostream_iterator<int>(cout, " "));
    do {
        cin>>i;
        cout<<"Index :"<<search(data2, i)<<endl;
    } while (i!= -1);
}
