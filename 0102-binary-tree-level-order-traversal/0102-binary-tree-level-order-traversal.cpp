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

    
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        queue<TreeNode*> q;

        if(root==NULL){
            return result;
        }

        q.push(root);
        while(!q.empty()){
            int levelsize= q.size();
            vector<int> temp;

            for(int i=0;i<levelsize; i++){
                TreeNode* curr= q.front();
                temp.push_back(q.front()->val);
                if(curr->left){
                    q.push(curr->left);
                }if(curr->right){
                    q.push(curr->right);
                }
                q.pop();
            }
            result.push_back(temp);

        }
        return result;
        
    }
};