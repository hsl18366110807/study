#include<iostream>
#include<vector>
using namespace std;
//快速排序
//执行用时:88 ms, 在所有 C++ 提交中击败了75.47 %的用户
//内存消耗 :12.6 MB, 在所有 C++ 提交中击败了100.00 %的用户
class Solution {
public:
	int partition(vector<int>& vec, int start, int end) {
		int pivot = vec[start];
		while (start < end) {
			while (start<end && vec[end]>=pivot)
				end--;
			vec[start] = vec[end];
			while (start<end && vec[start]<=pivot)
				start++;
			vec[end] = vec[start];
		}
		vec[start] = pivot;
		return start;
	}
	void QuickSort(vector<int>& vec,int start,int end) {
		int index = partition(vec, start, end);
		if (index > start) QuickSort(vec, start, index - 1);
		if (index < end)QuickSort(vec, index + 1, end);
	}
	vector<int> sortArray(vector<int>& nums) {
		int start = 0, end = nums.size() - 1;
		QuickSort(nums, start, end);
		return nums;
	}
};
int main() {
	int a;
	vector<int> vec;
	while (cin.peek() != '\n' && cin >> a) {
		vec.push_back(a);
	}
	Solution sol;
	vector<int> res;
	res=sol.sortArray(vec);
	for (int i = 0; i < res.size(); i++) {
		if ( i!= res.size() - 1)cout << res[i] << ' ';
		else cout << res[i];
	}
}