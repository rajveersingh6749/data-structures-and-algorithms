#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(): data(0), left(nullptr), right(nullptr){}
    Node(int x): data(x), left(nullptr), right(nullptr){}
    Node(int x, Node* left, Node* right): data(x), left(left), right(right){}
};

vector<vector<int>> preInPost(Node* root){

    vector<int> pre, in, post;
    if(root == nullptr) return {};

    stack<pair<Node*, int>> st;
    st.push({root, 1});

    while(!st.empty()){
        auto it = st.top();
        st.pop();

        if(it.second == 1){ // if it.second == 1 then it is preorder
            pre.push_back(it.first->data);
            it.second++;

            st.push({it.first, it.second});
            if(it.first->left != nullptr) st.push({it.first->left, 1});
        }

        else if(it.second == 2){ // if it.second == 2 then it is inorder
            in.push_back(it.first->data);
            it.second++;

            st.push({it.first, it.second});
            if(it.first->right != nullptr) st.push({it.first->right, 1});
        }

        else{ // if it.second == 3 then it is postorder
            post.push_back(it.first->data);
        }
    }

    vector<vector<int>> ans;
    ans.push_back(pre);
    ans.push_back(in);
    ans.push_back(post);
    return ans;
}


int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    vector<vector<int>> ans = preInPost(root);
    for(auto it : ans){
        for(auto i : it){
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}