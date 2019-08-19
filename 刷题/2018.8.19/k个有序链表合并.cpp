#include<iostream>
#include<vector>
using namespace std;
//合并k个有序链表
//执行用时:28 ms, 在所有 C++ 提交中击败了99.14 %的用户
//内存消耗 :11 MB, 在所有 C++ 提交中击败了90.74 %的用户
struct ListNode
{ 
	int val;
	ListNode* next;
	ListNode(int x):val(x),next(NULL){}
};
class Solution {
public:
	ListNode* merge2lists(ListNode* list1, ListNode* list2) {
		ListNode* head = new ListNode(-1);
		ListNode* p = head;
		while (list1 && list2) {
			if (list1->val <= list2->val) {
				p->next = list1;
				list1 = list1->next;
			}
			else {
				p->next = list2;
				list2 = list2->next;
			}
			p = p->next;
		}
		if (list1) {
			p->next = list1;
		}
		if (list2) {
			p->next = list2;
		}
		return head->next;
	}
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		if (lists.size() == 0)return NULL;
		while (lists.size() != 1) {
			int start = 0, end = lists.size() - 1;
			while (start <= end) {
				if (start == end)break;
				lists[start] = merge2lists(lists[start], lists[end]);
				lists.pop_back();
				start++;
				end--;
			}
		}
		return lists[0];
	}
};
int main() {
	Solution sol;
	ListNode* p1 = new ListNode(1);
	ListNode* p2 = new ListNode(4);
	ListNode* p3 = new ListNode(5);
	p1->next = p2;
	p2->next = p3;
	ListNode* p4 = new ListNode(1);
	ListNode* p5 = new ListNode(3);
	ListNode* p6 = new ListNode(4);
	p4->next = p5;
	p5->next = p6;
	ListNode* p7 = new ListNode(2);
	ListNode* p8 = new ListNode(6);
	p7->next = p8;
	vector<ListNode*> vec;
	vec.push_back(p1);
	vec.push_back(p4);
	vec.push_back(p7);
	ListNode* p9 = sol.mergeKLists(vec);
	system("pause");
}