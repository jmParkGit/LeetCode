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
    int sumOfLeftLeaves(TreeNode* root) {
        int ret=0;
        queue<TreeNode*> q;
        
        if(root == nullptr)
            return ret;

        q.push(root);
        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            
            if(node->left) {
                if(node->left->left == nullptr && node->left->right == nullptr)
                    ret += node->left->val;
                
                q.push(node->left);
            }
            
            if(node->right) {
                q.push(node->right);
            }
        }
        
        return ret;
    }
};