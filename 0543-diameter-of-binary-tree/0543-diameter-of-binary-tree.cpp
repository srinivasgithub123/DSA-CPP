// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
// class Solution {
// public:

//     int height(TreeNode* root){
//         if(root==nullptr)
//         return 0;

//         int ltht=height(root->left);
//         int rtht= height(root->right);
        
//         return max(ltht, rtht)+1;
//     }

//     int diameterOfBinaryTree(TreeNode* root) {
//         if(root==nullptr)
//         return 0;

//         int ltdiam= diameterOfBinaryTree(root->left);
//         int rtdiam= diameterOfBinaryTree(root->right);
//         int ansdiam= height(root->left)+height(root->right);

//         return max(ansdiam, max(ltdiam, rtdiam));
        
//     }
// };
class Solution {
public:
    int maxDiameter = 0;

    int height(TreeNode* root) {
        if (root == nullptr)
            return 0;

        int ltht = height(root->left);
        int rtht = height(root->right);

        // Update the global diameter while computing height
        maxDiameter = max(maxDiameter, ltht + rtht);

        return max(ltht, rtht) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return maxDiameter;
    }
};
