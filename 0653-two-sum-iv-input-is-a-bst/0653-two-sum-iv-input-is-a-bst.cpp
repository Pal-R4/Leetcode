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
 class BSTIterator {
public:
 stack<TreeNode*>mystack;
 bool reverse=true;
void pushall(TreeNode* root)
{
    while(root!=NULL)
    {
        mystack.push(root);
        if(!reverse)
        root=root->left;
        else
        root=root->right;
    }
}
    BSTIterator(TreeNode* root,bool isreverse) {
        reverse =isreverse;
        pushall(root);
    }
    
    int next() {
       TreeNode* temp=mystack.top();
       mystack.pop();
       if(!reverse)
       pushall(temp->right);
       else
       pushall(temp->left);
       return temp->val;
    }
    
    bool hasNext() {
        return !mystack.empty();
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root)false;
        BSTIterator l(root,false);
        BSTIterator r(root,true);
        int i=l.next();
        int j=r.next();
        while(i<j)
        {
            if(i+j==k)return true;
            else if(i+j<k)i=l.next();
            else j=r.next();
        }
        return false;
    }
};