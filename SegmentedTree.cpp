#include<bits/stdc++.h>
using namespace std;

class NumArray {
    vector<int> seg;
    size_t seg_len;
    size_t num_len;
    vector<int> arr;
    int constructST(vector<int> &seg, int si, vector<int> &nums, int l, int r) {
        //cout<<" si : "<<si<<" l:"<<l<<" r:"<<r<<endl;
        if (si >= seg_len) return 0;

        if (l == r) //root node
        {
            seg[si] = nums[l];
            return nums[l];
        }
        
        int mid = (l+r)/2;
        seg[si] = constructST(seg, 2*si+1, nums, l, mid)
                + constructST(seg, 2*si+2, nums, mid+1, r);
        return seg[si];
    }
    
    int getSum(int si, int sl, int sr, int l, int r) {
        //cout<<"Called with si:"<<si<<" sl:"<<sl<<" sr:"<<sr<<endl;
        if (si >= seg_len) return 0;
        //no overlap
        if (sr < l or sl > r ) return 0;
        
        //total overlap
        if (l<= sl and r>= sr) return seg[si];
        
        //partial overlap
        int mid = (sl+sr)/2;
        //add left right
        return getSum(2*si+1, sl, mid, l, r) + getSum(2*si+2, mid+1, sr, l, r);
    }
    
    void update_diff(int si, int sl, int sr, int pos, int diff) {
        if (si >= seg_len) return;
        if (sl > pos or sr < pos) return;
        
        seg[si]+= diff;
        if (sl!=sr) {
            int mid = (sl + sr)/2;
            update_diff(2*si+1, sl, mid, pos, diff);
            update_diff(2*si+2, mid+1, sr, pos, diff);
        }
    }
    
public:
    NumArray(vector<int>& nums) {
        int m = nums.size();
        num_len = m-1;
        int h = (int) ceil(log2(m)); //height of the tree
        seg_len = 2*(int)pow(2,h) -1;
        seg = vector<int> (seg_len, 0);
        arr = nums;
        constructST(seg, 0, nums, 0, nums.size()-1);
    }
    
    void update(int index, int val) {
        int diff = val - arr[index];
        update_diff(0, 0, num_len, index, diff);
        arr[index] = val;
    }
    
    int sumRange(int left, int right) {
        return getSum(0, 0, num_len, left, right);    
    }

    void dump() {
        cout<<"Array: ";
        copy(arr.begin(), arr.end(), ostream_iterator<int>(cout," "));
        cout<<"\nSeg Array: ";
        copy(seg.begin(), seg.end(), ostream_iterator<int> (cout, " "));
        cout<<endl;
    }
};

int main() {
    vector<int> nums {7,2,7,2,0};
    NumArray* obj = new NumArray(nums);
    
    vector<string> oper{"update","update","update","sumRange","update","sumRange",
                            "update","sumRange","sumRange","update"};
    vector<vector<int>> param {{4,6},{0,2},{0,9},{4,4},{3,8},{0,4},{4,1},{0,3},{0,4},{0,4}};
    obj->dump();
    for(int i = 0; i < oper.size(); i++) {
        if(oper[i]== "update") {
            cout<<"Update for idx: "<<param[i][0]<<" value:"<<param[i][1]<<endl;;
            obj->update(param[i][0], param[i][1]);
        } else if(oper[i]=="sumRange") {
            cout<<"Calculate sum range for ["<<param[i][0]<<", "<<param[i][1]<<"]"<<" sum = "
                <<obj->sumRange(param[i][0], param[i][1])<<endl;
        }
        obj->dump();
    }
    return 0;
    //obj->update(index,val);
    //int param_2 = obj->sumRange(left,right);
}