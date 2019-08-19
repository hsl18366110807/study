#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
//执行用时 :236 ms, 在所有 C++ 提交中击败了29.09 %的用户
//内存消耗 :20 MB, 在所有 C++ 提交中击败了18.63 %的用户
using namespace std;
class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		set<vector<int>> st;
		vector<vector<int>> res;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size(); i++) {
			if (i != 0 && nums[i] == nums[i - 1]) continue;
			int start = i + 1, end = nums.size() - 1;
			while (start < end) {
				if (nums[i] + nums[start] == -nums[end]) {
					st.insert({ nums[i],nums[start],nums[end] });
					start++;
					end--;
				}
				else if (nums[i] + nums[start] < -nums[end]) start++;
				else end--;
			}
		}
		for (set<vector<int>>::iterator iter = st.begin(); iter != st.end(); iter++) {
			res.push_back(*iter);
		}
		return res;
	}
};
int main() {
	Solution sol;
	vector<int> vec = {-1,0,1,2,-1,-4};
	vector<vector<int>> res = sol.threeSum(vec);
	system("pause");
}