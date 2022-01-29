#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <limits.h>

using namespace std;
int RandomNumber () { return (std::rand()%100); }
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// ============== UTils =====================================
void dumpList(ListNode *tmp) {
    cout<<"List : ";
    while(tmp) {
        cout<<tmp->val<<" ";
        tmp = tmp->next;
    }
    cout<<endl;
}

void freeList(ListNode *root) {
    while(root) {
        ListNode *tmp = root;
        root = root->next;
        delete tmp;
    }
}

ListNode* createList(vector<int> &nums) {
    ListNode *head = nullptr;
    ListNode *curr = nullptr;
    for (int e: nums) {
        ListNode *tmp = new ListNode(e);
        if (head == nullptr) {
            head = tmp;
            curr = tmp;
        } else {
            curr->next = tmp;
            curr = tmp;
        }
    }
    return head;
}

struct MinHeapNode {
    ListNode *c;
    ListNode *next; //next pointerto take
};

void swap1(MinHeapNode *n1, MinHeapNode *n2) {
    MinHeapNode tmp = *n1;
    *n1 = *n2;
    *n2 = tmp;
}

class MinHeap {
    MinHeapNode *harr;
    int size;
public:
    MinHeap(MinHeapNode *v, int s) {
        harr = v;
        size = s;
        for (int i = s/2-1; i>= 0; i--) {
            heapify(i);
        }
        cout<<"Created heap of sie "<<s<<endl;
        printHeap();
    }
    
    void heapify(int i) {
        int l = 2*i + 1;
        int r = 2*i + 2;
        int smallest = i;
        if (l < size and harr[l].c->val < harr[smallest].c->val)
            smallest = l;
        if (r < size and harr[r].c->val < harr[smallest].c->val)
            smallest = r;

        if(smallest != i) {
            swap1(&harr[smallest], &harr[i]);
            heapify(smallest);
        }
    }

    //Remove first element
    void pop() {
        swap1(&harr[0], &harr[size-1]);
        size -= 1;
        heapify(0);
    }

    bool isEmpty() {
        return size == 0;
    }

    bool replace(MinHeapNode m) {
        harr[0] = m;
        heapify(0);
    }

    MinHeapNode getMin() {
        return harr[0];
    }
    
    void printHeap() {
        cout<<"Heap : ";
        for (int i = 0; i < size; i++) {
            cout<<harr[i].c->val<<" ";
        }
        cout<<endl;
    }
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
    ListNode *root = nullptr;
    ListNode *curr = nullptr;

    int sz = lists.size();
    if (sz == 0) return nullptr;
    MinHeapNode har[sz];
    int hsz = 0;
    for (int i = 0; i < sz; i++ ) {
        if (lists[i] != nullptr) {
            har[hsz].c = lists[i];
            har[hsz].next = lists[i]->next;
            hsz++;
        }
    }

    MinHeap min_heap(har, hsz);
    while (not min_heap.isEmpty()) {
        min_heap.printHeap();
        MinHeapNode m = min_heap.getMin();
        if (root == nullptr) {
            root = curr = m.c;
        } else {
            curr->next = m.c;
            curr = m.c;
        }
        if (m.next != nullptr) {
            m.c = m.next;
            m.next = m.c->next;
            min_heap.replace(m);
        } else {
            min_heap.pop();
        }
    }
    return root;
}


int main() {
    vector<ListNode*> arrays;
    srand(time(0));

    for (int i = 0; i < 5; i++) {
        vector<int> vec(6,0);
        generate(vec.begin(), vec.end(), RandomNumber);
        sort(vec.begin(), vec.end());
        cout<<"Vector "<<i<<" : ";
        copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
        cout<<endl;
        ListNode *r = createList(vec);
        arrays.push_back(r);
    }
    
    ListNode *srt = mergeKLists(arrays);
    cout<<"Sorted : ";
    dumpList(srt);
    freeList(srt);
    cout<<endl;
    return 0;
}