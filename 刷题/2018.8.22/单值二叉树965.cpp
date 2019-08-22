#include<iostream>
#include<stack>
using namespace std;
/////////////////////

struct TreeNode
{
	int val;
	TreeNode* left, * right;
	TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};
//////////////
class Solution {
public:
	/////ÖÐÐò±éÀú¶þ²æÊ÷
	bool isUnivalTree(TreeNode* root) {
		TreeNode* p = root;
		TreeNode* pre=NULL;
		stack<TreeNode*>s;
		while (p || !s.empty()) {
			while (p) {
				s.push(p);
				p = p->left;
			}
			p = s.top();
			s.pop();
			if (pre && pre->val != p->val)return false;
			pre = p;
			p = p->right;
		}
		return true;
	}
};
int main() {
	TreeNode* t1 = new TreeNode(2);
	TreeNode* t2 = new TreeNode(2);
	TreeNode* t3 = new TreeNode(2);
	TreeNode* t4 = new TreeNode(5);
	TreeNode* t5 = new TreeNode(2);
	//TreeNode* t6 = new TreeNode(6);
	//TreeNode* t7 = new TreeNode(7);
	t1->left = t2;
	t1->right = t3;
	t2->left = t4;
	t2->right = t5;
	//t3->left = t4;
	//t3->right = t7;
	Solution sol;
	TreeNode* p;
	sol.isUnivalTree(t1);
}