
#include <iostream>
#include <map>
using namespace std;

int getnum(map<int, int> mp, int a, int b) {
	//map里的数据已经按照start排好序了
	map<int, int>::iterator iter = mp.begin();
	int prestart = iter->first, preend = iter->second;
	if (iter->first != 0)return -1;
	int res = 1;
	for (map<int, int>::iterator iter = mp.begin(); iter != mp.end();) {
		if (iter->first == 0) {
			iter++;
			continue;
		}
		if (iter->first > preend)return -1;
		int mx = -1;
		map<int, int>::iterator maxit;
		map<int, int>::iterator it;
		for (it = iter; it != mp.end() && it->first >= prestart && it->first <= preend; it++) {
			if (it->second > mx) {
				mx = it->second;
				maxit = it;
			}
		}
		prestart = maxit->first;
		preend = maxit->second;
		res++;
		if (preend > b) return res;
		iter = it;
	}
	if (preend < b)return -1;
	return res;
}
int main()
{
	int a, b;
	map<int, int> mp;
	cin >> a >> b;
	for (int i = 0; i < a ; i++) {
		int start, end;
		cin >> start >> end;
		mp[start] = end;
	}
	cout << getnum(mp, a, b);
}