#include<iostream>
#include<vector>
using namespace std;
//main函数之前全局类的构造函数已经加载
//905,偶数在前，基数在后
//思想是用快排的思想，前后交换
//执行用时:60 ms, 在所有 C++ 提交中击败了35.22 %的用户
//内存消耗 :9.7 MB, 在所有 C++ 提交中击败了86.81 %的用户
class Solution {
public:
	vector<int> sortArrayByParity(vector<int>& A) {
		int start = 0, end = A.size() - 1;
		while (start<end)
		{
			while (start < end && (A[end] & 1) == 1)
				end--;
			while (start < end && (A[start] & 1) == 0)
				start++;
			swap(A[start], A[end]);
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
	res = sol.sortArrayByParity(vec);
	for (int i = 0; i < res.size(); i++) {
		cout << res[i];
	}
	system("pause");
}
