#include<iostream>
#include"rand.h"
#include"vectorr.h"
using namespace std;
int main() {
	vectorr<int> vec(3,0);
	cout << "�ֶ�ʵ��vector����vectorr" << endl;
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << endl;
	}
	cout << "size:" << vec.capacity();
	cout<<"capacity:"<<vec.capacity();
	cout << "empty:" << vec.empty();
	cout << "   " << endl;
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
