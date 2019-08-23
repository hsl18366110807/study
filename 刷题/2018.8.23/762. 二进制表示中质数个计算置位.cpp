#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//main函数之前全局类的构造函数已经加载
//执行用时:84 ms, 在所有 C++ 提交中击败了6.90 %的用户
//内存消耗 :8.2 MB, 在所有 C++ 提交中击败了80.70 %的用户
class Solution {
public:
	vector<int> zhishu32 = { 2,3,5,7,11,13,17,19,23,29,31 };
	int countPrimeSetBits(int L, int R) {
		int res=0;
		for (int i = L; i <= R; i++) {
			int count=0;
			int k = i;
			while (k) {
				k = k & (k - 1);
				count++;
			}
			if (find(zhishu32.begin(), zhishu32.end(), count) != zhishu32.end()) res++;
		}
		return res;
	}
};
/////////////////////////////////////////////////
int main() {
	Solution sol;
	vector<int> vec;
	int a, b;
	cin >> a >> b;
	cout<<sol.countPrimeSetBits(a,b);
	system("pause");
}
