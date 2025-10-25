#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// coder army solution using level order traversal

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

    vector<int> bottomView(Node* root){
        int l = 0, r = 0;
        find(root,0,l,r);
        vector<int> ans(r - l + 1);
        vector<int> vis(r - l + 1, 0);
        queue<Node* > q;
        queue<int> index;

        q.push(root);
        index.push(-1 * l);

        while(!q.empty()){
            Node* temp = q.front();
            q.pop();
            int pos = index.front();
            index.pop();

            // if(!vis[pos]){
            //     vis[pos] = 1;
                ans[pos] = temp->data;
            // }

            if(temp->left){
                q.push(temp->left);
                index.push(pos - 1);
            }
            
            if(temp->right){
                q.push(temp->right);
                index.push(pos + 1);
            }
        }
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
    root->right->right->left = new Node(9);
    root->right->right->left->left = new Node(12);
    root->right->right->right = new Node(10);
    root->right->right->right->left = new Node(13);
    root->left->left->left = new Node(7);
    root->left->left->right = new Node(8);
    root->left->left->left->left = new Node(11);

    Solution sol;
    vector<int> ans = sol.bottomView(root);
    for(int i = 0; i < ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}