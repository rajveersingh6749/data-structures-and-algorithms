#include <iostream>
#include <vector>

using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node():data(0),left(nullptr),right(nullptr){}
    Node(int data):data(data),left(nullptr),right(nullptr){}
    Node(int data,Node* left,Node* right):data(data),left(left),right(right){}
};

class Solution{
    public:
    bool getPath(Node* root,int target,vector<int>& path){
        if(!root) return false;

        path.push_back(root->data);

        if(root->data == target) return true;

        if(getPath(root->left,target,path) || getPath(root->right,target,path)) return true;

        path.pop_back();
        return false;
    }


    vector<int> rootToNodePath(Node* root,int target){
        vector<int> path;

        if(!root) return path;
        getPath(root,target,path);
        return path;
    }
};

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(6);
    root->left->right->right = new Node(7);

    Solution sol;
    vector<int> path = sol.rootToNodePath(root,7);
    for(int i=0;i<path.size();i++){
        cout<<path[i]<<" ";
    }
    cout<<endl;
    return 0;
}