/*
199. Binary Tree Right Side View
https://leetcode.com/problems/binary-tree-right-side-view/
*/

// Same as left view logic -> just make right call first

// Noice at each level size of vector == level(eg at lvl 0 leftview vector size = 0, at lvl 1 leftview vector size = 1 , ans so on...)
// so check if vector size == lvl then store that element and make root->left call first bec we need left most node

void solve(Node *root, int lvl,vector<int> &ans){
    if(root == NULL){
        return ;
    }
    
    if(ans.size() == lvl){
        ans.push_back(root->data);
    }
    
    solve(root->left,lvl + 1,ans);
    solve(root->right,lvl + 1,ans);
}

vector<int> leftView(Node *root){
    vector<int> ans;
    int lvl = 0;
    solve(root,lvl,ans);
    return ans;
    
}