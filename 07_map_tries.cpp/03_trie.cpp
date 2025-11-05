/*

🧩 1. What is a Trie?
A Trie (also called a Prefix Tree) is a tree-based data structure used to store and search strings efficiently, especially when dealing with prefixes.
Each node represents a character of a word.
Paths from the root to a node form prefixes of stored words.

💡 2. Why use a Trie?
Tries are ideal for:
✅ Prefix-based searches (e.g., autocomplete, spell checking)
✅ Dictionary-like word lookups
✅ Efficient string searching in large datasets (better than hash maps for prefix operations)


Compared to a hash map:
| Operation     | HashMap | Trie   |
| ------------- | ------- | ------ |
| Insert Word   | O(L)    | O(L)   |
| Search Word   | O(L)    | O(L)   |
| Prefix Search | O(N·L)  | ✅ O(L) |


Each node has 3 things - 
1- value --> character
2- children --> array/map
3- isTerminal --> T/F (tells whether 1 word is completed)
*/


// https://leetcode.com/problems/implement-trie-prefix-tree/description/

#include<iostream>
using namespace std;



class TrieNode{
    
    public:
    char value;
    TrieNode *children[26];
    bool isTerminal;

    TrieNode(char value){
        this -> value = value;
        this -> isTerminal = false;
        for(int i = 0 ; i < 26; i++){
            this -> children[i] = nullptr;
        }
    }

};


// TC = O(L) -> L length of word
void insertWord(TrieNode *root, string &word){ 

    TrieNode *temp = root;
    for(int i = 0 ; i < word.length(); i++){
        char ch = word[i];
        // check if there is any children present with this value 
        if(temp -> children[ch - 'a'] == nullptr){ //not  present then insert
            cout << "inserted : " << ch << endl;
            TrieNode *newNode = new TrieNode(ch);
            temp -> children[ch - 'a'] = newNode;
        }
        // traverse
        temp = temp -> children[ch - 'a'];
    }
    temp -> isTerminal = true;
}


// TC = O(L) -> L length of word
bool searchWord(TrieNode*root , string word){
    TrieNode *temp = root;
    for(int i = 0 ; i < word.length(); i++){
        char ch = word[i];
        // check if there is any children present with this value 
        if(temp -> children[ch - 'a'] == nullptr){ //not  present return false
           return false;
        }
        // traverse
        temp = temp -> children[ch - 'a'];
    }
    // at last check if it is terminal (for exact word matching, not prefix)
    return temp -> isTerminal;
}


// TC = O(L) -> L length of word 
// prefix search
bool startsWith(TrieNode*root , string word){
    TrieNode *temp = root;
    for(int i = 0 ; i < word.length(); i++){
        char ch = word[i];
        // check if there is any children present with this value 
        if(temp -> children[ch - 'a'] == nullptr){ //not  present return false
           return false;
        }
        // traverse
        temp = temp -> children[ch - 'a'];
    }
    return true;
}


// For deletion we cant delete node completely bec this will effect/erase other words also
// so traverse that word and mark it's terminal node as False
// TC = O(L) -> L length of word  
void deleteWord(TrieNode *root, string word){
    TrieNode *temp = root;
    for(int i = 0 ; i < word.length(); i++){
        char ch = word[i];
        if(temp ->children[ch - 'a'] == nullptr){
            return ; // not found
        }
        temp = temp -> children[ch - 'a'];
    }
    temp -> isTerminal = false;
}


// print all words in Trie
// TC = O(N)
// N = total number of nodes in the Trie
// (i.e. the total number of characters across all inserted words)
// ΣL = sum of the lengths of all words (same as N)
void printWords(TrieNode *root, string curr, vector<string> &ans){
    if(!root){
        return ;
    }

    if(root -> isTerminal){
        ans.push_back(curr);
    }

    // find for all childs
    for(int i = 0 ; i < 26; i++){
        TrieNode *child = root ->children[i];
        if(child){
            curr.push_back(child -> value);
            printWords(child, curr, ans);
            curr.pop_back();
        }
    }
}


// recommendation system --> move to last char of prefix --> use printWords to get all words from here
vector<string> recommendedWords(TrieNode *root, string word){
    vector<string> ans;
    // reach last node of char of that word
    for(int i = 0 ; i < word.length(); i++){
        char ch = word[i];
        if(root -> children[ch - 'a'] == nullptr){
            return {}; // no match
        }
        root = root -> children [ch - 'a'];
    }

    // from here find all words
    printWords(root, word , ans);
    return ans;
}

int main(){

    TrieNode *root = new TrieNode('-');
    string word = "apple";
    insertWord(root, word);
    
    cout << endl << endl;

    word = "app";
    insertWord(root, word);
    
    cout << endl << endl;

    word = "bat";
    insertWord(root, word);

    vector<string> ans;
    cout << "Printing all word " << endl;
    printWords(root, "", ans);
    for(auto &x : ans){
        cout << x << " ";
    }

    
    cout << endl << endl;

    cout << "search with app : " << searchWord(root, "app") << endl;
    cout << "search with appl : " << searchWord(root, "appl") << endl;
    cout << "search with apple : " << searchWord(root, "apple") << endl;
    cout << "search with bat : " << searchWord(root, "bat") << endl;
    cout << "search with batt : " << searchWord(root, "batt") << endl;

    cout << endl << endl;

    cout << "starts with appl : " << startsWith(root, "appl") << endl;
    cout << "starts with apple : " << startsWith(root, "ba") << endl;

    cout << endl << endl;

    cout << "search with app : " << searchWord(root, "app") << endl;

    deleteWord(root, "app");
    cout << endl << endl;

    cout << "search with app : " << searchWord(root, "app") << endl;
    cout << "search with apple : " << searchWord(root, "apple") << endl;


    cout << "Printing all word " << endl;
    ans = {};
    printWords(root, "", ans);
    for(auto &x : ans){
        cout << x << " ";
    }


    word = "car";
    insertWord(root, word);
    word = "care";
    insertWord(root, word);
    word = "caring";
    insertWord(root, word);
    word = "card";
    insertWord(root, word);

    cout << "Printing all word " << endl;
    ans = {};
    printWords(root, "", ans);
    for(auto &x : ans){
        cout << x << " ";
    }

    cout << endl << endl;

    vector<string> words = recommendedWords(root, "ca");
    cout << "Printing all recommendations " << endl;
    for(auto &x : words){
        cout << x << " ";
    }
    cout << endl << endl;
    return 0;
}