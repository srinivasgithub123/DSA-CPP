class Solution {
public:
    void helper(TreeNode* root, int targetSum, vector<int>& path, vector<vector<int>>& result) {
        if (root == nullptr)
            return;

        path.push_back(root->val);

        // If leaf node and sum matches, store the path
        if (root->left == nullptr && root->right == nullptr && targetSum == root->val) {
            result.push_back(path);
        } else {
            // Continue recursion
            int newTarget = targetSum - root->val;
            helper(root->left, newTarget, path, result);
            helper(root->right, newTarget, path, result);
        }

        // Backtrack
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;
        vector<int> path;
        helper(root, targetSum, path, result);
        return result;
    }
};
