#include<iostream>

using namespace std;

// Coder Army's Solution using Morris Traversal
struct Node{
    int data;
    Node* left;
    Node* right;

    Node(): data(0), left(nullptr), right(nullptr){}
    Node(int val): data(val), left(nullptr), right(nullptr){}
    Node(int val, Node* left, Node* right): data(val), left(left), right(right){}
};

void flattenBTtoLL(Node* root){
    while(root){
        // if left doesn't exist
        if(!root -> left){
            root = root -> right;
        }
        else{
            Node* curr = root -> left;
            while(curr -> right){
                curr = curr -> right;
            }
            curr -> right = root -> right;
            root -> right = root -> left;
            root -> left = nullptr;
            root = root -> right;
        }
    }
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->right = new Node(6);
    root->right->right = new Node(7);
    root->right->left = new Node(8);

    flattenBTtoLL(root);

    while(root){
        cout << root->data << " ";
        root = root->right;
    }
    return 0;
}