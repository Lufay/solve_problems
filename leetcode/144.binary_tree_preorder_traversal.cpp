/**
 * @file 144.binary_tree_preorder_traversal.cpp
 * @author life000
 * @brief 
 * @version 0.1
 * @date solved at 2014.06.23
 * 
 * @copyright Copyright (c) 2024
 * 
 * 思路：非递归方法，遍历左孩子压栈并访问，直至一个没有左孩子的结点，弹栈，以右孩子为root重复该过程，直至弹栈到空（且root为空）
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> res;
        stack<TreeNode*> sn;
        while ( root || !sn.empty() ) {
            while ( root ) {
                res.push_back(root->val);
                sn.push(root);
                root =  root->left;
            }       
            if ( !sn.empty() ) {
                root = sn.top()->right;
                sn.pop();
            }       
        }       
        return res;
    }
};
