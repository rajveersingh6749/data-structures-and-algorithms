#include <bits/stdc++.h>
using namespace std;

// Coder Army Solution

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

    int height(Node* root, bool &valid){
        if(root == NULL) return 0;

        int lh = height(root->left, valid);
        int rh = height(root->right, valid);

        if(abs(lh - rh) > 1){
            valid = 0;
        }

        return max(lh, rh) + 1;
    }

    bool isBalanced(Node* root){
        bool valid = 1;

        height(root, valid);
        return valid;
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
    cout << sol.isBalanced(root) << endl;
    return 0;
}