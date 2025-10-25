#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(): data(0), left(nullptr), right(nullptr) {}
    Node(int data): data(data), left(nullptr), right(nullptr) {}
    Node(int data, Node* left, Node* right): data(data), left(left), right(right) {}
};

class Solution{
    public:

    vector<vector<int>> zigzagTraversal(Node* root){
        vector<vector<int>> ans;
        if(root == NULL) return ans;

        queue<Node*> q;
        q.push(root);

        bool leftToRight = true;

        while(!q.empty()){
            int size = q.size();
            vector<int> level(size);

            for(int i = 0; i < size; i++){
                Node* node = q.front();
                q.pop();

                int index = leftToRight ? i : size - i - 1;
                level[index] = node->data;

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }

            ans.push_back(level);
            leftToRight = !leftToRight;
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
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Solution sol;
    vector<vector<int>> ans = sol.zigzagTraversal(root);
    for(auto &level : ans){
        for(auto &node : level){
            cout << node << " ";
        }
        cout << endl;
    }
}