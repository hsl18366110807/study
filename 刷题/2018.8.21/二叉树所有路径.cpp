#include<iostream>
#include<vector>
#include<string>
using namespace std;
/////////////////////
//������������·��leetcode257
//�ѵ㣺������⣬��·���û��ݷ�
//ִ����ʱ:8 ms, ������ C++ �ύ�л�����65.78 %���û�
//�ڴ����� :13 MB, ������ C++ �ύ�л�����25.26 %���û�
struct TreeNode
{
	int val;
	TreeNode* left, * right;
	TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};
//////////////
class Solution {
public:
	vector<vector<int>> res;
	vector<int> vec;
	vector<string> rres;
	vector<vector<int>> BinaryTreePaths(TreeNode* root) {
		if (root == NULL) return res;
		vec.push_back(root->val);
		if (!root->left && !root->right) {
			res.push_back(vec);
		}
		if (root->left) res=BinaryTreePaths(root->left);
		if (root->right) res=BinaryTreePaths(root->right);
		vec.pop_back();
		return res;
	}
	vector<string> binaryTreePaths(TreeNode* root) {
		BinaryTreePaths(root);
		for (int i = 0; i < res.size(); i++) {
			string s="";
			for (int j = 0; j < res[i].size(); j++) {
				string ss;
				if (j == res[i].size() - 1) s += to_string(res[i][j]);
				else {
					s+= to_string(res[i][j]);
					s += "->";
				}
			}
			rres.push_back(s);
		}
		return rres;
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
	vector<string> rres;
	rres = sol.binaryTreePaths(t1);
	

}