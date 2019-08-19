#include<iostream>
using namespace std;
//执行用时:12 ms, 在所有 C++ 提交中击败了42.91 %的用户
//内存消耗 :14.7 MB, 在所有 C++ 提交中击败了88.79 %的用户
struct TreeNode
{
	int val;
	TreeNode* left, * right;
	TreeNode(int x):val(x),left(NULL),right(NULL){}
};
class Solution {
public:
	bool ismirror(TreeNode* self, TreeNode* root) {
		if (!self && !root) return true;
		else if (self && root && self->val == root->val) {
			return ismirror(self->right, root->left) && ismirror(self->left, root->right);
		}
		else return false;
	}
	bool isSymmetric(TreeNode* root) {
		return ismirror(root, root);
	}
};
int main() {
	Solution sol;

	system("pause");
}