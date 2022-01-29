#include <bits/stdc++.h>
using namespace std;

class SegTree {
    vector<int> seg;
    size_t seg_size;
    vector<int> nums;
    size_t num_size;

    int constructSt(int root, int l, int r) {
        if (root >= seg_size) return INT_MAX;
        int lc = 2*root + 1;
        int rc = 2*root + 2;
        if(l == r) {
            seg[root] = nums[l];
        } else {
            int mid = (l+r)/2;
            seg[root] = min(constructSt(lc, l, mid), constructSt(rc, mid+1,r));
        }
        cout<<" "<<l<<" "<<r<<" "<<seg[root]<<"\n";
        return seg[root];
    }

    int _workerMin(int si, int sl, int sr, int l, int r) {
        
        if (si >= seg_size) return INT_MAX;
        //No overlap
        if (r <  sl or l > sr) return INT_MAX;

        //complete overlap
        if (l <= sl and r >= sr) return seg[si]; 
        
        //partial overlap
        int mid = (sl+sr) / 2;
        return min(_workerMin(2*si+1, sl, mid, l, r) , _workerMin(2*si+2, mid+1, sr, l, r));
    }

    public:
    SegTree(vector<int> &ar) {
        nums = ar;
        num_size = ar.size();
        int height = (int) ceil(log2(num_size));
        seg_size = 2*pow(2,height) - 1;
        seg.resize(seg_size, 0);
        constructSt(0, 0, num_size-1);
    }

    void dump() {
        cout<<"Dump: ";
        copy(seg.begin(), seg.end(), ostream_iterator<int>(cout," "));
        cout<<"\n";
    }

    int findMinQuery(int l, int r) {
        return _workerMin(0, 0, num_size-1, l, r);
    }
};
int findMin(vector<int> &nums, int l, int r) {
    int m = nums[l];
    for(int i = l+1; i <= r; i++) {
        m = m > nums[i] ? nums[i] : m;
    }
    return m;
}

int main() {
    vector<int> nums {2,1,4,7,8,9,2,6,4,3,8,1,2,3,6,8};
    size_t sz = nums.size();
    SegTree *obj = new SegTree(nums);
    obj->dump();
    srand(time(0));
    for(int i = 0; i < 50; i++) {
        int sl = rand() % sz;
        int sr = rand() % sz;
        if (sl > sr) swap(sl, sr);
        int ans1 = findMin(nums, sl, sr);
        int ans2 = obj->findMinQuery(sl,sr);
        cout<<"Testing for sl:"<<sl<<" sr:"<<sr<<"\n";
        if (ans1 != ans2) {
            cout<<"Test Failed for sl:"<<sl<<" sr:"<<sr<<"\n";
            break;
        }
    }
}