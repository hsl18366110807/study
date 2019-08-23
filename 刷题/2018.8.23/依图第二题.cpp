//n个筛子，组合K,一共有多少种情况
#include<iostream>
#include<vector>
using namespace std;
class solution {
public:
	int count = 0;
	void getsum(vector<vector<int>> vec, int start, int left) {
		for (int i = 0; i < 6; i++) {
			int a = vec[start][i];
			int lef =left  - a;
			if (lef < 0)break;
			if (start == vec.size() - 1 && lef == 0)count++;
			if (start + 1 < vec.size()) getsum(vec, start + 1, lef);
		}
	}
};

int main() {
	int n, k;
	cin >> n >> k;
	vector<vector<int>> vec(n,vector<int>(6,0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 6; j++) {
			int a;
			cin >> a;
			vec[i][j] = a;
		}
	}
	solution sol;
 sol.getsum(vec,0,k);
 cout << sol.count;
}