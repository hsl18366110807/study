#include<iostream>
#include<vector>
using namespace std;
//main函数之前全局类的构造函数已经加载
//922,索引和值都是奇数或者偶数
//执行用时:120 ms, 在所有 C++ 提交中击败了82.33 %的用户
//内存消耗 :11.5 MB, 在所有 C++ 提交中击败了99.79 %的用户
class Solution {
public:
	vector<int> sortArrayByParityII(vector<int>& A) {
		for (int i = 0; i < A.size(); i++) {
			if ((i & 1) == 1 && (A[i] & 1) == 1)continue;
			if ((i & 1) == 0 && (A[i] & 1) == 0)continue;
			if ((i & 1) == 0) {
				for (int j = i + 1; j < A.size(); j += 2) {
					if ((A[j] & 1) == 0) { swap(A[i], A[j]); break; }
				}
			}
			if ((i & 1) == 1) {
				for (int j = i + 1; j < A.size(); j += 2) {
					if ((A[j] & 1) == 1) { swap(A[i], A[j]); break; }
				}
			}
		}
		return A;
	}
};
/////////////////////////////////////////////////
int main() {
	Solution sol;
	vector<int> vec;
	int a;
	while (cin.peek() != '\n' && cin >> a)
	{
		vec.push_back(a);
	}
	vector<int>res;
	res = sol.sortArrayByParityII(vec);
	for (int i = 0; i < res.size(); i++) {
		cout << res[i];
	}
	system("pause");
}
