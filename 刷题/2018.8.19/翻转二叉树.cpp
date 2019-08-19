#include<iostream>
using namespace std;
//执行用时:4 ms, 在所有 C++ 提交中击败了81.96 %的用户
//内存消耗 :9.2 MB, 在所有 C++ 提交中击败了32.01 %的用户
struct TreeNode
{
	int val;
	TreeNode* left, * right;
	TreeNode(int x):val(x),left(NULL),right(NULL){}
};
class Solution {
public:
	TreeNode* invertTree(TreeNode* root) {
		if (root == NULL)return NULL;
		TreeNode* left = root->left;
		root->left = invertTree(root->right);
		root->right = invertTree(left);
		return root;
	}
};
int main() {
	Solution sol;

	system("pause");
}