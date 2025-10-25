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

void postorder(Node* root, vector<int> &result){
    if(root == NULL){
        return;
    }
    postorder(root->left, result);
    postorder(root->right, result);
    result.push_back(root->data);
}

vector<int> postorderTraversal(Node* root){
    vector<int> result;
    postorder(root, result);
    return result;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    
    vector<int> result = postorderTraversal(root);
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }
    return 0;
}