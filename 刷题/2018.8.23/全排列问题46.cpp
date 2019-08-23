#include<iostream>
#include<vector>
using namespace std;
//main函数之前全局类的构造函数已经加载
//46,全排列问题
//执行用时:280 ms, 在所有 C++ 提交中击败了8.47 %的用户
//内存消耗 :118 MB, 在所有 C++ 提交中击败了5.01 %的用户
class Solution {
public:
	vector<vector<int>> res;
	vector<vector<int>> permutee(vector<int>& nums, int start) {
		if (start == nums.size() - 1) res.push_back(nums);
		for (int i = start; i < nums.size(); i++) {
			swap(nums[start], nums[i]);
		if(start+1<nums.size())	res = permutee(nums, start+1);
			swap(nums[start], nums[i]);
		}
		return res;
	}
	vector<vector<int>> permute(vector<int>& nums) {
		res = permutee(nums, 0);
		return res;
		
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
	vector<vector<int>>res;
	res = sol.permute(vec);
	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[i].size(); j++) {
			if (j != res[i].size() - 1) cout << res[i][j] << ' ';
			else cout << res[i][j] << endl;
		}	
	}
	system("pause");
}
