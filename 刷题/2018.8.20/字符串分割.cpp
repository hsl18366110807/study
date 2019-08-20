#include<iostream>
#include<vector>
#include<string>
using namespace std;
/////////////////////
//分割字符串
typedef vector<string> stringlist;
///根据字母来分割字符串
stringlist splitstr(const string& str, char ch) {
	string substr;
	stringlist li;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == ch) {
			li.push_back(substr);
			substr.clear();
		}
		else {
			substr.push_back(str[i]);
		}
	}
	if (!substr.empty()) li.push_back(substr);
	return li;
}
///根据字符串来分割
stringlist splitstr(const std::string& str, const std::string& pattern)
{
	stringlist  li;
	std::string subStr;
	std::string tPattern;
	size_t      patternLen = pattern.length();

	for (size_t i = 0; i < str.length(); i++)
	{
		if (pattern[0] == str[i])
		{
			tPattern = str.substr(i, patternLen);
			if (tPattern == pattern)
			{
				i += patternLen - 1;
				if (!subStr.empty())
				{
					li.push_back(subStr);
					subStr.clear();
				}
			}
			else
			{
				subStr.push_back(str[i]);
			}
		}
		else
		{
			subStr.push_back(str[i]);
		}
	}

	if (!subStr.empty())
	{
		li.push_back(subStr);
	}

	return li;
}
int main() {
	string s = "aaab aaa aa";
	string ss=s.substr(0, 5);
	stringlist l;
	l = splitstr(s, ' ');
}