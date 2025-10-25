#include <iostream>
#include <vector>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

void inorder(Node* root, vector<int> &result){
    if(root == NULL){
        return;
    }
    inorder(root->left, result);
    result.push_back(root->data);
    inorder(root->right, result );
}

vector<int> inorderTraversal(Node* root){
    vector<int> result;
    inorder(root, result);
    return result;
}


int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    vector<int> result = inorderTraversal(root);
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }
    return 0;
}
