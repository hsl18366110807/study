/////////////////////////////////////////////////
////��n������������д��bug��t2,t3,t5,�����α��һ����ÿ�ζ�����vec����С��û�г˹�������
///��������������д����bug��Ӧ������if�ֿ���������else if
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
/////////////////////////��6���ԣ�����2*3����3*2
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