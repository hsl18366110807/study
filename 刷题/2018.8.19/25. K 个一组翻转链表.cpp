#include<iostream>
#include<vector>
using namespace std;
struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x) :val(x), next(NULL) {}
};
class Solution {
public:
	ListNode* rvrs(ListNode* head) {
		ListNode* p1 = NULL, *p2 = head, *p3 = p2;
		while (p2) {
			p3 = p2->next;
			p2->next = p1;
			p1 = p2;
			p2 = p3;
		}
		return p1;
	}
	ListNode* reverseKGroup(ListNode* head, int k) {
		if (head == NULL) return NULL;
		ListNode* p = head;
		int n=0;
		while (p) {
			n++;
			p = p->next;
		}
		int zushu = 0;
		if (n % k == 0) zushu = n / k;
		else zushu = n / k + 1;
		vector<ListNode*> vec;
		p = head;
		int k1 = k;
		while (p) {
			if (k1 == 0||k1==k) {
				k1 = k;
				vec.push_back(p);
			}
			if (k1 == 1) {
				ListNode* q = p;
				p = p->next;
				q->next = NULL;
			}else 	p = p->next;
			k1--;
		}
		if (n % k == 0) {
			for (int i = 0; i < vec.size(); i++) {
				vec[i] = rvrs(vec[i]);
			}
		}
		else {
			for (int i = 0; i < vec.size(); i++) {
				if (vec[i] == vec.back()) continue;
				vec[i] = rvrs(vec[i]);
			}
		}
		ListNode* q = new ListNode(-1);
		for (int i = 0; i < vec.size(); i++) {
			q->next = vec[i];
			q = vec[i];
			while (q->next) {
				q = q->next;
			}
		}
		return vec[0];
	}
};
int main() {
	Solution sol;
	ListNode* p1 = new ListNode(1);
	ListNode* p2 = new ListNode(2);
	ListNode* p3 = new ListNode(3);
	ListNode* p4 = new ListNode(4);
	ListNode* p5 = new ListNode(5);
	p1->next = p2;
	p2->next = p3;
	p3->next = p4;
	p4->next = p5;
	ListNode* p6 = sol.reverseKGroup(p1, 3);
	system("pause");
}