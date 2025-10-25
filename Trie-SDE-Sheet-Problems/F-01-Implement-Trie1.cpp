#include <bits/stdc++.h>
using namespace std;


struct TrieNode{
    TrieNode* links[26];
    bool flag = false;

    bool containskey(char ch){
        return (links[ch - 'a'] != NULL);
    }

    void put(char ch, TrieNode* node){
        links[ch - 'a'] = node;
    }

    TrieNode* get(char ch){
        return links[ch - 'a'];
    }

    void setEnd(){
        flag = true;
    }

    bool isEnd(){
        return flag;
    }
};

class Trie{
    private:
    TrieNode* root;

    public:
    Trie(){
        root = new TrieNode();
    }

    void insert(string word){
        TrieNode* node = root;
        for(int i = 0; i < word.length(); i++){
            if(!node->containskey(word[i])){
                node->put(word[i], new TrieNode());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }

    bool search(string word){
        TrieNode* node = root;
        for(int i = 0; i < word.length(); i++){
            if(!node->containskey(word[i])){
                return false;
            }
            node = node->get(word[i]);
        }
        return node->isEnd();
    }

    bool startsWith(string prefix){
        TrieNode* node = root;
        for(int i = 0; i < prefix.length(); i++){
            if(!node->containskey(prefix[i])){
                return false;
            }
            node = node->get(prefix[i]);
        }
        return true;
    }
};

int main(){
    Trie* trie = new Trie();
    trie->insert("apple");
    cout << trie->search("apple") << endl;
    cout << trie->search("app") << endl;
    cout << trie->startsWith("app") << endl;
    return 0;
}
