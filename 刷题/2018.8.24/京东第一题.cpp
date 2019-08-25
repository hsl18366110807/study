#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//京东第一题
//ac了27%，气炸了
//现在ac了，这道题自己的边界做的不好
class Solution {
public:
	int getcount(vector<int> vec){
		vector<vector<int>> res(vec.size()+1,vector<int>(2,-1));
		int count = 0;
		res[0][0] = -1;
		res[0][1] = -1;
		int j = 1;
		for (int i = 0; i < vec.size(); i++) {
			if (vec[i] >= res[j - 1][1]) {
				if (i == 0) {
					res[j][1] = vec[i];
					res[j][0] = vec[i];
				}
				else {
					res[j][1] = vec[i];
					res[j][0] = res[j - 1][1];
				}	
				j++;
			}
			else {
				if (vec[i] < res[j-1][0]) res[j-1][0] = vec[i];
				for (int k = j-1; k > 0; k--) {
					if (res[k][0] < res[k - 1][1]) {
						res[k - 1][1] = res[k][1];
						res[k - 1][0] = min(res[k][0], res[k - 1][0]);
						res[k][0] = -1;
						res[k][1] = -1;
						j--;
					}
				}
			}
		}
		for (int i = 1; i < res.size(); i++) {
			if (res[i][1] == -1)break;
			else count++;
		}
		return count;
	}
};

int main() {
	int n;
	cin >> n;
	vector<int > vec;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		vec.push_back(a);
	}
	Solution sol;
	cout<<sol.getcount(vec);
}