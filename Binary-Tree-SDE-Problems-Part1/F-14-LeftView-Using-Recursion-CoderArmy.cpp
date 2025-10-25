#include <iostream>
#include <vector>

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

    void leftView(Node* root, int level, vector<int>& ans){
        if(!root) return;
        if(level == ans.size()){
            ans.push_back(root->data);  
        }
        leftView(root->left,level+1,ans);
        leftView(root->right,level+1,ans);
    }

    vector<int> leftView(Node* root){
        vector<int> ans;
        leftView(root,0,ans);
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
    root->left->right->left = new Node(7);
    root->left->right->right = new Node(8);
    root->left->right->right->right = new Node(9);

    Solution sol;
    vector<int> ans = sol.leftView(root);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}