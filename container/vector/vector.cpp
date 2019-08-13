#include<iostream>
#include"vectorr.h"
#include<vector>
using namespace std;
int main() {
	vectorr<int> vec(3, 0);
	cout << "手动实现vector，类vectorr" << endl;
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << endl;
	}
	cout << "操作以下" << endl;
	cout << "初始化3个0" << endl;
	cout << "size:" << vec.capacity();
	cout << "capacity:" << vec.capacity();
	cout << "empty:" << vec.empty();
	cout << "   " << endl;
	cout << "push_back 1,2,3,4" << endl;
	cout << "vec.insert(vec.begin(), 0);" << endl;
	cout << "头部插入0,5,6" << endl;

	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.erase(vec.begin());
	vec.insert(vec.begin(), 0);
	vec.insert(vec.begin(), 5);
	vec.insert(vec.begin(), 6);
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << endl;
	}
	cout << "back:" << "  " << vec.back() << endl;
	cout << "front:" << "  " << vec.front() << endl;
	cout << "size:" << vec.size();
	cout << "capacity:" << vec.capacity();
	cout << "empty:" << vec.empty();
	system("pause");
}
