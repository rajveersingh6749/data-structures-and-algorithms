#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Coder Army Solution Using Recursion

struct Node{
    int data;
    Node* left;
    Node* right;
    Node():data(0),left(nullptr),right(nullptr){}
    Node(int x):data(x),left(nullptr),right(nullptr){}
    Node(int x,Node* left,Node* right):data(x),left(left),right(right){}
};


class Solution{
    public:

    void find(Node* root, int pos, int &l, int &r){
        if(!root) return;
        l = min(l,pos);
        r = max(r,pos);
        find(root->left,pos-1,l,r);
        find(root->right,pos+1,l,r);
    }

    void Tview(Node* root, int pos, vector<int> &ans, vector<int> &level, int l){
        if(!root) return;

        if(level[pos] > l){
            ans[pos] = root->data;
            level[pos] = l;
        }

        Tview(root->left,pos-1,ans,level,l+1);
        Tview(root->right,pos+1,ans,level,l+1);
    }

    vector<int> topView(Node* root){
        int l = 0, r = 0;
        find(root,0,l,r);
        vector<int> ans(r-l+1);
        vector<int> level(r-l+1, INT_MAX);
        Tview(root,-1*l,ans,level,0);
        return ans;
    }
};

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    root->left->left->left = new Node(7);
    root->left->left->right = new Node(8);
    root->right->right->left = new Node(9);
    root->right->right->right = new Node(10);
    root->left->left->left->left = new Node(11);
    root->right->right->left->left = new Node(12);
    root->right->right->left->right = new Node(13);
    root->right->right->left->right->right = new Node(14);

    Solution sol;   
    vector<int> ans = sol.topView(root);
    for(int i = 0; i < ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}

    
    