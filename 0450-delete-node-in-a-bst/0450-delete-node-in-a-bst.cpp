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

    // Helper function to find the node with the smallest value in a given subtree
    TreeNode* minValueNode(TreeNode* node) {
        TreeNode* curr = node;
        // The smallest value is always found by going as far left as possible
        while (curr && curr->left != NULL) {
            curr = curr->left;
        }
        return curr;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        // Base case: empty tree
        if (root == NULL) {
            return NULL;
        }

        // If key to be deleted is smaller than root’s key, move to left subtree
        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        }
        // If key to be deleted is greater than root’s key, move to right subtree
        else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        }
        // Key is same as root’s key → this is the node to delete
        else {
            // Case 1: Node has no left child → replace with right child
            if (root->left == NULL) {
                TreeNode* temp = root->right;
                delete root; // free memory
                return temp;
            }
            // Case 2: Node has no right child → replace with left child
            else if (root->right == NULL) {
                TreeNode* temp = root->left;
                delete root; // free memory
                return temp;
            }
            // Case 3: Node has two children
            else {
                // Find inorder successor (smallest in right subtree)
                TreeNode* successor = minValueNode(root->right);
                // Copy successor's value to this node
                root->val = successor->val;
                // Delete the successor from the right subtree
                root->right = deleteNode(root->right, successor->val);
            }
        }

        // Return the updated root pointer
        return root;
    }
};
