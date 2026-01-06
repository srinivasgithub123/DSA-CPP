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
    int maxLevelSum(TreeNode* root) {
        if(root== NULL){
            return -1;
        }

        queue<TreeNode*>q;
        q.push(root);
        int ans=INT_MIN, level=1, levels;

        while(!q.empty()){
            int size= q.size();
            int cursum=0;

            for(int i=0; i<size; i++){
                TreeNode* node= q.front();
                q.pop();
                cursum= cursum+ node->val;
                if(node->left){
                    q.push(node->left);
                } if(node->right){
                    q.push(node->right);
                }
                
            }
            if(cursum > ans){
                    ans= cursum;
                    levels= level;
                }

            level++;
        }
    return levels;   
    }
};