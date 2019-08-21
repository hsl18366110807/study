#include<iostream>
#include<vector>
#include<string>
using namespace std;
/////////////////////
//两节点的最近公共祖先leetcode236
//难点：路径的表示问题，路径的节点不一定从根节点开始
//执行用时:24 ms, 在所有 C++ 提交中击败了82.27%的用户
//内存消耗 :16.6 MB, 在所有 C++ 提交中击败了64.58%的用户
struct TreeNode
{
	int val;
	TreeNode* left, * right;
	TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};
//////////////
class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root == NULL)return NULL;
		if (root == p) return root;
		if (root == q) return root;
		TreeNode* left = lowestCommonAncestor(root->left, p, q);
		TreeNode* right = lowestCommonAncestor(root->right, p, q);
		if (left && right) return root;
		else if (left)return left;
		else return right;
		return NULL;
	}
};
int main() {
	TreeNode* t1 = new TreeNode(1);
	TreeNode* t2 = new TreeNode(2);
	TreeNode* t3 = new TreeNode(3);
	TreeNode* t4 = new TreeNode(4);
	TreeNode* t5 = new TreeNode(5);
	TreeNode* t6 = new TreeNode(6);
	TreeNode* t7 = new TreeNode(7);
	t1->left = t2;
	t1->right = t3;
	t2->left = t6;
	t2->right = t5;
	t3->left = t4;
	t3->right = t7;
	Solution sol;
	TreeNode* p;
	p = sol.lowestCommonAncestor(t1, t2, t5);
}