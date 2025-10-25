#include <iostream>
#include <queue>
#include <vector>

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

vector<int> rightView(Node* root){
    vector<int> ans;
    if(root == nullptr) return ans;
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        int n = q.size();
        ans.push_back(q.front()->data);
        while(n--){
            Node* temp = q.front();
            q.pop();
            if(temp->right != nullptr) q.push(temp->right);
            if(temp->left != nullptr) q.push(temp->left);
        }
    }
    return ans;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    root->left->right->left = new Node(7);
    root->left->right->right = new Node(8);
    root->left->right->right->right = new Node(9);

    vector<int> ans = rightView(root);
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout<<endl;
    return 0;
}