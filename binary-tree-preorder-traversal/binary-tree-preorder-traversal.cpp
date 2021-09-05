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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        vector<TreeNode *> stk;
        TreeNode* head=root;
        
        if(root ==nullptr)
            return ret;
        
        stk.push_back(root);
        
        while(!stk.empty())
        {
            TreeNode* head=stk.back();
            stk.pop_back();
            
            ret.push_back(head->val);
            if(head->right)
                stk.push_back(head->right);
            
            if(head->left)
                stk.push_back(head->left);
        }
        
        return ret;
    }
};