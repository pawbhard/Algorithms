#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <limits.h>


using namespace std;

int RandomNumber () { return (std::rand()%100); }

struct MinHeapNode {
    int ele;
    int i; //index of array
    int j; //index of next element
};

void swap1(MinHeapNode *x, MinHeapNode *y) {
    MinHeapNode tmp = *x;
    *x = *y;
    *y = tmp; 
}

class MinHeap {
    MinHeapNode *harr;
    int size;

public:
    MinHeap(MinHeapNode *m, int s) {
        harr = m;
        size = s;
        for (int i = s/2-1; i >=0; i--) {
            MinHeapify(i);
        }
    }

    void MinHeapify(int);
    int left(int i) { return 2*i + 1;}
    int right(int i) { return 2*i + 2;}

    MinHeapNode getMin() { return harr[0];}

    //replace root with new node
    void replace(MinHeapNode x) {
        harr[0] = x;
        MinHeapify(0);
    }

    void pop() {
        harr[0] = harr[size-1];
        MinHeapify(0);
        size -= 1;
    }

    bool isEmpty() {
        return size == 0;
    }
};

void MinHeap::MinHeapify(int i) {
    int l = left(i);
    int r = right(i);

    int smallest = i;
    if (l < size and harr[l].ele < harr[smallest].ele) {
        smallest = l;
    }
    if (r < size  and harr[r].ele < harr[smallest].ele) {
        smallest = r;
    }
    if (smallest != i) {
        swap1(&harr[smallest], &harr[i]);
        MinHeapify(smallest);
    }
}
/*
vector<int> mergeKSorted(vector<vector<int>> ar) {
    vector<int> res;
    MinHeapNode har[ar.size()];
    int num_element = 0;
    for (int i = 0; i < ar.size(); i++) {
        har[i].ele = ar[i][0];
        har[i].i = i;
        har[i].j = 1;
        num_element += ar[i].size();
    }
    MinHeap min_heap(har, ar.size());

    for(int i = 0; i < num_element; i++) {
        MinHeapNode m = min_heap.getMin();
        res.push_back(m.ele);
        if(m.j < ar[m.i].size()) {
            m.ele = ar[m.i][m.j];
        } else {
            m.ele = INT_MAX;
        }
        m.j+=1;
        min_heap.replace(m);
    }
    return res;
}
*/
vector<int> mergeKSorted(vector<vector<int>> ar) {
    vector<int> res;
    MinHeapNode har[ar.size()];

    for (int i = 0; i < ar.size(); i++) {
        har[i].ele = ar[i][0];
        har[i].i = i;
        har[i].j = 1;
    }
    MinHeap min_heap(har, ar.size());

    while(not min_heap.isEmpty()) {
        MinHeapNode m = min_heap.getMin();
        res.push_back(m.ele);
        if(m.j < ar[m.i].size()) {
            m.ele = ar[m.i][m.j];
            m.j+= 1;
            min_heap.replace(m);
        } else {
            min_heap.pop();
        }
    }
    return res;
}

int main() {
    vector<vector<int>> arrays;
    srand(time(0));

    for (int i = 0; i < 5; i++) {
        vector<int> vec(6,0);
        generate(vec.begin(), vec.end(), RandomNumber);
        sort(vec.begin(), vec.end());
        cout<<"Vector "<<i<<" : ";
        copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
        cout<<endl;
        arrays.push_back(vec);
    }
    
    vector<int> srt = mergeKSorted(arrays);
    cout<<"Sorted : ";
    copy(srt.begin(), srt.end(), ostream_iterator<int>(cout, " "));
    cout<<endl;
    return 0;
}