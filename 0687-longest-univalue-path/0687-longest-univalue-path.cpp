/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    int dfs(TreeNode* root, int& global) {
    if (!root) return 0;

    int left_len = dfs(root->left, global);
    int right_len = dfs(root->right, global);

    int left_chain = 0, right_chain = 0;

    if (root->left && root->left->val == root->val)
        left_chain = left_len + 1;
    if (root->right && root->right->val == root->val)
        right_chain = right_len + 1;

    global = max(global, left_chain + right_chain);

    return max(left_chain, right_chain);
}

    int longestUnivaluePath(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int global= INT_MIN;
        dfs(root, global);
        return global;
        
    }
};