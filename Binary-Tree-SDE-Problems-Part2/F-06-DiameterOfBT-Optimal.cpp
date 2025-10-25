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

    int height(Node* root, int& diameter){
        if(root == nullptr) return 0;

        int leftHeight = height(root->left, diameter);
        int rightHeight = height(root->right, diameter);

        diameter = max(diameter, leftHeight + rightHeight);

        return 1 + max(leftHeight, rightHeight);
    }


    int diameter(Node* root){
        int diameter = 0;
        height(root, diameter);
        return diameter;
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
    cout << sol.diameter(root) << endl;
    return 0;
}