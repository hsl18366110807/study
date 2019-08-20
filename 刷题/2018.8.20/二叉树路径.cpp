#include<iostream>
#include<vector>
using namespace std;
/////////////////////
//二叉树的路径和为某一个数
struct TreeNode
{
	int val;
	TreeNode* left, * right;
	TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};
//////////////存满足的数组和
class Solution {
public:
	vector<int> vec;
	vector<vector<int>> res;
	vector<vector<int> > FindPath(TreeNode* root, int expectNumber) {
		if (root == NULL || expectNumber < 0)
			return res;
		vec.push_back(root->val);
		if (!root->left && !root->right && root->val == expectNumber) {
			res.push_back(vec);
		}
		FindPath(root->left, expectNumber - root->val);////////不一定要有return的
		FindPath(root->right, expectNumber - root->val);
		vec.pop_back();
		return res;
	}
};
int main() {

}