#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

// simple approach coder army youtube channel
// coder army approach: first find NRL(preorder with small changes like change the order of the calls) then reverse it that becomes LRN (postorder)         


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
        stack<Node*> st;
        st.push(root);
        while(!st.empty()){
            Node* curr = st.top();
            st.pop();
            result.push_back(curr->data);
            if(curr->left != NULL){
                st.push(curr->left);
            }
            if(curr->right != NULL){
                st.push(curr->right);
            }
        }
        reverse(result.begin(), result.end());
        return result;
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

    Solution obj;
    vector<int> result = obj.postorderTraversal(root);
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }
    return 0;
}