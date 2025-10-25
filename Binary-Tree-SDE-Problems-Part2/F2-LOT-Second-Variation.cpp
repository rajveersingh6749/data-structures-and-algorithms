#include <bits/stdc++.h>
using namespace std;

// Coder Army's Solution

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(): data(0), left(nullptr), right(nullptr){}
    Node(int x): data(x), left(nullptr), right(nullptr){}
    Node(int x, Node* left, Node* right): data(x), left(left), right(right){}
};

class Solution{
    public:

    vector<int> levelOrder(Node* root){
        vector<int> result;

        if(root == nullptr) return result;

        queue<Node*> q;
        q.push(root);

        while(!q.empty()){
            Node* temp = q.front();
            q.pop();

            result.push_back(temp->data);

            if(temp->left != nullptr) q.push(temp->left);
            if(temp->right != nullptr) q.push(temp->right);
        }
        return result;
    }
};

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Solution sol;
    vector<int> result = sol.levelOrder(root);
    for(int val : result){
        cout << val << " ";
    }
    cout << endl;
    return 0;
}