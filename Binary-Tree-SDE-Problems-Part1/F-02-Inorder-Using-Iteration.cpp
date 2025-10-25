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
    vector<int> inorderTraversal(Node* root){
        vector<int> inorder;
        Node* curr = root;
        stack<Node*> st;

        while(true){
            if(curr != NULL){
                st.push(curr);
                curr = curr->left;
            }
            else{
                if(st.empty()) break;
                curr = st.top();
                st.pop();
                inorder.push_back(curr->data);

                curr = curr->right;
            }
        }
        return inorder;
    }
};

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    Solution sol;
    vector<int> result = sol.inorderTraversal(root);
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }
    return 0;
}