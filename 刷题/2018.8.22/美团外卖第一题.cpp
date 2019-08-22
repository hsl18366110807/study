#include<iostream>
#include<vector>
#include<map>
using namespace std;
class Solution {
public:
	vector<int> res;
	map<char,int> mp;
	void getcount(string s) {
		for (int i = 0; i < s.length();) {
			if (!mp.empty()) mp.clear();
			int end = s.length() - 1;
			int start = i;
			for (int j = s.length() - 1; j >= i; j--) {
				if (s[j] == s[i]) {
					end = j;
					break;
				} 
				else {
					if (mp.find(s[j]) == mp.end()) mp[s[j]] = j;
				}
			}
			for (int k = start; k < end; k++) {
				if (mp.find(s[k]) != mp.end()&&end<mp[s[k]]) end = mp[s[k]];
			}
			res.push_back(end - start + 1);
			i = end + 1;
	 }
	}
};
int main() {
	string s;
	cin >> s;
	Solution sol;
	sol.getcount(s);
	for (int i = 0; i < sol.res.size(); i++){
		if (i != sol.res.size() - 1) cout << sol.res[i] << ' ';
		else cout << sol.res[i];
	}
}