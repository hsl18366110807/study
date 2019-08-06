![image](https://github.com/hsl18366110807/study-Git/blob/master/%E5%AE%9E%E7%8E%B0%E5%AE%B9%E5%99%A8/vector/photo.jpg)
#include<iostream>
#include"rand.h"
#include"vectorr.h"
using namespace std;
int main() {
	vectorr<int> vec(3,0);
	cout << "手动实现vector，类vectorr" << endl;
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
