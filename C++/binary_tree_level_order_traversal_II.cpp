/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    vector<vector<int>> result;
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {        
        layer(root, 0);
        
        return result;
    }
        
    void layer(TreeNode* node, int depth) {
        if(node == NULL) return;
        
        if(result.size() == depth) result.insert(result.begin(), vector<int>{node->val});
        else result[result.size() - depth -1].push_back(node->val);
        
        layer(node->left, depth+1);

        layer(node->right, depth+1);
    }
};
