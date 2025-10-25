#include <bits/stdc++.h>

using namespace std;

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

    vector<vector<int>> levelOrder(Node* root){
        vector<vector<int>> result;

        if(root == nullptr) return result;

        queue<Node*> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            vector<int> level;

            for(int i = 0; i < size; i++){
                Node* node = q.front();
                q.pop();

                if(node->left != nullptr) q.push(node->left);
                if(node->right != nullptr) q.push(node->right);

                level.push_back(node->data);
            }

            result.push_back(level);
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
    vector<vector<int>> result = sol.levelOrder(root);
    for(const auto& level : result){
        for(int val : level){
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}