#include <iostream>
#include <vector>
#include <stack>

// For another simple approach visit coder army youtube channel
// coder army approach: first find NRL(preorder with small changes like change the order of the calls) then reverse it that becomes LRN

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
        Node* curr = root;
        stack<Node*> st;

        while(curr != NULL || !st.empty()){
            if(curr != NULL){
                st.push(curr);
                curr = curr->left;
            }
            else{
                Node* temp = st.top()->right;
                if(temp == NULL){
                    temp = st.top();
                    st.pop();
                    result.push_back(temp->data);
                    while(!st.empty() && st.top()->right == temp){
                        temp = st.top();
                        st.pop();
                        result.push_back(temp->data);
                    }
                }
                else{
                    curr = temp;
                }
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
    vector<int> result = sol.postorderTraversal(root);
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }
    return 0;
}