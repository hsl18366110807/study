#include<iostream>
#include<vector>
using namespace std;
//main����֮ǰȫ����Ĺ��캯���Ѿ�����
//905,ż����ǰ�������ں�
//˼�����ÿ��ŵ�˼�룬ǰ�󽻻�
//ִ����ʱ:60 ms, ������ C++ �ύ�л�����35.22 %���û�
//�ڴ����� :9.7 MB, ������ C++ �ύ�л�����86.81 %���û�
class Solution {
public:
	vector<int> sortArrayByParity(vector<int>& A) {
		int start = 0, end = A.size() - 1;
		while (start<end)
		{
			while (start < end && (A[end] & 1) == 1)
				end--;
			while (start < end && (A[start] & 1) == 0)
				start++;
			swap(A[start], A[end]);
		}
		return A;
	}
};
/////////////////////////////////////////////////
int main() {
	Solution sol;
	vector<int> vec;
	int a;
	while (cin.peek() != '\n' && cin >> a)
	{
		vec.push_back(a);
	}
	vector<int>res;
	res = sol.sortArrayByParity(vec);
	for (int i = 0; i < res.size(); i++) {
		cout << res[i];
	}
	system("pause");
}
