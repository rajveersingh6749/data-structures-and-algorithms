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

    Node* lca(Node* root, Node* p, Node* q){
        if(root == NULL || root == p || root == q) return root;

        Node* left = lca(root->left, p, q);
        Node* right = lca(root->right, p, q);

        if(left == NULL) return right;
        else if(right == NULL) return left;
        else return root;
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
    Node* lca = sol.lca(root, root->left->left, root->left->right);
    cout << lca->data << endl;
    return 0;
}