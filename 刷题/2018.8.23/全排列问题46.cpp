#include<iostream>
#include<vector>
using namespace std;
//main����֮ǰȫ����Ĺ��캯���Ѿ�����
//46,ȫ��������
//ִ����ʱ:280 ms, ������ C++ �ύ�л�����8.47 %���û�
//�ڴ����� :118 MB, ������ C++ �ύ�л�����5.01 %���û�
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
