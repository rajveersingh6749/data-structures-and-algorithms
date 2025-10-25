#include<bits/stdc++.h>
using namespace std;

// Coder Army Solution Using Level Order Traversal

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(): data(0), left(nullptr), right(nullptr){}
    Node(int x): data(x), left(nullptr), right(nullptr){}
    Node(int x, Node* left, Node* right): data(x), left(left), right(right){}
};

void find(Node* root, int pos, int &l, int &r){
    if(!root) return;

    l = min(l, pos);
    r = max(r, pos);

    find(root->left, pos - 1, l, r);
    find(root->right, pos + 1, l, r);
}


vector<int> verticalTraversal(Node* root){
    int l = 0, r = 0;
    find(root, 0, l, r);

    vector<vector<int>> Positive(r + 1);
    vector<vector<int>> Negative(abs(l) + 1);

    queue<Node*> q;
    queue<int> index;

    q.push(root);
    index.push(0);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        int pos = index.front();
        index.pop();

        if(pos >= 0){
            Positive[pos].push_back(temp->data);
        }
        else{
            Negative[abs(pos)].push_back(temp->data);
        }

        if(temp->left){
            q.push(temp->left);
            index.push(pos - 1);
        }
        if(temp->right){
            q.push(temp->right);
            index.push(pos + 1);
        }

    }

    vector<int> ans;

    for(int i = Negative.size() - 1; i > 0; i--)
        for(int j = 0; j < Negative[i].size(); j++)
            ans.push_back(Negative[i][j]);

    for(int i = 0; i < Positive.size(); i++)
        for(int j = 0; j < Positive[i].size(); j++)
            ans.push_back(Positive[i][j]);

    return ans;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->left->left = new Node(7);
    root->left->right = new Node(5);
    root->left->left->right = new Node(8);
    root->left->left->right->left = new Node(11);
    root->left->left->right->right = new Node(12);
    root->right->right = new Node(6);
    root->right->right->left = new Node(9);
    root->right->right->right = new Node(10);
    root->right->right->right->left = new Node(13);

    vector<int> ans = verticalTraversal(root);
    for(auto it : ans)
        cout << it << " ";
    return 0;
}