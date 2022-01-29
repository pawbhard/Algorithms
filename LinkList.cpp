#include <iostream>
#include <vector>

using namespace std;

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

//============================================================

ListNode* reverseList(ListNode* head) {
    if (head == nullptr) return head;
    ListNode *prev = nullptr;
    ListNode *curr = head;
    while (curr) {
        ListNode *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

//============================================================

bool hasCycle(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head;

    while(slow and fast) {
        slow = slow->next;
        if (fast->next)
            fast = fast->next->next;
        else
            return false;
        if (slow == fast)
            return true;
    }
    return false;
}

//============================================================

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode *head = nullptr;
    ListNode *curr = nullptr;

    while(list1 and list2) {
        if (list1->val <= list2->val) {
            if (head == nullptr) {
                head = list1;
                curr = list1;
            } else {
                curr->next = list1;
                curr = curr->next;
            }
            list1 = list1->next;
        } else {
            if (head == nullptr) {
                head = list2;
                curr = list2;
            } else {
                curr->next = list2;
                curr = curr->next;
            }
            list2 = list2->next;
        }
    }

    while (list1) {
        if (head == nullptr) {
            head = list1;
            curr = list1;
        } else {
            curr->next = list1;
            curr = curr->next;
        }
        list1 = list1->next;
    }

    while (list2) {
        if (head == nullptr) {
            head = list2;
            curr = list2;
        } else {
            curr->next = list2;
            curr = curr->next;
        }
        list2 = list2->next;
    }

    return head;
}

//============================================================

ListNode* removeNthFromEnd(ListNode* head, int n) {
    if(head == nullptr) return head;
    
    ListNode *forward= head, *backward = head;
    int i{0};
    for (i = 1; i <= n; i++) {
        if(forward == nullptr) {
            break;
        } else {
            forward = forward->next;
        }
    }
    if (i != n+1) {
        cout<<"List is short" <<endl;
        return head;
    }

    ListNode *tmp;
    //Need to remove first element
    if(forward == nullptr) {
        tmp = head;
        head = head->next;
    } else {
        while(forward->next) {
            backward = backward->next;
            forward = forward->next;
        }
        tmp = backward->next;
        backward->next = tmp->next;
    }
    delete tmp;
    return head;
}

//============================================================
/* L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …*/
// split reverse merge
int getLength(ListNode *head) {
    int len = 0;
    while(head) {
        len++;
        head = head->next;
    }
    return len;
}

void reorderList(ListNode* head) {
    if (head == nullptr) return;
    if (head->next == nullptr) return;

    ListNode *fast= head;
    ListNode *slow = head;
    while(fast and fast->next) {
        fast = fast->next;
        fast = fast->next;
        slow = slow->next;
    }

    cout<<"Middle is "<<slow->val<<endl;
    ListNode *middle = reverseList(slow->next);
    slow->next = nullptr;
    ListNode *init = head;
    while(middle) {
        ListNode* tmp = init->next;
        init->next = middle;
        middle = middle->next;
        init->next->next = tmp;
        init = tmp;
    }
    return;
}

ListNode * _reorderList(ListNode *head, int len){
    if(len == 0)
        return NULL;
    if( len == 1 )
        return head;
    if( len == 2 )
        return head->next;
    ListNode * tail = _reorderList(head->next, len-2);
    cout<<"Tail " <<tail->val<<" Head "<<head->val<<endl;
    ListNode * tmp = tail->next;
    tail->next = tail->next->next;
    tmp->next = head->next;
    head->next = tmp;
    cout<<"Tail " <<tail->val<<" Head "<<head->val <<endl;
    dumpList(head);
    return tail;
}

void reorderList_recur(ListNode *head) {  //recursive
    ListNode  * tail = NULL;
    tail = _reorderList(head, getLength(head));
}
//============================================================
string getVal(ListNode *t) {
    if (t) return to_string(t->val);
    else return "null";
}
//Reverse again practice recursion
ListNode* reverseList_1(ListNode *head, int K) {
    
    ListNode *_head = nullptr;
    ListNode *currHead = head;
    ListNode *prevTail = nullptr;

    while (currHead) {
        ListNode* curr = currHead;
        ListNode* prev = prevTail;
        int k = 1; ListNode *tmp = curr;
        while((tmp = tmp->next)) {
            if(k == K) break;
            k++;
        }
        cout<<k<<"\n";
        if(k != K) break;
        while(curr and k--) {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        cout<<"Linking CurrHead:"<<getVal(currHead)<<" curr:"<<getVal(curr)<<"\n";
        currHead->next = curr;
        if(prevTail) prevTail->next = prev;
        prevTail = currHead;
        currHead = curr;

        if (not _head) _head = prev;
    }
    return _head;
}




int main() {
    vector<int> nums{1,2,3,4,5,6,7,8,9,10,11,12,13,14};
    ListNode *head = createList(nums);
    dumpList(head);
 /*   head = reverseList(head);
    dumpList(head);
    head = reverseList(head);
    dumpList(head);
    cout<<hasCycle(head)<<endl;
    reorderList_recur(head);
    dumpList(head);
    cout<<"++++++++++++++++++\n"; */
    head = reverseList_1(head, 1);
    dumpList(head);
 /*   int N{0};
    do {
        dumpList(head);
        cout<<"Enter Node to Remove :";
        cin >> N;
        head = removeNthFromEnd(head, N);
        
    }while (N != 0);
    */
    return 0;
}