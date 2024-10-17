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
bool isValidBST(TreeNode *root,long long minval,long long maxval)
{
    if(root==NULL)return true;
if(root->val>=maxval||root->val<=minval)return false;
return isValidBST(root->left,minval,root->val)&&isValidBST(root->right,root->val,maxval);

}
    bool isValidBST(TreeNode* root) {
        long long min=LLONG_MIN,max=LLONG_MAX;
        return isValidBST(root,min,max);
    }
};