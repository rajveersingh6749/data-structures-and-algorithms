#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(): data(0), left(NULL), right(NULL){}
    Node(int val): data(val), left(NULL), right(NULL){}
    Node(int val, Node* left, Node* right): data(val), left(left), right(right){}
};

class Solution{
    public:
    vector<int> postorderTraversal(Node* root){
        vector<int> result;
        if(root == NULL){
            return result;
        }
        stack<Node*> st1;
        stack<Node*> st2;
        st1.push(root);

        while(!st1.empty()){
            Node* root = st1.top();
            st1.pop();
            st2.push(root);
            if(root->left != NULL){
                st1.push(root->left);
            }
            if(root->right != NULL){
                st1.push(root->right);
            }
        }
        while(!st2.empty()){
            result.push_back(st2.top()->data);
            st2.pop();
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
    
    Solution sol;
    vector<int> result = sol.postorderTraversal(root);
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }
    return 0;
}