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
    vector<int> preorderTraversal(Node* root){
        vector<int> result;
        if(root == NULL){
            return result;
        }
        stack<Node*> st;
        st.push(root);
        while(!st.empty()){
            Node* curr = st.top();
            st.pop();
            result.push_back(curr->data);
            if(curr->right != NULL){
                st.push(curr->right);
            }
            if(curr->left != NULL){
                st.push(curr->left);
            }
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
    vector<int> result = sol.preorderTraversal(root);
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }
    return 0;
}