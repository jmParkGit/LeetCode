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
    bool hasPathSum(TreeNode* root, int targetSum) {
        vector<pair<TreeNode*,int>> stk;
        bool ret=false;
        
        if(root==nullptr)
            return ret;
        
        stk.push_back(make_pair(root,root->val));
        
        while(!stk.empty())
        {
            TreeNode* node=stk.back().first;
            int sum=stk.back().second;
            stk.pop_back();
            
            
            if((sum==targetSum)&&(node->right==nullptr)&&(node->left==nullptr))
            {
                ret=true;
                break;
            }
            
            if(node->right)
                stk.push_back(make_pair(node->right,sum+node->right->val));
            if(node->left)
                stk.push_back(make_pair(node->left,sum+node->left->val));
        }
        
        
        return ret;
    }
};