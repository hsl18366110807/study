#include<iostream>
#include<vector>
using namespace std;
//数组中逆序对
//运行超时:您的程序未能在规定时间内运行结束，请检查是否循环有错或算法复杂度过大。
//class Solution {
//public:
//	int InversePairs(vector<int> data) {
//		long long res = 0;
//		for (int i = 1; i < data.size(); i++) {
//			for (int j = 0; j < i; j++) {
//				if (data[i] < data[j]) res++;
//			}
//		}
//		return res % 1000000007;
//	}
//};
////////////////////////////////////////////

//运行时间：98ms
//
//占用内存：4276k

class Solution {
public:
	int merge(vector<int>& vec, int start, int end, vector<int>& res) {
		if (start >= end) return 0;
		int mid = start + ((end - start) >> 1);
		int left = merge(vec, start, mid, res);
		int right = merge(vec, mid + 1, end, res);
		int lb = start, le = mid;
		int rb = mid + 1, re = end;
		long long count = left + right;
		int index = end;
		while (lb <= le && rb <= re) {
			if (vec[le] > vec[re]) {
				res[index--] = vec[le--];
				count += re - rb + 1;
			}
			else {
				res[index--] = vec[re--];
			}
		}
		while (lb <= le)
		{
			res[index--] = vec[le--];
		}
		while (rb <= re)
		{
			res[index--] = vec[re--];
		}
		index = start;
		while (index <= end) {
			vec[index] = res[index];
			index++;
		}
		return count % 1000000007;
	}
	int InversePairs(vector<int> data) {
		int start = 0, end = data.size() - 1;
		vector<int> res(data.size(), 0);
		return merge(data, start, end, res);
	}
};
int main() {

	Solution sol;
	vector<int> vec;
	int a;
	while (cin.peek() != '\n' && cin >> a) {
		vec.push_back(a);
	}
	cout << sol.InversePairs(vec);
	system("pause");
}