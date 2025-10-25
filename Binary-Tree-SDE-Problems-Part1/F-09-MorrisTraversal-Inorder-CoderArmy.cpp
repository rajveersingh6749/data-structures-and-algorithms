#include <iostream>
#include <vector>

using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(): data(0), left(NULL), right(NULL){}
    Node(int val): data(val), left(NULL), right(NULL){}
    Node(int val, Node* left, Node* right): data(val), left(left), right(right){}
};

vector<int> inorderMorrisTraversal(Node* root){
    vector<int> result;

    while(root){
        // if left is null then print the data and move to right
        if(!root->left){
            result.push_back(root->data);
            root = root->right;
        }
        else{
            // find the rightmost node in the left subtree
            Node* curr = root->left;
            while(curr->right && curr->right != root){
                curr = curr->right;
            }
            // if left subtree not traversed
            if(curr->right == NULL){
                curr->right = root;
                root = root->left;
            }else{ // already traversed
                curr->right = NULL;
                result.push_back(root->data);
                root = root->right;
            }
        }
    }
    return result;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    vector<int> result = inorderMorrisTraversal(root);
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }
    return 0;
}