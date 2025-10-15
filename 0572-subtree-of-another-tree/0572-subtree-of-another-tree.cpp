class Solution {
public:
    bool isIdentical(TreeNode* p, TreeNode* q) {
        if (p == NULL || q == NULL)
            return p == q;
        return p->val == q->val &&
               isIdentical(p->left, q->left) &&
               isIdentical(p->right, q->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // ✅ Fix: handle NULL root before dereferencing
        if (root == NULL) return false;
        
        if (isIdentical(root, subRoot)) 
            return true;

        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};
