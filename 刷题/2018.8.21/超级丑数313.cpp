#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
////执行用时 :92 ms, 在所有 C++ 提交中击败了53.28 %的用户
//内存消耗 :9.3 MB, 在所有 C++ 提交中击败了66.35 %的用户
class Solution {
public:
	int nthSuperUglyNumber(int n, vector<int>& primes) {
		int len = primes.size();
		vector<int> res(n, 0);
		vector<int> pram(len, 0);
		res[0] = 1;
		for (int i = 1; i < n; i++) {
			int min = INT_MAX;
			for (int j = 0; j < len; j++) {
				if (min > res[pram[j]] * primes[j]) min = res[pram[j]] * primes[j];
			}
			res[i] = min;
			for (int j = 0; j < len; j++) {
				if (min == res[pram[j]] * primes[j]) pram[j]++;
			}
		}
		return res[n - 1];
	}
};
int main() {
	Solution sol;
	vector<int> vec;
	int a;
	cin >> a;
	int b;
	while (cin.peek() != '\n' && cin >> b) {
		vec.push_back(b);
	}
	cout << sol.nthSuperUglyNumber(a,vec);
	system("pause");
}
