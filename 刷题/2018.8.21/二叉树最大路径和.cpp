#include<iostream>
#include<vector>
#include<string>
using namespace std;
/////////////////////
//������������·��leetcode124
//�ѵ㣺·���ı�ʾ���⣬·���Ľڵ㲻һ���Ӹ��ڵ㿪ʼ
//ִ����ʱ:56 ms, ������ C++ �ύ�л�����31.73 %���û�
//�ڴ����� :23.3 MB, ������ C++ �ύ�л�����99.16 %���û�
struct TreeNode
{
	int val;
	TreeNode* left, * right;
	TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};
//////////////
class Solution {
public:
	 int maxres = INT_MIN;
	int maxPathSum(TreeNode* root) {
		if (root == NULL) return 0;
		int left = maxPathSum(root->left);
		int right = maxPathSum(root->right);
		if (left < 0) left = 0;
		if (right < 0) right = 0;
		if (root->val + left + right > maxres) maxres = root->val + left + right;
		return root->val + (left > right ? left : right);
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
	sol.maxPathSum(t1);
	int rres;
	rres = sol.maxres;
}