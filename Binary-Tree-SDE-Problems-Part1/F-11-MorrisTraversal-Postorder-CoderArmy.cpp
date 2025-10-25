#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(): data(0), left(NULL), right(NULL){}
    Node(int val): data(val), left(NULL), right(NULL){}
    Node(int val, Node* left, Node* right): data(val), left(left), right(right){}
};

// Approach: Postorder means LRN. So we find reverse of it like NRL and then reverse it to get LRN

vector<int> postorderMorrisTraversal(Node* root){
    vector<int> result;
    while(root){
        // if right doesn't exist then print the data and move to left
        if(!root->right){
            result.push_back(root->data);
            root = root->left;
        }
        else{ // if right does exist then find the leftmost node in the right subtree
            Node* curr = root->right;
            while(curr->left && curr->left != root){
                curr = curr->left;
            }
            // if right not traversed
            if(curr->left == NULL){
                result.push_back(root->data);
                curr->left = root;//make the link
                root = root->right;
            }else{ // already traversed
                curr->left = NULL;//remove the link
                root = root->left;
            }
        }
    }
    reverse(result.begin(), result.end());
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

    vector<int> result = postorderMorrisTraversal(root);
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }
    return 0;
}