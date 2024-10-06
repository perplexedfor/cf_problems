#include <bits/stdc++.h>
using namespace std;

class TrieNode{
public:
    TrieNode *child[26];
    bool isWord;
    TrieNode(){
        isWord = false;
        for(auto &a : child) a = nullptr;
    }
};

class Trie{
    TrieNode* root;
public:
    Trie(){
        root = new TrieNode();
    }
    void insert(string word){
        TrieNode* curr = root;
        for(int i = 0;i < word.size();i++){
            int index = word[i] - 'a';
            if(curr->child[index] == nullptr){
                curr->child[index] = new TrieNode();
            }
            curr = curr->child[index];
        }
        curr->isWord = true;
    }
    bool search(string word,bool prefix = false){
        TrieNode* curr = root;
        for(int i = 0;i < word.size();i++){
            int index = word[i] - 'a';
            if(curr->child[index] == nullptr){
                return false;
            }
            curr = curr->child[index];
        }
        if(prefix) return true;
        if(curr->isWord){
            return true;
        }
        return false;
    }
    bool startsWith(string prefix){
        return search(prefix,true);
    }
};