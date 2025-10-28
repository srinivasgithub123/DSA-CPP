class Solution {
public:
    int dfs(TreeNode* root, int& total_tilt) {
        if (root == NULL) return 0;

        int left_sum = dfs(root->left, total_tilt);
        int right_sum = dfs(root->right, total_tilt);

        int tilt_here = abs(left_sum - right_sum);
        total_tilt += tilt_here;

        return root->val + left_sum + right_sum;
    }

    int findTilt(TreeNode* root) {
        int total_tilt = 0;
        dfs(root, total_tilt);
        return total_tilt;
    }
};
