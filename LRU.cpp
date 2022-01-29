#include <bits/stdc++.h>

using namespace std;

int RandomNumber () { return (std::rand()%100); }

struct DLinkListNode {
    int key;
    int value;
    DLinkListNode *next, *prev;

    DLinkListNode() : key(0), value(0), next(nullptr), prev(nullptr) {}
    DLinkListNode(int k, int v) : key(k), value(v), next(nullptr), prev(nullptr) {}
};

class DLinkList {
    DLinkListNode *front, *rear;
public:
    DLinkList() : front(nullptr), rear(nullptr) {};
    ~DLinkList() {
        cout<<"Deleting Dlinklist"<<endl;
        while(front) {
            DLinkListNode *tmp = front;
            front = front->next;
            delete tmp;
        }
    }

    DLinkListNode * getRear() {
        return rear;
    }
    DLinkListNode * getFront() {
        return front;
    }
    void insert_rear(DLinkListNode *node) {
        if (front == nullptr) {
            front = rear = node;
        } else {
            node->prev = rear;
            rear->next = node;
            rear = node;
            //To avoid cleanup
            rear->next = nullptr;
        }
    }

    void insert_front(DLinkListNode *node) {
        if (front == nullptr) {
            front = rear = node;
        } else {
            node->next = front;
            front->prev = node;
            front = node;
            //To avoid any cleanup
            node->prev = nullptr;
        }
    }

    void removeNode(DLinkListNode *node) {
        if (node == nullptr) return;
        if (node == front) front = front->next;
        if (node == rear) rear = rear->prev;

        DLinkListNode *p = node->prev;
        DLinkListNode *n = node->next;
        if (p) {
            p->next = n;
        }
        if (n) {
            n->prev = p;
        }
    }

    void deleteNode(DLinkListNode *node) {
        removeNode(node);
        delete node;
    }

    void pop_front() {
        deleteNode(front);
    }
    
    void pop_rear() {
        deleteNode(rear);
    }
    
    void move_to_front(DLinkListNode *node) {
        if (node == front) return;

        removeNode(node);
        insert_front(node);
    }

    void dumpList() {
        DLinkListNode *tmp = front;
        cout<<"Front : ";
        while(tmp) {
            cout<<"("<<tmp->key<<", "<<tmp->value<<") ";
            tmp = tmp->next;
        }
        cout<<" : Rear "<<endl;
    } 
};

class LRU {
    //Key - Node
    unordered_map<int, DLinkListNode*> hash_map;
    size_t size;
    DLinkList dq;

public:
    LRU(size_t s) : size(s) {}

    void set(int key, int value) {
        cout<<"Set "<<key<<", "<<value<<endl;
        DLinkListNode *node = nullptr;
        auto it = hash_map.find(key);
        if (it != hash_map.end()) {
            node = it->second;
            node->value = value;
            dq.move_to_front(node);
        } else {
            cout<<"Fault element not found"<<endl;
            if (hash_map.size() == size) {
                DLinkListNode *least_node = dq.getRear();
                hash_map.erase(hash_map.find(least_node->key));   
                dq.pop_rear();
            }
            node = new DLinkListNode(key, value);
            dq.insert_front(node);
            hash_map[key] = node;
        }
    }

    int get(int key) {
        cout<<"Get "<<key<<endl;
        DLinkListNode *node = nullptr;
        auto it = hash_map.find(key);
        if (it != hash_map.end()) {
            node = it->second;
            dq.removeNode(node);
            dq.insert_front(node);
            return node->value;
        }
        return -1;
    }

};


int main() {
    srand(time(0));

    LRU lru(3);
    lru.set(1,10);
    lru.set(2,20);
    lru.set(3, 30);
    cout<<lru.get(1) <<endl;
    lru.set(2,25);
    lru.set(4,40);
    cout<<lru.get(1)<<endl;
    cout<<lru.get(2)<<endl;
    //lru.set();
    //lru.get();
    //lru.get();
    //lru.set();
    //lru.get();
    return 0;
}