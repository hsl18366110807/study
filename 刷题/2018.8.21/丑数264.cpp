/////////////////////////////////////////////////
////第n个丑数，这样写有bug，t2,t3,t5,就像游标尺一样，每次都乘以vec中最小的没有乘过的数，
///但是像下面这样写会有bug，应该三个if分开，而不是else if
class Solution {
public:
	int nthUglyNumber(int n) {
		vector<int>vec(n, 0);
		vec[0] = 1;
		int t2 = 0, t3 = 0, t5 = 0;
		for (int i = 1; i < n; i++) {
			vec[i] = min(vec[t2] * 2, min(vec[t3] * 3, vec[t5] * 5));
			if (vec[i] == vec[t2] * 2) t2++;
			else if (vec[i] == vec[t3] * 3) t3++;
			else t5++;
		}
		return vec[n - 1];
	}
};

////////////////////////////////////////////////
/////////////////////////就6而言，即是2*3又是3*2
////////////////////////
class Solution {
public:
	int nthUglyNumber(int n) {
		vector<int>vec(n, 0);
		vec[0] = 1;
		int t2 = 0, t3 = 0, t5 = 0;
		for (int i = 1; i < n; i++) {
			vec[i] = min(vec[t2] * 2, min(vec[t3] * 3, vec[t5] * 5));
			if (vec[i] == vec[t2] * 2) t2++;
		    if (vec[i] == vec[t3] * 3) t3++;
			if (vec[i] == vec[t5] * 3) t5++;
		}
		return vec[n - 1];
	}
};