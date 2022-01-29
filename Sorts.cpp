#include <bits/stdc++.h>

using namespace std;

int generateRandom(int max_num) {
    return rand() % max_num;
}

//Merge two sorted array
void merge(vector<int> &nums , int s1, int s2, int e2) {
    size_t sz = e2 - s1 + 1;
    vector<int> marr(sz,0);
    int i = s1;
    int j = s2;
    int k = 0;
    while(i < s2 and j < e2) {
        if(nums[i] < nums[j])
            marr[k++] = nums[i++];
        else
            marr[k++] = nums[j++];
    }

    if (i < s2) {
        while (i < s2) {
            marr[k++] = nums[i++];
        }
    }

    if (j < e2) {
        while (j < e2) {
            marr[k++] = nums[j++];
        }
    }

    //copy back
    for (i = s1; i < e2; i++) {
        nums[i] = marr[i-s1];
    }
}

void mergeSort(vector<int> &nums, int s, int e) {
    if ( e - s <= 1) return;
    //split
    int mid = (s + e)/2;
    mergeSort(nums, s, mid);
    mergeSort(nums, mid, e);
    merge(nums, s, mid, e);
} 

int partition(vector<int>& nums, int s, int e) {
    int pivot = nums[e];
    int i = s - 1;
    for (int j = s; j < e; j++) {
        if (nums[j] <= pivot) {
            i  += 1;
            swap(nums[i], nums[j]);
        }
    }
    swap(nums[i+1], nums[e]);
    return i+1;
}

void quickSort(vector<int> &nums, int s, int e) {
    if (s >= e) return;
    int p = partition(nums, s, e);
    quickSort(nums, s, p-1);
    quickSort(nums, p+1, e);
}

//Counting Sort
vector<int> countingSort(vector<int>& nums, int max) {
    vector<int> carr(max, 0);
    for (int n : nums) {
        carr[n]++;
    }

    //accumulate
    for (int i = 1; i < max; i++) {
        carr[i] += carr[i-1];
    }

    vector<int> res(nums.size(), 0);
    for (int i = nums.size()-1; i >= 0; i--) {
        res[carr[nums[i]]-1] = nums[i];
        carr[nums[i]]--;
    }
    return res;
}

void countingSort_d(vector<int> &nums,int d) {
    vector<int> carr(10, 0);
    for(auto n: nums) {
        int v = (n/(int)pow(10,d)) % 10;
        carr[v]++;
    }

    //accumulate
    for(int i = 1; i < carr.size(); i++)
        carr[i]+= carr[i-1];
    
    vector<int> res(nums.size(), 0);
    for(int i = nums.size()-1; i >= 0; i--) {
        int v = (nums[i]/(int) pow(10,d)) % 10;
        res[carr[v]-1] = nums[i];
        carr[v]--; 
    }

    //copy back
    for (int i = 0; i < nums.size(); i++) {
        nums[i] = res[i];
    }

}

void radixSort(vector<int> &nums) {
    for (int i = 0; i < 4; i++) {
        countingSort_d(nums, i);
        copy(nums.begin(), nums.end(), ostream_iterator<int>(cout, " "));
        cout<<endl;
    }
}

int main() {
    srand(time(0));
    size_t sz = 20;
    vector<int> nums(sz,0);
    for (int i = 0; i < sz; i++) {
        nums[i] = generateRandom(5000);
    }
    cout<<"Nums   : ";
    copy(nums.begin(), nums.end(), ostream_iterator<int>(cout, " "));
    cout<<endl;
    //quickSort(nums, 0, nums.size()-1);
    radixSort(nums);
    cout<<"Sorted : ";
    copy(nums.begin(), nums.end(), ostream_iterator<int>(cout, " "));
    cout<<endl;
    return 0;
}