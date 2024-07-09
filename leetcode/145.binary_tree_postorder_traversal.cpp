/**
 * @file 145.binary_tree_postorder_traversal.cpp
 * @author life000
 * @brief 
 * @version 0.1
 * @date solved at 2014.06.22
 * 
 * @copyright Copyright (c) 2024
 * 
 * 思路：非递归方法，遍历左孩子并压栈，直至一个没有左孩子的结点，而后开始回溯，这里由于一个结点需要确保其有孩子已经被访问过才能弹栈（弹栈访问之），故需要给每个结点一个标志。回溯结束后，就可以将右孩子作为新的root重复该过程，直至弹栈到空（且root为空）
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
    vector<int> postorderTraversal(TreeNode *root) {
		vector<int> res;
		stack<pair<bool, TreeNode*> > sn;	//first表示是否已访问其右孩子
		while ( root || ! sn.empty() ) {
			while ( root ) {
				sn.push(make_pair(false,root));
				root = root->left;
			}
			while ( !sn.empty() && sn.top().first ) {
				res.push_back(sn.top().second->val);
				sn.pop();
			}
			if ( !sn.empty() ) {
				sn.top().first = true;
				root = sn.top().second->right;
			}
		}
		return res;
    }
};
