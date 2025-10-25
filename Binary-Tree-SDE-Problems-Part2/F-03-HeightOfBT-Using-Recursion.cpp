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

    int height(Node* root){
        if(root == nullptr) return 0;

        return (1 + max(height(root->left), height(root->right)));
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
    int height = sol.height(root);
    cout << "Height of the Binary Tree is: " << height << endl;
    return 0;
}