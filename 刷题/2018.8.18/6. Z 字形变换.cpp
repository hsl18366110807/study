执行用时 :68 ms, 在所有 C++ 提交中击败了15.26%的用户
内存消耗 :21.8 MB, 在所有 C++ 提交中击败了14.24%的用户
#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
	string convert(string s, int numRows) {
		if (s == "" || numRows == 1)return s;
		int rows = numRows;
		int cols;
		int len = s.length();
		int shang = len / (2 * rows - 2);
		if (len % (2 * rows - 2) == 0) cols = shang*(rows-1);
		else if (len % (2 * rows - 2) > rows) cols = shang * (rows - 1) + len % (2 * rows - 2) - rows+1;
		else cols = shang * (rows - 1) + 1;
		vector<vector<char>> vec(rows, vector<char>(cols, ' '));
		int col = 0, row = 0, i = 0, sum = col + row;
		while (i <= len - 1) {
			if (row == 0) {
				for (;row < rows&& i <= len - 1; row++) {
				
					vec[row][col] = s[i];
					i++;
				}
				row--;
				sum = col + row;
			}
			else if (row +1== rows) {
				row--;
				while (row > 0&& i <= len - 1) {
					vec[row][sum - row] = s[i];
					i++;
					row--;
				}
				col = sum;
			}
		}
		string res;
		for (int i = 0; i < vec.size(); i++) {
			for (int j = 0; j < vec[0].size(); j++) {
				if (vec[i][j] == ' ')continue;
				res += vec[i][j];
			}
		}
		return res;
	}
};
int main() {
	Solution sol;
	string s;
	int n;
	cin >> s >> n;
	cout << sol.convert(s, n);
	system("pause");
}