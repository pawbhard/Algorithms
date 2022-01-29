#include <bits/stdc++.h>
using namespace std;
bool compare(pair<int,int> a, pair<int,int> b) {
    return a.second < b.second;
}


vector<int> smallestRange(vector<vector<int>>& nums) {
    vector<pair<int,int>> all;
    for (int i = 0; i < nums.size(); i++) {
        for (int n: nums[i]) {
            all.push_back({i, n});
        }
    }
    sort(all.begin(), all.end(), compare);
    vector<int> map(nums.size(),0);
    int counter = nums.size();
    int num_size = nums.size();
    int start = 0, end = 0;
    int low = 0, high = all.size();
    int range = all[high-1].second - all[low].second;

    while(start <= end and end < all.size()) {
        //cout<<"Low : "<<low<<" High : "<<high<<endl;
        if (map[all[end++].first]++ == 0) counter--;

        while(counter == 0) { //valid case
            //update
            
            int new_range = all[end-1].second - all[start].second;
            cout<<"Start "<<start<<" End "<<end<<" Range:"<<new_range<<endl;
            if (new_range < range) {
                range = new_range;
                high =  end;
                low = start;
            }
            if (map[all[start++].first]-- == 1) counter++;
        }
    }
    return vector<int>{all[low].second,all[high-1].second};
}

int main() {
    //[[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]
    vector<int> v1 {4,10,15,24,26};
    vector<int> v2 {0,9,12,20};
    vector<int> v3 {5,18,22,30};

    vector<vector<int>> nums {v1,v2,v3};

    vector<int> res = smallestRange(nums);
    cout<<"[ "<<res[0]<<", "<<res[1]<<"]"<<endl;

    return 0;
}