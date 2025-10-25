#include <bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(): data(0),left(nullptr),right(nullptr){}
    Node(int data): data(data),left(nullptr),right(nullptr){}
    Node(int data,Node* left,Node* right): data(data),left(left),right(right){}
};

class Solution{
    public:

    int maxWidth(Node* root){
        if(!root) return 0;

        long long width = 0;
        queue<pair<Node*,int>> q;
        q.push({root,0});

        while(!q.empty()){
            int size = q.size();
            long long minIndex = q.front().second;

            long long first,last;

            for(int i = 0; i < size; i++){
                long long currentIndex = q.front().second - minIndex;

                Node* node = q.front().first;
                q.pop();

                if(i == 0) first = currentIndex;
                if(i == size - 1) last = currentIndex;

                if(node -> left) q.push({node -> left,2 * currentIndex + 1});
                if(node -> right) q.push({node -> right,2 * currentIndex + 2});
            }

            width = max(width,last - first + 1);
        }

        return int(width);
    }
};

int main(){
    Node* root = new Node(1);
    root->left = new Node(3);
    root->right = new Node(7);
    root->left->left = new Node(8);
    root->right->right = new Node(4);

    Solution sol;
    cout<<sol.maxWidth(root)<<endl;
    return 0;
}
    