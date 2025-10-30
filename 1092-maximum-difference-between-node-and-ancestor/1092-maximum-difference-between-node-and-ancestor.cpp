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

int dfs(TreeNode* root, int maxVal, int minVal) {
    if (root == nullptr) 
        return maxVal - minVal;

    maxVal = max(maxVal, root->val);
    minVal = min(minVal, root->val);

    int left = dfs(root->left, maxVal, minVal);
    int right = dfs(root->right, maxVal, minVal);

    return max(left, right);
}

    int maxAncestorDiff(TreeNode* root) {
        int maxval=root->val;
        int minval= root->val;
        return dfs(root, maxval, minval);

        
    }
};