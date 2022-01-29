#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void printStack(stack<TreeNode*> st) {
    cout<<"\nStack: ";
    while(not st.empty()) {
        cout<<st.top()->val<<" ";
        st.pop();
    }
    cout<<endl;
}
void preOrder(TreeNode *root) {
    stack<TreeNode*> st;
    TreeNode *tmp;
    st.push(root);
    cout<<"Preorder: ";
    while(not st.empty()) {
        tmp = st.top();
        st.pop();
        cout<<tmp->val<<" ";
        if (tmp->right) st.push(tmp->right);
        if (tmp->left) st.push(tmp->left);
    }
    cout<<endl;
}

void inOrder(TreeNode *root) {
    stack <TreeNode*> st;
    TreeNode *curr = root;
    cout<<"INorder : ";

    st.push(root);
    curr = curr->left;

    while(not st.empty() or curr) {
        //printStack(st);
        if (curr) {
            st.push(curr);
            curr = curr->left;
        } else {
            curr = st.top();
            st.pop();
            cout<<curr->val<<" ";
            curr = curr->right;
        }
    }
    cout<<endl;
}

void postOrder(TreeNode* root) {
    stack<TreeNode*> st;
    cout<<"PostOrder :";
    TreeNode *curr = root;
    st.push(root);
    st.push(root);
    curr = curr->left;
    while(not st.empty()) {
        //printStack(st);
        if (curr) {
            st.push(curr);
            st.push(curr);
            curr = curr->left;
        } else {
            curr = st.top();
            st.pop();
            if (not st.empty() and curr == st.top()) {
                curr = curr->right;
            } else {
                cout<<curr->val<<" ";
                curr = nullptr; 
            }
        }
    }

    cout<<endl;
}

int maxDepth(TreeNode* root) {
    if (root == nullptr) return 0;

    int ltree = maxDepth(root->left);
    int htree = maxDepth(root->right);

    return 1 + max(ltree, htree);
}

bool isSameTree(TreeNode* p, TreeNode* q) {
    if(p == nullptr and q == nullptr) return true;
    if(p == nullptr or q == nullptr) return false;

    if (p->val != q->val) return false;

    return isSameTree(p->left, q->left) and isSameTree(p->right, q->right); 
}

TreeNode* invertTree(TreeNode* root) {
    if (root == nullptr) return nullptr;

    TreeNode *tmp = root->right;
    root->right = invertTree(root->left);
    root->left = invertTree(tmp);

    return root;
}

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<TreeNode*>> res{};
    vector<vector<int>> ans{};
    if (root == nullptr) return ans;
    int level = 0;
    res.push_back(vector<TreeNode*> {root});
    while(true) {
        vector<TreeNode*> v{};
        vector<TreeNode*> parent = res[level];

        for (TreeNode *t : parent) {
            if (t->left != nullptr)
                v.push_back(t->left);
            if (t->right != nullptr)
                v.push_back(t->right);
        }

        if (v.size() == 0) break;
        level += 1;
        res.push_back(v);
    }

    for (auto v: res) {
        vector<int> vi{};
        for (TreeNode *t  : v) {
            vi.push_back(t->val);
        }
        ans.push_back(vi);
    }

    return ans;
}
vector<vector<int>> levelOrder1(TreeNode* root) {
    vector<vector<int>> res{};
    queue<TreeNode*> q;
    if (root == nullptr) return res;
    q.push(root);
    q.push(nullptr); //to mark end

    while(not q.empty()) {
        
        TreeNode *p = nullptr;
        vector<int> vec{};
        while(true) {
            p = q.front();
            q.pop();
            if (p != nullptr) {
                vec.push_back(p->val);
                if (p->left) q.push(p->left);
                if (p->right) q.push(p->right);
            } else {
                if (vec.size() != 0) {
                    res.push_back(vec);
                    q.push(nullptr);
                }
                break;
            }
        }
    }
    return res;
}

bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    if (root == nullptr) return false;

    return isSameTree(root, subRoot) or isSubtree(root->left, subRoot) or isSubtree(root->right, subRoot);
}

bool check(TreeNode* root, long _min, long _max) {
    if (root == nullptr) return true;

    if (root->val <= _min or  root->val >= _max)
        return false;
    
    return check(root->left, _min, root->val) and check(root->right, root->val, _max);

}
bool isValidBST(TreeNode* root) {
    return check(root, LONG_MIN, LONG_MAX);
}
bool search(TreeNode * root, TreeNode *node) {
    if (root == nullptr) return false;
    if (root == node) return true;
    else return search(root->left, node) or search(root->right, node);
}
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root== nullptr) return nullptr;
    if(root == p and search(root, q)) return root;
    if (root == q and search(root, p)) return root;

    TreeNode* l = lowestCommonAncestor(root->left, p, q);
    if (l != nullptr) return l;
    TreeNode *r = lowestCommonAncestor(root->right , p, q);
    if (r != nullptr) return r;

    if (root != nullptr) {
        if ((search(root->left, p) and search(root->right, q)) or 
            (search(root->right, p)and search(root->left, q))) {
                return root;
            }
    }
    return nullptr;
}

TreeNode* _worker(vector<int>& preorder, vector<int>& inorder, int &rIdx, int left, int right) {
    
    if (left > right) return nullptr;
    
    int val = preorder[rIdx];
    TreeNode *root = new TreeNode(val);
    int pvt = left;
    while(inorder[pvt] != val and pvt != right) pvt++;
    //assert(pvt != right);
    rIdx++;
    root->left = _worker(preorder, inorder, rIdx, left, pvt-1);
    root->right = _worker(preorder, inorder, rIdx, pvt+1, right);
    return root;
}
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int rIdx = 0;
    return _worker(preorder, inorder, rIdx, 0, inorder.size()-1 );

}

//================================
//Tree is BST

int kthSmallest(TreeNode* root, int k) {
    stack<TreeNode*> st{};
    TreeNode *curr = root;
    while(not st.empty() or curr) {
        if(curr) {
            st.push(curr);
            curr = curr->left;
        } else {
            curr = st.top();
            st.pop();
            if (k == 1) return curr->val;
            else k--;
            curr = curr->right;
        }
    }
}


int _maxPathSum(TreeNode* root, int& max_path_sum) {
    if (root == nullptr) return 0;
    int l = max(_maxPathSum(root->left, max_path_sum), 0);
    int r = max(_maxPathSum(root->right, max_path_sum), 0);
    int val = root->val + l + r;
    if (val > max_path_sum) {
        max_path_sum = val;
    }
    return root->val+ max(l,r);        
}
int maxPathSum(TreeNode *root) {
    int max_path_sum = INT_MIN;
    _maxPathSum(root, max_path_sum);
    return max_path_sum;
}


// Encodes a tree to a single string.
string serialize(TreeNode* root) {
    if(root == nullptr) return "#";
    
    return to_string(root->val) + ","+serialize(root->left) + ","+serialize(root->right);
}

// Decodes your encoded data to tree
TreeNode* _deserialize(queue<string> &parts) {
    string s = parts.front();
    parts.pop();
    if (s == "#") {
        return nullptr;
    } else {
        TreeNode * root = new TreeNode(stoi(s));
        root->left = _deserialize(parts);
        root->right = _deserialize(parts);
        return root;
    }

}

TreeNode* deserialize(string data) {
    stringstream ss;
    ss<<data;
    queue<string> parts;
    string s;
    char delimiter=',';
    while(getline(ss, s,delimiter)) {
        parts.push(s);
    }
    return _deserialize(parts);
}

int main() {
    TreeNode t4(4), t8(8), t3(3),t9(9), t20(20), t15(15), t7(7);

    t3.left = &t9;
    t3.right = &t20;
    t20.left = &t15;
    t20.right = &t7;
    t9.left = &t4;
    t9.right = &t8;
    
    vector<vector<int>> res = levelOrder1(&t3);
    cout<<"[";
    for( auto v : res) {
        cout<<"[";
        for (int e: v) {
            cout<<e<<" ";
        }
        cout<<"]";
    }
    cout<<"]"<<endl;

    vector<int> pre{1,2,4,8,9,5,10,3,6,7,11,12,13};
    vector<int> in {8,9,4,2,5,10,1,6,3,11,7,13,12};
    TreeNode *root = buildTree(pre, in);
    preOrder(root);
    postOrder(root);
    inOrder(root);
    TreeNode *t = lowestCommonAncestor(&t3 ,&t15, &t20);
    cout<<t->val<<endl;
    cout<<maxPathSum(root)<<endl;
    
    res = levelOrder1(root);
    cout<<"[";
    for( auto v : res) {
        cout<<"[";
        for (int e: v) {
            cout<<e<<" ";
        }
        cout<<"]";
    }
    cout<<"]"<<endl;

    string ss = serialize(root);
    cout<<ss<<endl;
    TreeNode *nroot = deserialize(ss);
    preOrder(nroot);   
    return 0;

}