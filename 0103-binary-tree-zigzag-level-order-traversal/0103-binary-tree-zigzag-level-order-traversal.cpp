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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;

        if(root==NULL){
            return result;
        }
        queue<TreeNode*> q;
        q.push(root);
        bool lefttoright= false;

        while(!q.empty()){
            int levelsize= q.size();
            vector<int> temp;
            lefttoright=!lefttoright;

            for(int i=0; i<levelsize; i++){
                TreeNode* curr= q.front();
                temp.push_back(curr->val);
                if(curr->left){
                    q.push(curr->left);
                }
                if(curr->right){
                    q.push(curr->right);
                }
                q.pop();
            }
            if(lefttoright==false){
                reverse(temp.begin(), temp.end());
                result.push_back(temp);
            }else{
                result.push_back(temp);
            }

        }
        return result;
    }
};