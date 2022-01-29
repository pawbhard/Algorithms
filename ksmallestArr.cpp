#include <bits/stdc++.h>

using namespace std;

//find smallest k elements from an array
typedef long long int ll;
#define MAX 50000
//generate random
void array_random(vector<int> &nums, ll sz) {
    nums.resize(sz, 0);
    for (ll i = 0; i < sz; i++) {
        nums[i] = rand() % MAX;
    }
}

class heap {
    ll heap_sz;
    vector<int> heap_arr;

    public:
    heap(vector<int> &nums, ll sz) {
        heap_arr.resize(sz, 0);
        for(int i = 0; i < sz; i++)
            heap_arr[i] = nums[i];
        heap_sz = sz;
    }

    void heapify(int i) {
        if (i >= heap_sz) return;
        //cout<<"Heapify called with "<<i<<endl;
        int lc = 2*i+1;
        int rc = 2*i+2;
        int min = i;
        if (lc < heap_sz and heap_arr[min] < heap_arr[lc]) min = lc;
        if (rc < heap_sz and heap_arr[min] < heap_arr[rc]) min = rc;

        if (min != i) {
            swap(heap_arr[min], heap_arr[i]);
            heapify(min);
        }
    }

    void constructHeap() {
        for (ll i = heap_sz/2; i >= 0; i--) {
            heapify(i);
        }
    }

    int getMin() {
        return heap_arr[0];
    }

    int replaceMin(int val) {
        heap_arr[0] = val;
        heapify(0);
    }

    void dump() {
        cout<<"Dump: ";
        for(ll i = 0; i < heap_sz; i++) cout<<heap_arr[i]<<" ";
        cout<<"\n";
    }
};

int main() {
    vector<int> n;
    ll s = 99000;
    srand(time(0));
    array_random(n,s);
    //copy(n.begin(), n.end(), ostream_iterator<int>(cout, " ")); cout<<"\n";
    //Find  k smallest element
    int k = 50;
    heap *obj = new heap(n, k);
    obj->constructHeap();
    for(int j = 3; j < s; j++) {
        if (n[j] < obj->getMin()) {
            obj->replaceMin(n[j]);
        }
    }
    obj->dump();
    sort(n.begin(), n.end());
    //copy(n.begin(), n.end(), ostream_iterator<int>(cout, " ")); cout<<"\n";
    return 0;
}