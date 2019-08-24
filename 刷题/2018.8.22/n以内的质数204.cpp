#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//main函数之前全局类的构造函数已经加载
//统计n以内的所有质数的数量leetcode204
///////////////////////
////////////最笨的方法会超时基本还是n√n的时间复杂度
class Solution {
public:
	int countPrimes(int n) {
		int count = 1;
		for (int i = 3; i < n; i++) {
			int flag = 0;
			if ((i & 1) == 0)continue;//偶数完，continue
			for (int j = 3; j <= sqrt(i); j=j+2) {//j增加到i的平方根即可
				if (i % j == 0) {
					flag = 1;
					break;
				} 
			}
			if (!flag)count++;
		}
		return count;
	}
};//优化暴力解法。。。。

//厄拉多塞筛法（时间最优）
int countPrimes(int n) {
	int count = 0;
	//初始默认所有数为质数
	vector<bool> signs(n, true);
	for (int i = 2; i < n; i++) {
		if (signs[i]) {
			count++;
			for (int j = i + i; j < n; j += i) {
				//排除不是质数的
				signs[j] = false;
			}
		}
	}
	return count;
}
/////////////////////////////////////////////////
int main() {
	Solution sol;
	vector<int> vec;
	int a;
	cin >> a; 
	cout<<sol.countPrimes(a);
	system("pause");
}
