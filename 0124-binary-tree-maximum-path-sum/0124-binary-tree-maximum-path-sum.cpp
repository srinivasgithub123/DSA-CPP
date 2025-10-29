class Solution {
public:
    int pathsum(TreeNode* root, int& globalpath) {
        if (!root) return 0;

        int ls = pathsum(root->left, globalpath);
        int rs = pathsum(root->right, globalpath);

        int localpath = root->val + max(0, ls) + max(0, rs);
        globalpath = max(globalpath, localpath);

        return root->val + max(0, max(ls, rs));
    }

    int maxPathSum(TreeNode* root) {
        int globalpath = INT_MIN;
        pathsum(root, globalpath);
        return globalpath;
    }
};
