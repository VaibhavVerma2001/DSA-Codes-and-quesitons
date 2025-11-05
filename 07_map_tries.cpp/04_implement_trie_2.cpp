/*
https://www.naukri.com/code360/problems/implement-trie_1387095
*/


class TrieNode {
    public :
    char value;
    TrieNode *children[26];
    int count; // count of each char
    int endCount; // count number of endings
    bool isTerminal;


    TrieNode(char value){
        this -> value = value;
        this -> isTerminal = false;
        this -> count = 0;
        this -> endCount = 0;
        for(int i = 0 ;i < 26; i++){
            this -> children[i] = nullptr;
        }
    }
};


#include <bits/stdc++.h> 
class Trie{

    public:

    TrieNode *root ;
    Trie(){
        // Write your code here.
        root = new TrieNode('-');
    }

    void insert(string &word){
        // Write your code here.
        TrieNode *temp = root;
        for(auto &ch : word){
            if(temp -> children[ch - 'a'] == nullptr){
                TrieNode *newNode = new TrieNode(ch);
                temp -> children[ch - 'a'] = newNode;
            } 
            temp = temp -> children[ch - 'a'];
            temp -> count++;
        }
        temp -> isTerminal = true;
        temp -> endCount++;
    }

    int countWordsEqualTo(string &word){
        // Write your code here.
        TrieNode *temp = root;
        for(auto &ch : word){
            if(temp -> children[ch - 'a'] == nullptr){
                return 0;
            } 
            temp = temp -> children[ch - 'a'];
        }
        return temp -> endCount;
        
    }

    int countWordsStartingWith(string &word){
        // Write your code here.
        TrieNode *temp = root;
        for(auto &ch : word){
            if(temp -> children[ch - 'a'] == nullptr){
                return 0;
            } 
            temp = temp -> children[ch - 'a'];
        }
        return temp -> count;
    }

    void erase(string &word){
        // Write your code here.
        TrieNode *temp = root;
        for(auto &ch : word){
            if(temp -> children[ch - 'a'] == nullptr){
                return;
            } 
            temp = temp -> children[ch - 'a'];
            temp -> count--;
        }
        temp -> endCount--;
    }
};
